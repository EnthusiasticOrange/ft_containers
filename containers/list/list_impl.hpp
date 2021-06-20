#ifndef FT_CONTAINERS_LIST_IMPL_HPP
#define FT_CONTAINERS_LIST_IMPL_HPP

#include "other/utility.hpp"
#include "other/functional.hpp"
#include "containers/list.hpp"

namespace ft
{
    template<class T, class Allocator>
    list<T, Allocator>::list(const allocator_type& alloc)
        : base_type(alloc)
    {
    }

    template<class T, class Allocator>
    list<T, Allocator>::list(list::size_type n, const value_type& val, const allocator_type& alloc)
        : base_type(alloc)
    {
        _insert(&m_base, n, val);
    }

    template<class T, class Allocator>
    template<class InputIterator>
    list<T, Allocator>::list(InputIterator first, InputIterator last, const allocator_type& alloc,
            typename enable_if<!is_arithmetic<InputIterator>::value>::type*)
        : base_type(alloc)
    {
        _insert_iter(&m_base, first, last);
    }

    template<class T, class Allocator>
    list<T, Allocator>::list(const list& x)
        : base_type(x.m_alloc)
    {
        _insert_iter(&m_base, x.begin(), x.end());
    }

    template<class T, class Allocator>
    list<T, Allocator>::~list()
    {
    }

