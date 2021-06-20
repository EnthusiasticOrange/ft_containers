#ifndef FT_CONTAINERS_VECTOR_IMPL_HPP
#define FT_CONTAINERS_VECTOR_IMPL_HPP

#include <containers/vector.hpp>

namespace ft
{
    template<class T, class Allocator>
    vector<T, Allocator>::vector(const allocator_type& alloc)
        : base_type(alloc)
    {
    }

    template<class T, class Allocator>
    vector<T, Allocator>::vector(size_type n, const value_type& val, const allocator_type& alloc)
        : base_type(alloc)
    {
        if (n)
        {
            _reserve_empty(n);
            _construct_at_end(n, val);
        }
    }

    template<class T, class Allocator>
    template<class InputIterator>
    vector<T, Allocator>::vector(InputIterator first, InputIterator last, const allocator_type& alloc,
            typename enable_if<!is_arithmetic<InputIterator>::value>::type*)
        : base_type(alloc)
    {
        typedef typename ft::iterator_traits<InputIterator>::iterator_category it_cat_t;
        _assign_from_iter(first, last,
                typename ft::conditional<
                                ft::is_same<it_cat_t, ft::forward_iterator_tag>::value
                                || ft::is_same<it_cat_t, ft::bidirectional_iterator_tag>::value
                                || ft::is_same<it_cat_t, ft::random_access_iterator_tag>::value,
                                ft::true_type, ft::false_type
                                >::type());
    }

    template<class T, class Allocator>
    vector<T, Allocator>::vector(const vector& x)
        : base_type(x.m_alloc)
    {
        _reserve_empty(x.size());
        _construct_at_end(x.begin(), x.end());
    }

    template<class T, class Allocator>
    vector<T, Allocator>::~vector()
    {
        _destruct_at_end(m_begin);
    }

