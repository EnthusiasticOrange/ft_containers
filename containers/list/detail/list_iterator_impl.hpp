#ifndef FT_CONTAINERS_LIST_ITERATOR_IMPL_HPP
#define FT_CONTAINERS_LIST_ITERATOR_IMPL_HPP

namespace ft { namespace detail
{
    template<class T, class Pointer, class Reference>
    list_iterator<T, Pointer, Reference>::list_iterator()
        : m_node(NULL)
    {
    }

    template<class T, class Pointer, class Reference>
    list_iterator<T, Pointer, Reference>::list_iterator(node_type* node)
        : m_node(node)
    {
    }

    template<class T, class Pointer, class Reference>
    list_iterator<T, Pointer, Reference>::list_iterator(const iterator & other)
        : m_node(other.m_node)
    {
    }

    template<class T, class Pointer, class Reference>
    list_iterator<T, Pointer, Reference>::list_iterator(const const_iterator & other)
            : m_node(other.m_node)
    {
    }

    template<class T, class Pointer, class Reference>
    typename list_iterator<T, Pointer, Reference>::this_type&
    list_iterator<T, Pointer, Reference>::operator=(const this_type& other)
    {
        if (this != &other)
            m_node = other.m_node;
        return *this;
    }

    template<class T, class Pointer, class Reference>
    typename list_iterator<T, Pointer, Reference>::reference
    list_iterator<T, Pointer, Reference>::operator*() const
    {
        return m_node->m_value;
    }

    template<class T, class Pointer, class Reference>
    typename list_iterator<T, Pointer, Reference>::pointer
    list_iterator<T, Pointer, Reference>::operator->() const
    {
        return &m_node->m_value;
    }

    template<class T, class Pointer, class Reference>
    typename list_iterator<T, Pointer, Reference>::this_type&
    list_iterator<T, Pointer, Reference>::operator++()
    {
        m_node = static_cast<node_type*>(m_node->m_next);
        return *this;
    }

    template<class T, class Pointer, class Reference>
    typename list_iterator<T, Pointer, Reference>::this_type
    list_iterator<T, Pointer, Reference>::operator++(int)
    {
        this_type tmp(m_node);
        m_node = static_cast<node_type*>(m_node->m_next);
        return tmp;
    }

    template<class T, class Pointer, class Reference>
    typename list_iterator<T, Pointer, Reference>::this_type&
    list_iterator<T, Pointer, Reference>::operator--()
    {
        m_node = static_cast<node_type*>(m_node->m_prev);
        return *this;
    }

    template<class T, class Pointer, class Reference>
    typename list_iterator<T, Pointer, Reference>::this_type
    list_iterator<T, Pointer, Reference>::operator--(int)
    {
        this_type tmp(m_node);
        m_node = static_cast<node_type*>(m_node->m_prev);
        return tmp;
    }

    template<class T, class Pointer, class Reference>
    bool list_iterator<T, Pointer, Reference>::operator==(
            const typename list_iterator<T, Pointer, Reference>::this_type& other)
    {
        return m_node == other.m_node;
    }

    template<class T, class Pointer, class Reference>
    bool list_iterator<T, Pointer, Reference>::operator!=(
            const typename list_iterator<T, Pointer, Reference>::this_type& other)
    {
        return m_node != other.m_node;
    }
} }

#endif //FT_CONTAINERS_LIST_ITERATOR_IMPL_HPP
