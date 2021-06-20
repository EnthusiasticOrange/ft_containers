#ifndef FT_CONTAINERS_MAP_IMPL_HPP
#define FT_CONTAINERS_MAP_IMPL_HPP

#include <containers/map.hpp>

namespace ft
{
    template<class K, class T, class C, class A>
    map<K, T, C, A>::map(const key_compare& comp, const allocator_type& alloc)
        : m_tree(value_compare(comp), alloc)
    {
    }

    template<class K, class T, class C, class A>
    template<class InputIterator>
    map<K, T, C, A>::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
        : m_tree(value_compare(comp), alloc)
    {
        insert(first, last);
    }

    template<class K, class T, class C, class A>
    map<K, T, C, A>::map(const map& x)
        : m_tree(x.m_tree)
    {
    }

    template<class K, class T, class C, class A>
    map<K, T, C, A>::~map()
    {
    }

    template<class K, class T, class C, class A>
    map<K, T, C, A>& map<K, T, C, A>::operator=(const map& x)
    {
        if (this != &x)
        {
            m_tree.clear();
            insert(x.begin(), x.end());
        }
        return *this;
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::iterator map<K, T, C, A>::begin()
    {
        return m_tree.begin();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::const_iterator map<K, T, C, A>::begin() const
    {
        return m_tree.begin();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::iterator map<K, T, C, A>::end()
    {
        return m_tree.end();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::const_iterator map<K, T, C, A>::end() const
    {
        return m_tree.end();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::reverse_iterator map<K, T, C, A>::rbegin()
    {
        return m_tree.rbegin();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::const_reverse_iterator map<K, T, C, A>::rbegin() const
    {
        return m_tree.rbegin();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::reverse_iterator map<K, T, C, A>::rend()
    {
        return m_tree.rend();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::const_reverse_iterator map<K, T, C, A>::rend() const
    {
        return m_tree.rend();
    }

    template<class Key, class T, class Compare, class Alloc>
    bool map<Key, T, Compare, Alloc>::empty() const
    {
        return m_tree.empty();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::size_type map<K, T, C, A>::size() const
    {
        return m_tree.size();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::size_type map<K, T, C, A>::max_size() const
    {
        return m_tree.max_size();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::mapped_type&
    map<K, T, C, A>::operator[](const key_type& k)
    {
        node_pointer parent;
        node_pointer node = _find_by_key(parent, k);
        if (!node)
        {
            node = m_tree._allocate_node();

            typename allocator_type::template rebind<key_type>::other key_alloc(m_tree.m_alloc);
            typename allocator_type::template rebind<mapped_type>::other mapped_alloc(m_tree.m_alloc);

            map_node_guard guard(m_tree.m_node_alloc, node);
            key_alloc.construct(const_cast<key_type*>(&node->m_value.first), k);
            guard.m_is_first_constructed = true;
            mapped_alloc.construct(&node->m_value.second);
            guard.m_is_second_constructed = true;
            guard.release();

            m_tree._insert_node(parent, node);
            m_tree._balance_after_insert(node);
            m_tree.m_size += 1;
        }
        return node->m_value.second;
    }

    template<class K, class T, class C, class A>
    ft::pair<typename map<K, T, C, A>::iterator, bool>
    map<K, T, C, A>::insert(const value_type& val)
    {
        return m_tree.insert(val);
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::iterator
    map<K, T, C, A>::insert(iterator position, const value_type& val)
    {
        return m_tree.insert(position, val);
    }

    template<class Key, class T, class Compare, class Alloc>
    template<class InputIterator>
    void map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last,
                                             typename enable_if<!is_arithmetic<InputIterator>::value>::type*)
    {
        for (iterator it = begin(); first != last; ++first)
            it = insert(it, *first);
    }

    template<class K, class T, class C, class A>
    void map<K, T, C, A>::erase(iterator position)
    {
        m_tree.erase(position);
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::size_type map<K, T, C, A>::erase(const key_type& k)
    {
        iterator it = find(k);
        if (it != end())
        {
            erase(it);
            return 1;
        }
        return 0;
    }

    template<class K, class T, class C, class A>
    void map<K, T, C, A>::erase(iterator first, iterator last)
    {
        while (first != last)
            erase(first++);
    }

    template<class Key, class T, class Compare, class Alloc>
    void map<Key, T, Compare, Alloc>::swap(map& x)
    {
        m_tree.swap(x.m_tree);
    }

    template<class K, class T, class C, class A>
    void map<K, T, C, A>::clear()
    {
        m_tree.clear();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::key_compare map<K, T, C, A>::key_comp() const
    {
        return m_tree.value_comp().comp;
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::value_compare map<K, T, C, A>::value_comp() const
    {
        return m_tree.value_comp();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::iterator map<K, T, C, A>::find(const key_type& k)
    {
        node_pointer dummy;
        node_pointer node = _find_by_key(dummy, k);
        return node ? iterator(node) : end();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::const_iterator map<K, T, C, A>::find(const key_type& k) const
    {
        node_pointer dummy;
        node_pointer node = _find_by_key(dummy, k);
        return node ? const_iterator(node) : end();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::size_type map<K, T, C, A>::count(const key_type& k) const
    {
        return find(k) != end();
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::iterator map<K, T, C, A>::lower_bound(const key_type& k)
    {
        return _lower_bound(k);
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::const_iterator map<K, T, C, A>::lower_bound(const key_type& k) const
    {
        return const_cast<this_type*>(this)->lower_bound(k);
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::iterator map<K, T, C, A>::upper_bound(const key_type& k)
    {
        return _upper_bound(k);
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::const_iterator map<K, T, C, A>::upper_bound(const key_type& k) const
    {
        return const_cast<this_type*>(this)->_upper_bound(k);
    }

    template<class K, class T, class C, class A>
    ft::pair<typename map<K, T, C, A>::iterator, typename map<K, T, C, A>::iterator>
    map<K, T, C, A>::equal_range(const key_type& k)
    {
        return _equal_range(k);
    }

    template<class K, class T, class C, class A>
    ft::pair<typename map<K, T, C, A>::const_iterator, typename map<K, T, C, A>::const_iterator>
    map<K, T, C, A>::equal_range(const key_type& k) const
    {
        return const_cast<this_type*>(this)->_equal_range(k);
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::allocator_type map<K, T, C, A>::get_allocator() const
    {
        return m_tree.m_alloc;
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::node_pointer
    map<K, T, C, A>::_find_by_key(node_pointer& parent, const key_type& k) const
    {
        node_pointer cur = static_cast<node_pointer>(const_cast<node_base_pointer>(m_tree.m_base.m_parent));
        const key_compare& key_comp = m_tree.m_comp.comp;
        while (cur)
        {
            if (key_comp(k, static_cast<node_pointer>(cur)->m_value.first))
            {
                if (cur->m_left)
                    cur = static_cast<node_pointer>(cur->m_left);
                else
                {
                    parent = cur;
                    return NULL;
                }
            }
            else if (key_comp(cur->m_value.first, k))
            {
                if (cur->m_right)
                    cur = static_cast<node_pointer>(cur->m_right);
                else
                {
                    parent = cur;
                    return NULL;
                }
            }
            else
                return cur;

        }
        parent = static_cast<node_pointer>(const_cast<node_base_pointer>(&m_tree.m_base));
        return NULL;
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::node_pointer
    map<K, T, C, A>::_lower_bound(const key_type& k)
    {
        node_pointer cur = static_cast<node_pointer>(m_tree.m_base.m_parent);
        node_pointer end = static_cast<node_pointer>(&m_tree.m_base);
        const key_compare& key_comp = m_tree.m_comp.comp;
        while(cur)
        {
            if (key_comp(cur->m_value.first, k))
                cur = static_cast<node_pointer>(cur->m_right);
            else
            {
                end = cur;
                cur = static_cast<node_pointer>(cur->m_left);
            }
        }
        return end;
    }

    template<class K, class T, class C, class A>
    typename map<K, T, C, A>::node_pointer
    map<K, T, C, A>::_upper_bound(const key_type& k)
    {
        node_pointer cur = static_cast<node_pointer>(m_tree.m_base.m_parent);
        node_pointer end = static_cast<node_pointer>(&m_tree.m_base);
        const key_compare& key_comp = m_tree.m_comp.comp;
        while(cur)
        {
            if (!key_comp(k, cur->m_value.first))
                cur = static_cast<node_pointer>(cur->m_right);
            else
            {
                end = cur;
                cur = static_cast<node_pointer>(cur->m_left);
            }
        }
        return end;
    }

    template<class K, class T, class C, class A>
    ft::pair<typename map<K, T, C, A>::node_pointer, typename map<K, T, C, A>::node_pointer>
    map<K, T, C, A>::_equal_range(const key_type& k)
    {
        node_pointer cur = static_cast<node_pointer>(m_tree.m_base.m_parent);
        node_pointer end = static_cast<node_pointer>(&m_tree.m_base);
        const key_compare& key_comp = m_tree.m_comp.comp;
        while(cur)
        {
            if (key_comp(cur->m_value.first, k))
                cur = static_cast<node_pointer>(cur->m_right);
            else if (key_comp(k, cur->m_value.first))
            {
                end = cur;
                cur = static_cast<node_pointer>(cur->m_left);
            }
            else
                return make_pair(cur,
                        cur->m_right != NULL ? static_cast<node_pointer>(rb_min(cur->m_right)) : end);
        }
        return make_pair(end, end);
    }

    template<class K, class T, class C, class A>
    bool operator==(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs)
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template<class K, class T, class C, class A>
    bool operator!=(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs)
    {
        return !(lhs == rhs);
    }

    template<class K, class T, class C, class A>
    bool operator<(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<class K, class T, class C, class A>
    bool operator<=(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs)
    {
        return !(rhs < lhs);
    }

    template<class K, class T, class C, class A>
    bool operator>(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs)
    {
        return rhs < lhs;
    }

    template<class K, class T, class C, class A>
    bool operator>=(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs)
    {
        return !(lhs < rhs);
    }

    template<class K, class T, class C, class A>
    void swap(map<K, T, C, A>& x, map<K, T, C, A>& y)
    {
        x.swap(y);
    }

    template<class K, class T, class C, class A>
    map<K, T, C, A>::map_node_guard::map_node_guard(node_allocator_type& node_alloc, node_pointer node)
        : node_guard_type(node_alloc, node)
        , m_is_first_constructed(false)
        , m_is_second_constructed(false)
    {
    }

    template<class K, class T, class C, class A>
    map<K, T, C, A>::map_node_guard::~map_node_guard()
    {
        if (m_node)
        {
            if (m_is_first_constructed)
            {
                typename allocator_type::template rebind<key_type>::other key_alloc(m_node_alloc);
                key_alloc.destroy(const_cast<key_type*>(&m_node->m_value.first));
            }
            if (m_is_second_constructed)
            {
                typename allocator_type::template rebind<mapped_type>::other mapped_alloc(m_node_alloc);
                mapped_alloc.destroy(&m_node->m_value.second);
            }
        }
    }
}

#endif //FT_CONTAINERS_MAP_IMPL_HPP