    template<class T, class Allocator>
    list<T, Allocator>& list<T, Allocator>::operator=(const list& x)
    {
        if (this != &x)
            assign(x.begin(), x.end());
        return *this;
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::begin()
    {
        return iterator(static_cast<node_pointer>(m_base.m_next));
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::const_iterator list<T, Allocator>::begin() const
    {
        return const_iterator(static_cast<node_pointer>(const_cast<node_base_pointer>(m_base.m_next)));
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::end()
    {
        return iterator(static_cast<node_pointer>(&m_base));
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::const_iterator list<T, Allocator>::end() const
    {
        return const_iterator(static_cast<node_pointer>(const_cast<node_base_pointer>(&m_base)));
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::reverse_iterator list<T, Allocator>::rbegin()
    {
        return reverse_iterator(end());
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::list::const_reverse_iterator list<T, Allocator>::rbegin() const
    {
        return const_reverse_iterator(end());
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::reverse_iterator list<T, Allocator>::rend()
    {
        return reverse_iterator(begin());
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::list::const_reverse_iterator list<T, Allocator>::rend() const
    {
        return const_reverse_iterator(begin());
    }

    template<class T, class Allocator>
    bool list<T, Allocator>::empty() const
    {
        return m_size == 0;
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::size_type list<T, Allocator>::size() const
    {
        return m_size;
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::size_type list<T, Allocator>::max_size() const
    {
        return m_node_alloc.max_size();
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::reference list<T, Allocator>::front()
    {
        return static_cast<node_pointer>(m_base.m_next)->m_value;
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::const_reference list<T, Allocator>::front() const
    {
        return static_cast<node_pointer>(m_base.m_next)->m_value;
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::reference list<T, Allocator>::back()
    {
        return static_cast<node_pointer>(m_base.m_prev)->m_value;
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::const_reference list<T, Allocator>::back() const
    {
        return static_cast<node_pointer>(m_base.m_prev)->m_value;
    }

    template<class T, class Allocator>
    template<class InputIterator>
    void list<T, Allocator>::assign(InputIterator first, InputIterator last,
            typename enable_if<!is_arithmetic<InputIterator>::value>::type*)
    {
        node_pointer node = static_cast<node_pointer>(m_base.m_next);
        for(; (node != &m_base) && (first != last); ++first)
        {
            node->m_value = *first;
            node          = static_cast<node_pointer>(node->m_next);
        }

        if(first != last)
            _insert_iter(&m_base, first, last);
        else
            erase(iterator(node), end());
    }

    template<class T, class Allocator>
    void list<T, Allocator>::assign(size_type n, const value_type& val)
    {
        node_pointer node = static_cast<node_pointer>(m_base.m_next);
        for(; (node != &m_base) && (n > 0); --n)
        {
            node->m_value = val;
            node          = static_cast<node_pointer>(node->m_next);
        }

        if(n)
            _insert(&m_base, n, val);
        else
            erase(iterator(node), end());
    }

    template<class T, class Allocator>
    void list<T, Allocator>::push_front(const value_type& val)
    {
        _insert_value(m_base.m_next, val);
    }

    template<class T, class Allocator>
    void list<T, Allocator>::pop_front()
    {
        _erase(static_cast<node_pointer>(m_base.m_next));
    }

    template<class T, class Allocator>
    void list<T, Allocator>::push_back(const value_type& val)
    {
        _insert_value(&m_base, val);
    }

    template<class T, class Allocator>
    void list<T, Allocator>::pop_back()
    {
        _erase(static_cast<node_pointer>(m_base.m_prev));
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::insert(iterator position,
            const value_type& val)
    {
        iterator prev(position.m_node);
        --prev;
        _insert_value(position.m_node, val);
        return ++prev;
    }

    template<class T, class Allocator>
    void list<T, Allocator>::insert(iterator position, size_type n, const value_type& val)
    {
        iterator prev(position.m_node);
        --prev;
        _insert(position.m_node, n, val);
    }

    template<class T, class Allocator>
    template<class InputIterator>
    void list<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last,
                                    typename enable_if<!is_arithmetic<InputIterator>::value>::type*)
    {
        iterator prev(position.m_node);
        --prev;
        _insert_iter(position.m_node, first, last);
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::erase(iterator position)
    {
        ++position;
        _erase(static_cast<node_pointer>(position.m_node->m_prev));
        return position;
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::erase(iterator first, iterator last)
    {
        while(first != last)
            first = erase(first);
        return last;
    }

    template<class T, class Allocator>
    void list<T, Allocator>::swap(list& x)
    {
        ft::ft_swap(m_alloc, x.m_alloc);
        ft::ft_swap(m_node_alloc, x.m_node_alloc);
        ft::ft_swap(m_size, x.m_size);
        ft::ft_swap(m_base, x.m_base);

        if(m_base.m_next == &x.m_base)
        {
            m_base.m_next = &m_base;
            m_base.m_prev = &m_base;
        }
        else
        {
            m_base.m_next->m_prev = &m_base;
            m_base.m_prev->m_next = &m_base;
        }
        if(x.m_base.m_next == &m_base)
        {
            x.m_base.m_next = &x.m_base;
            x.m_base.m_prev = &x.m_base;
        }
        else
        {
            x.m_base.m_next->m_prev = &x.m_base;
            x.m_base.m_prev->m_next = &x.m_base;
        }
    }

    template<class T, class Allocator>
    void list<T, Allocator>::resize(list::size_type n, value_type val)
    {
        iterator it = begin();
        size_type i = 0;

        while((it != end()) && (i < n))
        {
            ++it;
            ++i;
        }
        if(i == n)
            erase(it, end());
        else
            insert(static_cast<node_pointer>(&m_base), n - i, val);
    }

    template<class T, class Allocator>
    void list<T, Allocator>::clear()
    {
        _clear();
        _init();
        m_size = 0;
    }

    template<class T, class Allocator>
    void list<T, Allocator>::splice(iterator position, list& x)
    {
        if (m_alloc != x.m_alloc)
            return;

        position.m_node->splice(x.m_base.m_next, &x.m_base);
        m_size += x.m_size;
        x.m_size = 0;
    }

    template<class T, class Allocator>
    void list<T, Allocator>::splice(iterator position, list& x, iterator i)
    {
        if (m_alloc != x.m_alloc)
            return;

        iterator i2(i);
        ++i2;

        if (position != i && position != i2)
        {
            position.m_node->splice(i.m_node, i2.m_node);
            ++m_size;
            --x.m_size;
        }
    }

    template<class T, class Allocator>
    void list<T, Allocator>::splice(iterator position, list& x, iterator first, iterator last)
    {
        if (m_alloc != x.m_alloc)
            return;

        const size_type d = ft::distance(first, last);
        if (d)
        {
            position.m_node->splice(first.m_node, last.m_node);
            m_size += d;
            x.m_size -= d;
        }
    }

    template<class T, class Allocator>
    void list<T, Allocator>::remove(const value_type& val)
    {
        iterator it = begin();
        while (it != end())
        {
            if (*it++ == val)
                _erase(static_cast<node_pointer>(it.m_node->m_prev));
        }
    }

    template<class T, class Allocator>
    template<class Predicate>
    void list<T, Allocator>::remove_if(Predicate pred)
    {
        iterator it = begin();
        while (it != end())
        {
            if (pred(*it++))
                _erase(static_cast<node_pointer>(it.m_node->m_prev));
        }
    }

    template<class T, class Allocator>
    void list<T, Allocator>::unique()
    {
        unique(ft::equal_to<value_type>());
    }

    template<class T, class Allocator>
    template<class BinaryPredicate>
    void list<T, Allocator>::unique(BinaryPredicate binary_pred)
    {
        iterator cur = begin();
        if (cur != end())
        {
            iterator next = cur;
            while (++next != end())
            {
                if (binary_pred(*cur, *next))
                    _erase(next.m_node);
                else
                    cur = next;
                next = cur;
            }
        }
    }

    template<class T, class Allocator>
    void list<T, Allocator>::merge(list& x)
    {
        merge(x, ft::less<value_type>());
    }

    template<class T, class Allocator>
    template<class Compare>
    void list<T, Allocator>::merge(list& x, Compare comp)
    {
        if(&x == this)
            return;

        iterator    cur = begin();
        iterator    cur_x = x.begin();
        while((cur != end()) && (cur_x != x.end()))
        {
            if(comp(*cur_x, *cur))
            {
                iterator next_x = cur_x;

                splice(cur, x, cur_x, ++next_x);
                cur_x = next_x;
            }
            else
                ++cur;
        }
        if(cur_x != x.end())
            splice(end(), x, cur_x, x.end());
    }

    template<class T, class Allocator>
    void list<T, Allocator>::sort()
    {
        sort(ft::less<value_type>());
    }

    template<class T, class Allocator>
    template<class Compare>
    void list<T, Allocator>::sort(Compare comp)
    {
        _merge_sort(begin(), end(), m_size, comp);
    }

    template<class T, class Allocator>
    void list<T, Allocator>::reverse()
    {
        node_base_pointer node = &m_base;
        do
        {
            node_base_pointer temp = node->m_next;
            node->m_next = node->m_prev;
            node->m_prev = temp;
            node         = node->m_prev;
        }
        while(node != &m_base);
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::allocator_type list<T, Allocator>::get_allocator() const
    {
        return m_alloc;
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::node_pointer list<T, Allocator>::_allocate_node()
    {
        node_pointer p = m_node_alloc.allocate(1);
        return p;
    }

    template<class T, class Allocator>
    typename list<T, Allocator>::node_pointer list<T, Allocator>::_create_node(const value_type& val)
    {
        node_pointer p = _allocate_node();
        node_guard_type guard(m_node_alloc, p);

        m_alloc.construct(&p->m_value, val);

        guard.release();
        return p;
    }

    template<class T, class Allocator>
    template<class InputIterator>
    void list<T, Allocator>::_insert_iter(node_base_pointer p, InputIterator first, InputIterator last)
    {
        for(; first != last; ++first)
            _insert_value(p, *first);
    }

    template<class T, class Allocator>
    void list<T, Allocator>::_insert(node_base_pointer p, size_type n, const value_type& val)
    {
        while (n-- > 0)
            _insert_value(p, val);
    }

    template<class T, class Allocator>
    void list<T, Allocator>::_insert_value(node_base_pointer p, const value_type& val)
    {
        node_pointer node = _create_node(val);
        node->insert(p);
        ++m_size;
    }

    template<class T, class Allocator>
    void list<T, Allocator>::_erase(node_pointer node)
    {
        node->remove();
        m_alloc.destroy(&node->m_value);
        m_node_alloc.deallocate(node, 1);
        --m_size;
    }

    template<class T, class Allocator>
    template<class Compare>
    typename list<T, Allocator>::iterator list<T, Allocator>::_merge_sort(iterator first, iterator last,
            size_type size, Compare& comp)
    {
        if (size < 2)
            return first;

        size_type half = size / 2;
        iterator ret;
        iterator mid = first;
        for (size_type i = 0; i < half; i++)
            mid++;
        iterator i1 = _merge_sort(first, mid, half, comp);
        iterator i2 = _merge_sort(mid, last, size - half, comp);

        if(comp(*i2, *i1))
        {
            iterator i = i2;
            ++i;
            while((i != last) && comp(*i, *i1))
                ++i;
            node_base_pointer cut_first = i2.m_node;
            node_base_pointer cut_last  = i.m_node->m_prev;
            ret = i2;
            i2 = i;
            mid = i2;
            cut_last->m_next->m_prev = cut_first->m_prev;
            cut_first->m_prev->m_next = cut_last->m_next;

            node_base_pointer ins = i1.m_node;
            ins->m_prev->m_next = cut_first;
            cut_first->m_prev   = ins->m_prev;
            ins->m_prev         = cut_last;
            cut_last->m_next    = ins;
        }
        else
        {
            ret = i1;
            mid = i2;
        }

        for(++i1; (i1 != mid) && (i2 != last); ++i1)
        {
            if(comp(*i2, *i1))
            {
                iterator i = i2;
                ++i;
                while((i != last) && comp(*i, *i1))
                    ++i;

                node_base_pointer cut_first = i2.m_node;
                node_base_pointer cut_last  = i.m_node->m_prev;
                if(mid == i2)
                    mid = i;
                i2 = i;

                cut_last->m_next->m_prev = cut_first->m_prev;
                cut_first->m_prev->m_next = cut_last->m_next;

                node_base_pointer ins = i1.m_node;
                ins->m_prev->m_next = cut_first;
                cut_first->m_prev   = ins->m_prev;
                ins->m_prev         = cut_last;
                cut_last->m_next    = ins;
            }
        }

        return ret;
    }

    template<class T, class Alloc>
    bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template<class T, class Alloc>
    bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }

    template<class T, class Alloc>
    bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<class T, class Alloc>
    bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }

    template<class T, class Alloc>
    bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return rhs < lhs;
    }

    template<class T, class Alloc>
    bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }

    template<class T, class Alloc>
    void swap(list<T,Alloc>& x, list<T,Alloc>& y)
    {
        x.swap(y);
    }
}

#endif //FT_CONTAINERS_LIST_IMPL_HPP
