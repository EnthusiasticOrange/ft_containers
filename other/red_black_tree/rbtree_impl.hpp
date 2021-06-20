#ifndef FT_CONTAINERS_RBTREE_IMPL_HPP
#define FT_CONTAINERS_RBTREE_IMPL_HPP

#include "rbtree.hpp"

namespace ft { namespace detail
{
    template<class V, class C, class A>
    rbtree<V, C, A>::rbtree(const value_compare& comp, const allocator_type& alloc)
        : base_type(comp, alloc)
    {
    }

    template<class V, class C, class A>
    rbtree<V, C, A>::rbtree(const rbtree& x)
        : base_type(x.m_comp, x.m_alloc)
    {
        iterator it = begin();
        for (iterator x_it = x.begin(); x_it != x.end(); ++x_it)
            it = insert(it, *x_it);
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::iterator rbtree<V, C, A>::begin()
    {
        return iterator(static_cast<node_pointer>(m_base.m_left));
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::const_iterator rbtree<V, C, A>::begin() const
    {
        return const_iterator(static_cast<node_pointer>(const_cast<node_base_pointer>(m_base.m_left)));
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::iterator rbtree<V, C, A>::end()
    {
        return iterator(static_cast<node_pointer>(&m_base));
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::const_iterator rbtree<V, C, A>::end() const
    {
        return const_iterator(static_cast<node_pointer>(const_cast<node_base_pointer>(&m_base)));
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::reverse_iterator rbtree<V, C, A>::rbegin()
    {
        return reverse_iterator(end());
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::const_reverse_iterator rbtree<V, C, A>::rbegin() const
    {
        return const_reverse_iterator(end());
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::reverse_iterator rbtree<V, C, A>::rend()
    {
        return reverse_iterator(begin());
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::const_reverse_iterator rbtree<V, C, A>::rend() const
    {
        return const_reverse_iterator(begin());
    }

    template<class V, class C, class A>
    bool rbtree<V, C, A>::empty() const
    {
        return m_size == 0;
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::size_type rbtree<V, C, A>::size() const
    {
        return m_size;
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::size_type rbtree<V, C, A>::max_size() const
    {
        return m_node_alloc.max_size();
    }

    template<class V, class C, class A>
    pair<typename rbtree<V, C, A>::iterator, bool>
    rbtree<V, C, A>::insert(const_reference val)
    {
        node_pointer parent;
        node_pointer node = _find(parent, val);
        bool inserted = false;
        if (!node)
        {
            node = _create_and_insert(parent, val);
            inserted = true;
        }
        return ft::make_pair(iterator(node), inserted);
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::iterator rbtree<V, C, A>::insert(iterator hint, const_reference val)
    {
        if (hint == end())
            return insert(val).first;
        if (m_comp(*hint, val))
        {
            iterator next(hint);
            ++next;
            if (next == end() || m_comp(val, *next))
            {
                node_pointer parent;
                if (next == end() || !hint.m_node->m_right)
                    parent = hint.m_node;
                else
                    parent = next.m_node;
                node_pointer node = _create_and_insert(parent, val);
                return iterator(node);
            }
            else if (m_comp(*next, val))
                return insert(val).first;
            else
                return next;
        }
        else if (m_comp(val, *hint))
            return insert(val).first;
        else
            return hint;
    }

    template<class V, class C, class A>
    void rbtree<V, C, A>::erase(iterator position)
    {
        _remove_node(position.m_node);
        _free_node(static_cast<node_pointer>(position.m_node));
        --m_size;
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::iterator
    rbtree<V, C, A>::find(const_reference val)
    {
        node_pointer parent;
        node_pointer node = _find(parent, val);
        if (!node)
            return end();
        else
            return iterator(node);
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::const_iterator
    rbtree<V, C, A>::find(const_reference val) const
    {
        node_pointer parent;
        node_pointer node = _find(parent, val);
        if (!node)
            return end();
        else
            return const_iterator(node);
    }

    template<class V, class C, class A>
    void rbtree<V, C, A>::swap(this_type& x)
    {
        ft::ft_swap(m_alloc, x.m_alloc);
        ft::ft_swap(m_node_alloc, x.m_node_alloc);
        ft::ft_swap(m_comp, x.m_comp);
        ft::ft_swap(m_size, x.m_size);

        if (m_base.m_parent && x.m_base.m_parent)
        {
            ft::ft_swap(m_base.m_parent, x.m_base.m_parent);
            ft::ft_swap(m_base.m_right, x.m_base.m_right);
            ft::ft_swap(m_base.m_left, x.m_base.m_left);

            m_base.m_parent->m_parent = &m_base;
            x.m_base.m_parent->m_parent = &x.m_base;
        }
        else if (m_base.m_parent)
        {
            x.m_base.m_parent = m_base.m_parent;
            x.m_base.m_parent->m_parent = &x.m_base;
            x.m_base.m_left = m_base.m_left;
            x.m_base.m_right = m_base.m_right;

            m_base.m_parent = NULL;
            m_base.m_left = &m_base;
            m_base.m_right = &m_base;
        }
        else if (x.m_base.m_parent)
        {
            m_base.m_parent = x.m_base.m_parent;
            m_base.m_parent->m_parent = &m_base;
            m_base.m_left = x.m_base.m_left;
            m_base.m_right = x.m_base.m_right;

            x.m_base.m_parent = NULL;
            x.m_base.m_left = &x.m_base;
            x.m_base.m_right = &x.m_base;
        }
    }

    template<class V, class C, class A>
    void rbtree<V, C, A>::clear()
    {
        _free_subtree(static_cast<node_pointer>(m_base.m_parent));
        m_base.m_parent = NULL;
        m_base.m_left = &m_base;
        m_base.m_right = &m_base;
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::value_compare rbtree<V, C, A>::value_comp() const
    {
        return m_comp;
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::iterator rbtree<V, C, A>::lower_bound(const value_type& val)
    {
        node_pointer cur = static_cast<node_pointer>(m_base.m_parent);
        node_pointer end = static_cast<node_pointer>(&m_base);

        while(cur)
        {
            if (m_comp(cur->m_value, val))
                cur = static_cast<node_pointer>(cur->m_right);
            else
            {
                end = cur;
                cur = static_cast<node_pointer>(cur->m_left);
            }
        }
        return iterator(end);
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::const_iterator rbtree<V, C, A>::lower_bound(const value_type& val) const
    {
        return const_iterator(const_cast<this_type*>(this)->lower_bound(val));
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::iterator rbtree<V, C, A>::upper_bound(const value_type& val)
    {
        node_pointer cur = static_cast<node_pointer>(m_base.m_parent);
        node_pointer end = static_cast<node_pointer>(&m_base);

        while(cur)
        {
            if (!m_comp(cur->m_value, val))
                cur = static_cast<node_pointer>(cur->m_right);
            else
            {
                end = cur;
                cur = static_cast<node_pointer>(cur->m_left);
            }
        }
        return iterator(end);
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::const_iterator rbtree<V, C, A>::upper_bound(const value_type& val) const
    {
        return const_iterator(const_cast<this_type*>(this)->upper_bound(val));
    }

    template<class V, class C, class A>
    ft::pair<typename rbtree<V, C, A>::iterator, typename rbtree<V, C, A>::iterator>
    rbtree<V, C, A>::equal_range(const value_type& val)
    {
        node_pointer cur = static_cast<node_pointer>(m_base.m_parent);
        node_pointer end = static_cast<node_pointer>(&m_base);

        while(cur)
        {
            if (m_comp(cur->m_value, val))
                cur = static_cast<node_pointer>(cur->m_right);
            else if (m_comp(val, cur->m_value))
            {
                end = cur;
                cur = static_cast<node_pointer>(cur->m_left);
            }
            else
                return make_pair(iterator(cur),
                                 iterator(cur->m_right != NULL ? static_cast<node_pointer>(rb_min(cur->m_right)) : end));
        }
        return make_pair(iterator(end), iterator(end));
    }

    template<class V, class C, class A>
    ft::pair<typename rbtree<V, C, A>::const_iterator, typename rbtree<V, C, A>::const_iterator>
    rbtree<V, C, A>::equal_range(const value_type& val) const
    {
        return const_iterator(const_cast<this_type*>(this)->equal_range(val));
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::node_pointer rbtree<V, C, A>::_allocate_node()
    {
        node_pointer p = m_node_alloc.allocate(1);
        return p;
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::node_pointer rbtree<V, C, A>::_create_node(const_reference val)
    {
        node_pointer p = _allocate_node();
        node_guard_type guard(m_node_alloc, p);

        m_alloc.construct(&p->m_value, val);

        guard.release();
        return p;
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::node_pointer
    rbtree<V, C, A>::_create_and_insert(node_pointer parent, const_reference val)
    {
        node_pointer node = _create_node(val);
        _insert_node(parent, node);
        _balance_after_insert(node);
        ++m_size;
        return node;
    }

    template<class V, class C, class A>
    typename rbtree<V, C, A>::node_pointer rbtree<V, C, A>::_find(node_pointer& parent, const_reference val) const
    {
        node_pointer cur = static_cast<node_pointer>(m_base.m_parent);
        while (cur)
        {
            if (m_comp(val, static_cast<node_pointer>(cur)->m_value))
            {
                if (cur->m_left)
                    cur = static_cast<node_pointer>(cur->m_left);
                else
                {
                    parent = cur;
                    return NULL;
                }
            }
            else if (m_comp(cur->m_value, val))
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
        parent = static_cast<node_pointer>(const_cast<node_base_pointer>(&m_base));
        return NULL;
    }

    template<class Value, class Compare, class Allocator>
    void rbtree<Value, Compare, Allocator>::_rotate_left(node_base_pointer node)
    {
        node_base_pointer temp = node->m_right;

        node->m_right = temp->m_left;
        if (temp->m_left)
            temp->m_left->m_parent = node;
        temp->m_parent = node->m_parent;

        if (node == m_base.m_parent)
            m_base.m_parent = temp;
        else if (node == node->m_parent->m_left)
            node->m_parent->m_left = temp;
        else
            node->m_parent->m_right = temp;

        temp->m_left = node;
        node->m_parent = temp;
    }

    template<class Value, class Compare, class Allocator>
    void rbtree<Value, Compare, Allocator>::_rotate_right(node_base_pointer node)
    {
        node_base_pointer temp = node->m_left;

        node->m_left = temp->m_right;
        if (temp->m_right)
            temp->m_right->m_parent = node;
        temp->m_parent = node->m_parent;

        if (node == m_base.m_parent)
            m_base.m_parent = temp;
        else if (node == node->m_parent->m_right)
            node->m_parent->m_right = temp;
        else
            node->m_parent->m_left = temp;

        temp->m_right = node;
        node->m_parent = temp;
    }

    template<class Value, class Compare, class Allocator>
    void rbtree<Value, Compare, Allocator>::_insert_node(node_pointer parent, node_pointer node)
    {
        node->m_left = NULL;
        node->m_right = NULL;
        node->m_parent = parent;
        node->m_color = node_base_type::red;

        if (parent == &m_base || !m_comp(parent->m_value, node->m_value))
        {
            parent->m_left = node;
            if (parent == &m_base)
            {
                m_base.m_parent = node;
                m_base.m_right = node;
            }
            else if (parent == m_base.m_left)
                m_base.m_left = node;
        }
        else
        {
            parent->m_right = node;
            if (parent == m_base.m_right)
                m_base.m_right = node;
        }
    }

    template<class V, class C, class A>
    void rbtree<V, C, A>::_balance_after_insert(node_base_pointer node)
    {
        while (node != m_base.m_parent && node->m_parent->m_color == node_base_type::red)
        {
            node_base_pointer g_parent = node->m_parent->m_parent;
            if (rb_is_left_child(node->m_parent))
            {
                node_base_pointer temp = g_parent->m_right;
                if (temp && temp->m_color == node_base_type::red)
                {
                    node = node->m_parent;
                    node->m_color = node_base_type::black;
                    node = node->m_parent;
                    node->m_color = node_base_type::red;
                    temp->m_color = node_base_type::black;
                }
                else
                {
                    if (rb_is_right_child(node))
                    {
                        node = node->m_parent;
                        _rotate_left(node);
                    }
                    node = node->m_parent;
                    node->m_color = node_base_type::black;
                    node = node->m_parent;
                    node->m_color = node_base_type::red;
                    _rotate_right(node);
                }
            }
            else
            {
                node_base_pointer temp = g_parent->m_left;
                if (temp && temp->m_color == node_base_type::red)
                {
                    node = node->m_parent;
                    node->m_color = node_base_type::black;
                    node = node->m_parent;
                    node->m_color = node_base_type::red;
                    temp->m_color = node_base_type::black;
                }
                else
                {
                    if (rb_is_left_child(node))
                    {
                        node = node->m_parent;
                        _rotate_right(node);
                    }
                    node = node->m_parent;
                    node->m_color = node_base_type::black;
                    node = node->m_parent;
                    node->m_color = node_base_type::red;
                    _rotate_left(node);
                }
            }
        }
        m_base.m_parent->m_color = node_base_type::black;
    }

    template<class V, class C, class A>
    void rbtree<V, C, A>::_remove_node(node_base_pointer node)
    {
        node_base_pointer child_parent;
        node_base_pointer replace = node;
        if (node->m_left && node->m_right)
            replace = rb_next(node);

        node_base_pointer child = replace->m_left ? replace->m_left : replace->m_right;
        child_parent = replace->m_parent;
        if (child)
            child->m_parent = child_parent;

        if (replace == node)
        {
            if (node == m_base.m_parent)
                m_base.m_parent = child;
            else
            {
                if (rb_is_left_child(node))
                    node->m_parent->m_left = child;
                else
                    node->m_parent->m_right = child;
            }
            if (node == m_base.m_left)
            {
                if (node->m_right && child)
                    m_base.m_left = rb_min(child);
                else
                    m_base.m_left = node->m_parent;
            }
            if (node == m_base.m_right)
            {
                if (node->m_left && child)
                    m_base.m_right = rb_max(child);
                else
                    m_base.m_right = node->m_parent;
            }
        }
        else
        {
            replace->m_left = node->m_left;
            node->m_left->m_parent = replace;

            if (node->m_right != replace)
            {
                replace->m_right = node->m_right;
                node->m_right->m_parent = replace;
                replace->m_parent->m_left = child;
            }
            else
                child_parent = replace;

            replace->m_parent = node->m_parent;
            replace->m_color = node->m_color;

            if (node == m_base.m_parent)
                m_base.m_parent = replace;
            else if (rb_is_left_child(node))
                replace->m_parent->m_left = replace;
            else
                replace->m_parent->m_right = replace;
        }

        if (node->m_color == node_base_type::black)
        {
            while (child != m_base.m_parent && (!child || child->m_color == node_base_type::black))
            {
                if (child == child_parent->m_left)
                {
                    node_base_pointer temp = child_parent->m_right;
                    if (temp->m_color == node_base_type::red)
                    {
                        temp->m_color = node_base_type::black;
                        child_parent->m_color = node_base_type::red;
                        _rotate_left(child_parent);
                        temp = child_parent->m_right;
                    }
                    if ((!temp->m_left || temp->m_left->m_color == node_base_type::black)
                        && (!temp->m_right || temp->m_right->m_color == node_base_type::black))
                    {
                        temp->m_color = node_base_type::red;
                        child = child_parent;
                        child_parent = child_parent->m_parent;
                    }
                    else
                    {
                        if (!temp->m_right || temp->m_right->m_color == node_base_type::black)
                        {
                            temp->m_left->m_color = node_base_type::black;
                            temp->m_color = node_base_type::red;
                            _rotate_right(temp);
                            temp = child_parent->m_right;
                        }
                        temp->m_color = child_parent->m_color;
                        child_parent->m_color = node_base_type::black;
                        if (temp->m_right)
                            temp->m_right->m_color = node_base_type::black;
                        _rotate_left(child_parent);
                        break;
                    }
                }
                else
                {
                    node_base_pointer temp = child_parent->m_left;
                    if (temp->m_color == node_base_type::red)
                    {
                        temp->m_color = node_base_type::black;
                        child_parent->m_color = node_base_type::red;
                        _rotate_right(child_parent);
                        temp = child_parent->m_left;
                    }
                    if ((!temp->m_left || temp->m_left->m_color == node_base_type::black)
                        && (!temp->m_right || temp->m_right->m_color == node_base_type::black))
                    {
                        temp->m_color = node_base_type::red;
                        child = child_parent;
                        child_parent = child_parent->m_parent;
                    }
                    else
                    {
                        if (!temp->m_left || temp->m_left->m_color == node_base_type::black)
                        {
                            temp->m_right->m_color = node_base_type::black;
                            temp->m_color = node_base_type::red;
                            _rotate_left(temp);
                            temp = child_parent->m_left;
                        }
                        temp->m_color = child_parent->m_color;
                        child_parent->m_color = node_base_type::black;
                        if (temp->m_left)
                            temp->m_left->m_color = node_base_type::black;
                        _rotate_right(child_parent);
                        break;
                    }
                }
            }
            if (child)
                child->m_color = node_base_type::black;
        }
    }

    template<class V, class C, class A>
    static void _print_node(typename rbtree<V, C, A>::node_pointer p)
    {
        if (!p->m_color)
            std::cout << p->m_value << "[fillcolor=red];" << std::endl;
        typename rbtree<V, C, A>::node_pointer leaf;
        if (p->m_left)
        {
            leaf = (typename rbtree<V, C, A>::node_pointer)p->m_left;
            std::cout << p->m_value << " -> " << leaf->m_value << ";" << std::endl;
            _print_node<V, C, A>(leaf);
        }
        else
            std::cout << p->m_value << " -> " << "\"NIL\\n" << p->m_value << "L\"" << ";" << std::endl;

        if (p->m_right)
        {
            leaf = (typename rbtree<V, C, A>::node_pointer)p->m_right;
            std::cout << p->m_value << " -> " << leaf->m_value << ";" << std::endl;
            _print_node<V, C, A>(leaf);
        }
        else
            std::cout << p->m_value << " -> " << "\"NIL\\n" << p->m_value << "R\"" << ";" << std::endl;
    }

    template<class V, class C, class A>
    void rbtree<V, C, A>::debug_print() const
    {
        node_pointer root = static_cast<node_pointer>(m_base.m_parent);
        if (!root)
            std::cout << "EMPTY" << std::endl;
        else if (!root->m_left && !root->m_right)
            std::cout << root->m_value << ";" << std::endl;
        else
            _print_node<V, C, A>(root);
    }
template<class Value, class Compare, class Allocator>
bool rbtree<Value, Compare, Allocator>::is_balanced() const
{
    return (_max_depth(m_base.m_parent) - _min_depth(m_base.m_parent) <= 1);
}
template<class Value, class Compare, class Allocator>
int rbtree<Value, Compare, Allocator>::_max_depth(rbtree::node_base_pointer p) const
{
    if (!p) return 0;
    if (p->m_color)
        return 1 + ft::max(_max_depth(p->m_left), _max_depth(p->m_right));
    else
        return ft::max(_max_depth(p->m_left), _max_depth(p->m_right));
}
template<class Value, class Compare, class Allocator>
int rbtree<Value, Compare, Allocator>::_min_depth(rbtree::node_base_pointer p) const
{
    if (!p) return 0;
    if (p->m_color)
        return 1 + ft::min(_min_depth(p->m_left), _min_depth(p->m_right));
    else
        return ft::min(_min_depth(p->m_left), _min_depth(p->m_right));
}
} }

#endif //FT_CONTAINERS_RBTREE_IMPL_HPP
