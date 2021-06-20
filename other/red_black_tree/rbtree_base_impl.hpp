#ifndef FT_CONTAINERS_RBTREE_BASE_IMPL_HPP
#define FT_CONTAINERS_RBTREE_BASE_IMPL_HPP

#include "rbtree_base.hpp"

namespace ft { namespace detail
{
    template<class V, class C, class A>
    rbtree_base<V, C, A>::rbtree_base(const value_compare& comp, const allocator_type& alloc)
        : m_alloc(alloc), m_node_alloc(alloc), m_comp(comp), m_size(0)
    {
        _init();
    }

    template<class V, class C, class A>
    rbtree_base<V, C, A>::~rbtree_base()
    {
        _free_subtree(static_cast<node_pointer>(m_base.m_parent));
    }

    template<class V, class C, class A>
    void rbtree_base<V, C, A>::_init()
    {
        m_base.m_right = &m_base;
        m_base.m_left = &m_base;
        m_base.m_parent = NULL;
        m_base.m_color = node_type::red;
    }

    template<class V, class C, class A>
    void rbtree_base<V, C, A>::_free_node(node_pointer node)
    {
        m_alloc.destroy(&node->m_value);
        m_node_alloc.deallocate(node, 1);
    }

    template<class V, class C, class A>
    void rbtree_base<V, C, A>::_free_subtree(node_pointer node)
    {
        if (node)
        {
            /*
            destroy(static_cast<__node_pointer>(__nd->__left_));
            destroy(static_cast<__node_pointer>(__nd->__right_));
            __node_allocator& __na = __node_alloc();
            __node_traits::destroy(__na, _NodeTypes::__get_ptr(__nd->__value_));
            __node_traits::deallocate(__na, __nd, 1);
             */

            _free_subtree(static_cast<node_pointer>(node->m_left));
            _free_subtree(static_cast<node_pointer>(node->m_right));
            _free_node(node);
        }
    }

    template<class V, class C, class A>
    rbtree_base<V, C, A>::rb_node_guard::rb_node_guard(node_allocator_type& node_alloc, node_pointer node)
        : m_node_alloc(node_alloc), m_node(node)
    {
    }

    template<class V, class C, class A>
    rbtree_base<V, C, A>::rb_node_guard::~rb_node_guard()
    {
        if (m_node)
            m_node_alloc.deallocate(m_node, 1);
    }

    template<class V, class C, class A>
    void rbtree_base<V, C, A>::rb_node_guard::release()
    {
        m_node = NULL;
    }
} }

#endif //FT_CONTAINERS_RBTREE_BASE_IMPL_HPP