    template<class T, class Allocator>
    vector<T, Allocator>& vector<T, Allocator>::operator=(const vector& x)
    {
        if (this != &x)
        {
            m_alloc = x.m_alloc;
            assign(x.begin(), x.end());
        }
        return *this;
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::begin()
    {
        return m_begin;
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const
    {
        return m_begin;
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::end()
    {
        return m_end;
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const
    {
        return m_end;
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin()
    {
        return reverse_iterator(m_end);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::vector::const_reverse_iterator vector<T, Allocator>::rbegin() const
    {
        return const_reverse_iterator(m_end);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend()
    {
        return reverse_iterator(m_begin);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::vector::const_reverse_iterator vector<T, Allocator>::rend() const
    {
        return const_reverse_iterator(m_begin);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const
    {
        return static_cast<size_type>(m_end - m_begin);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const
    {
        return m_alloc.max_size();
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::resize(size_type n, value_type val)
    {
        const size_type s = size();
        if (s < n)
            _append(n, val);
        else if (s > n)
            _destruct_at_end(m_begin + n);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const
    {
        return static_cast<size_type>(m_end_cap - m_begin);
    }

    template<class T, class Allocator>
    bool vector<T, Allocator>::empty() const
    {
        return m_begin == m_end;
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::reserve(size_type n)
    {
        if(n > capacity())
        {
            this_type temp(m_alloc);
            temp._reserve_empty(n);
            temp._construct_at_end(begin(), end());
            swap(temp);
        }
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::operator[](size_type n)
    {
        return *(m_begin + n);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[](size_type n) const
    {
        return *(m_begin + n);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::at(size_type n)
    {
        if (n >= size())
            throw std::out_of_range("ft::vector::at: out of range");
        return *(m_begin + n);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(size_type n) const
    {
        if (n >= size())
            throw std::out_of_range("ft::vector::at: out of range");
        return *(m_begin + n);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::front()
    {
        return *m_begin;
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const
    {
        return *m_begin;
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::back()
    {
        return *(m_end - 1);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const
    {
        return *(m_end - 1);
    }

    template<class T, class Allocator>
    template<class InputIterator>
    void vector<T, Allocator>::assign(InputIterator first, InputIterator last,
            typename enable_if<!is_arithmetic<InputIterator>::value>::type*)
    {
        typedef typename ft::iterator_traits<InputIterator>::iterator_category it_cat_t;
        _assign_from_iter(first, last,
                typename ft::conditional<
                        ft::is_same<it_cat_t, ft::forward_iterator_tag>::value
                                || ft::is_same<it_cat_t, ft::bidirectional_iterator_tag>::value
                                || ft::is_same<it_cat_t, ft::random_access_iterator_tag>::value,
                        ft::true_type, ft::false_type
                >::type());
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::assign(size_type n, const value_type& val)
    {
        if (n <= capacity())
        {
            size_type s = size();
            pointer p = m_begin;
            for (size_type i = ft::min(n, s); i > 0; ++p, --i)
                *p = val;
            if (n > s)
                _construct_at_end(n, val);
            else
                _destruct_at_end(m_begin + n);
        }
        else
        {
            this_type temp(m_alloc);
            temp._reserve_empty(n);
            temp._construct_at_end(n, val);
            swap(temp);
        }
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::push_back(const value_type& val)
    {
        if (m_end == m_end_cap)
        {
            this_type temp(m_alloc);
            temp._reserve_empty(_get_new_capacity(size() + 1));
            temp._construct_at_end(begin(), end());
            temp._construct_at_end(1, val);
            swap(temp);
        }
        else
        {
            m_alloc.construct(m_end, val);
            ++m_end;
        }
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::pop_back()
    {
        --m_end;
        m_alloc.destroy(m_end);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(iterator position, const value_type& val)
    {
        const ptrdiff_t p = position.m_p - m_begin;

        if(m_end == m_end_cap)
            _insert_realloc(position, 1, val);
        else if (position.m_p != m_end)
            _insert_value(position, 1, val);
        else
        {
            m_alloc.construct(m_end, val);
            ++m_end;
        }

        return m_begin + p;
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::insert(iterator position, size_type n, const value_type& val)
    {
        if (n > 0)
        {
            if(n > static_cast<size_type>(m_end_cap - m_end))
                _insert_realloc(position, n, val);
            else if (position.m_p != m_end)
                _insert_value(position, n, val);
            else
            {
                _construct_at_end(n, val);
            }
        }
    }

    template<class T, class Allocator>
    template<class InputIterator>
    void vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last,
                                      typename enable_if<!is_arithmetic<InputIterator>::value>::type*)
    {
        typedef typename ft::iterator_traits<InputIterator>::iterator_category it_cat_t;
        _insert_from_iter(position, first, last,
                typename ft::conditional<
                        ft::is_same<it_cat_t, ft::forward_iterator_tag>::value
                                || ft::is_same<it_cat_t, ft::bidirectional_iterator_tag>::value
                                || ft::is_same<it_cat_t, ft::random_access_iterator_tag>::value,
                        ft::true_type, ft::false_type
                >::type());
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator position)
    {
        return erase(position, position + 1);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator first, iterator last)
    {
        if (first != last)
        {
            size_t n = ft::distance(first, last);
            iterator end_copy = end() - n;
            pointer old_end = m_end;
            m_end = first.m_p;

            iterator it = first;
            guard_type guard(first.m_p, old_end, m_alloc);
            while (it != end_copy)
            {
                *it++ = *last++;
                guard.incBegin();
            }
            for (size_t i = 0; i < n; ++i)
                m_alloc.destroy(it.m_p++);
            m_end = old_end - n;
            guard.release();
        }

        return first;
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::swap(vector& x)
    {
        ft::ft_swap(m_begin, x.m_begin);
        ft::ft_swap(m_end, x.m_end);
        ft::ft_swap(m_end_cap, x.m_end_cap);
        ft::ft_swap(m_alloc, x.m_alloc);
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::clear()
    {
        _destruct_at_end(m_begin);
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const
    {
        return m_alloc;
    }

    template<class T, class Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::_get_new_capacity(size_type new_size)
    {
        const size_type ms = max_size();
        if (new_size > ms)
            throw std::length_error("ft::vector capacity over max_size");
        const size_type cap = capacity();
        if (cap >= ms / 2)
            return ms;
        return ft::max<size_type>(2 * cap, new_size);
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::_reserve_empty(size_t n)
    {
        m_begin = m_alloc.allocate(n);
        m_end = m_begin;
        m_end_cap = m_begin + n;
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::_construct_at_end(size_type n, const_reference val)
    {
        guard_type guard(m_end, m_end, m_alloc);

        while (n-- > 0)
        {
            m_alloc.construct(m_end, val);
            m_end = guard.moveEnd();
        }
        guard.release();
    }

    template<class T, class Allocator>
    template<class InputIterator>
    void vector<T, Allocator>::_construct_at_end(InputIterator first, InputIterator last,
            typename enable_if<!is_arithmetic<InputIterator>::value>::type*)
    {
        guard_type guard(m_end, m_end, m_alloc);
        pointer new_end = m_end;
        for (; first != last; ++first)
        {
            m_alloc.construct(new_end, *first);
            new_end = guard.moveEnd();
        }
        guard.release();
        m_end = new_end;
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::_destruct_at_end(pointer new_end)
    {
        while (m_end != new_end)
            m_alloc.destroy(--m_end);
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::_append(size_t n, const_reference val)
    {
        if(capacity() < n)
        {
            this_type temp(m_alloc);
            temp._reserve_empty(n);
            temp._construct_at_end(begin(), end());
            temp._construct_at_end(n - size(), val);
            swap(temp);
        }
        else
            _construct_at_end(n - size(), val);
    }

    template<class T, class Allocator>
    template<class InputIterator>
    void vector<T, Allocator>::_assign_from_iter(InputIterator first, InputIterator last, ft::false_type)
    {
        clear();
        for (; first != last; ++first)
            push_back(*first);
    }

    template<class T, class Allocator>
    template<class ForwardIterator>
    void vector<T, Allocator>::_assign_from_iter(ForwardIterator first, ForwardIterator last, ft::true_type)
    {
        const size_type n = ft::distance(first, last);
        if (n <= capacity())
        {
            ForwardIterator mid = last;
            bool is_growing = false;
            const size_type s = size();
            if (n > s)
            {
                is_growing = true;
                mid = first;
                ft::advance(mid, s);
            }
            pointer p = m_begin;
            for (; first != mid; ++first, (void) ++p)
                *p = *first;
            if (is_growing)
                _construct_at_end(mid, last);
            else
                _destruct_at_end(p);
        }
        else
        {
            this_type temp(m_alloc);
            temp._reserve_empty(n);
            temp._construct_at_end(begin(), end());
            temp._construct_at_end(first, last);
            swap(temp);
        }
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::_insert_value(iterator position, size_t n, const_reference val)
    {
        pointer new_end = m_end;

        guard_type guard(m_end, m_end, m_alloc);

        for (size_t i = 0; i < n; ++i)
        {
            m_alloc.construct(new_end, *(new_end - n + i));
            new_end = guard.moveEnd();
        }

        while (m_end - 1 != position.m_p)
        {
            *(m_end - 1) = *(m_end - 2);
            m_end = guard.decBegin();
        }

        while (n-- > 0)
        {
            *position.m_p = val;
            ++position;
        }
        m_end = new_end;

        guard.release();
    }

    template<class T, class Allocator>
    void vector<T, Allocator>::_insert_realloc(iterator position, size_t n, const_reference val)
    {
        size_t new_cap = _get_new_capacity(size() + n);

        this_type temp(m_alloc);
        temp._reserve_empty(new_cap);
        temp._construct_at_end(begin(), position);
        while (n-- > 0)
            temp.push_back(val);
        temp._construct_at_end(position, end());
        swap(temp);
    }

    template<class T, class Allocator>
    template<class InputIterator>
    void vector<T, Allocator>::_insert_from_iter(iterator position,
            InputIterator first, InputIterator last, ft::false_type)
    {
        for (; first != last; ++first, ++position)
            position = insert(position, *first);
    }

    template<class T, class Allocator>
    template<class ForwardIterator>
    void vector<T, Allocator>::_insert_from_iter(iterator position,
            ForwardIterator first, ForwardIterator last, ft::true_type)
    {
        const difference_type n = ft::distance(first, last);
        if (n > 0)
        {
            if(n > m_end - m_end_cap)
                _insert_realloc_from_iter(position, n, first, last);
            else if (position.m_p != m_end)
                _insert_value_from_iter(position, n, first, last);
            else
                _construct_at_end(first, last);
        }

    }
    template<class T, class Allocator>
    template<class ForwardIterator>
    void vector<T, Allocator>::_insert_realloc_from_iter(iterator position, size_t n,
            ForwardIterator first, ForwardIterator last)
    {
        size_t new_cap = _get_new_capacity(size() + n);

        this_type temp(m_alloc);
        temp._reserve_empty(new_cap);
        temp._construct_at_end(begin(), position);
        temp._construct_at_end(first, last);
        temp._construct_at_end(position, end());
        swap(temp);
    }

    template<class T, class Allocator>
    template<class ForwardIterator>
    void vector<T, Allocator>::_insert_value_from_iter(iterator position, size_t n,
            ForwardIterator first, ForwardIterator last)
    {
        pointer new_end = m_end;

        guard_type guard(m_end, m_end, m_alloc);

        for (size_t i = 0; i < n; ++i)
        {
            m_alloc.construct(new_end, *(new_end - 1));
            new_end = guard.moveEnd();
        }

        while (m_end != position.m_p)
        {
            *(m_end + n - 1) = *(m_end - 1);
            m_end = guard.decBegin();
        }

        while (first != last)
        {
            m_alloc.destroy(position.m_p);
            m_alloc.construct(position.m_p, *first);
            ++position;
            ++first;
        }
        m_end = new_end;

        guard.release();
    }

    template<class T, class Alloc>
    bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template<class T, class Alloc>
    bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }

    template<class T, class Alloc>
    bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }

    template<class T, class Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return rhs < lhs;
    }

    template<class T, class Alloc>
    bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }

    template<class T, class Alloc>
    void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}

#endif //FT_CONTAINERS_VECTOR_IMPL_HPP
