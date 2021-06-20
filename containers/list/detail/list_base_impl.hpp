#ifndef FT_CONTAINERS_LIST_BASE_IMPL_H
#define FT_CONTAINERS_LIST_BASE_IMPL_H

namespace ft { namespace detail
{
    template<class T, class Allocator>
    list_base<T, Allocator>::list_base(const allocator_type& alloc)
        : m_base(), m_alloc(alloc), m_node_alloc(alloc), m_size(0)
    {
        _init();
    }

    template<class T, class Allocator>
    list_base<T, Allocator>::~list_base()
    {
        _clear();
    }

    template<class T, class Allocator>
    void list_base<T, Allocator>::_init()
    {
        m_base.m_prev = &m_base;
        m_base.m_next = &m_base;
    }

    template<class T, class Allocator>
    void list_base<T, Allocator>::_clear()
    {
        node_pointer p = static_cast<node_pointer>(m_base.m_next);

        while(p != &m_base)
        {
            node_pointer temp = p;
            p = static_cast<node_pointer>(p->m_next);
            m_alloc.destroy(&temp->m_value);
            m_node_alloc.deallocate(temp, 1);
        }
    }

    template<class T, class Allocator>
    list_base<T, Allocator>::list_node_guard::list_node_guard(node_allocator_type& node_alloc,
            node_pointer node)
        : m_node_alloc(node_alloc), m_node(node)
    {
    }

    template<class T, class Allocator>
    list_base<T, Allocator>::list_node_guard::~list_node_guard()
    {
        if (m_node)
            m_node_alloc.deallocate(m_node, 1);
    }

    template<class T, class Allocator>
    void list_base<T, Allocator>::list_node_guard::release()
    {
        m_node = NULL;
    }
} }

#endif //FT_CONTAINERS_LIST_BASE_IMPL_H
