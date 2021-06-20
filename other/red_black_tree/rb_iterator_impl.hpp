#ifndef FT_CONTAINERS_RB_ITERATOR_IMPL_HPP
#define FT_CONTAINERS_RB_ITERATOR_IMPL_HPP

namespace ft { namespace detail
{
    template<class T, class Pointer, class Reference>
    rb_iterator<T, Pointer, Reference>::rb_iterator()
        : m_node(NULL)
    {
    }

    template<class T, class Pointer, class Reference>
    rb_iterator<T, Pointer, Reference>::rb_iterator(node_type* node)
        : m_node(node)
    {
    }

    template<class T, class Pointer, class Reference>
    rb_iterator<T, Pointer, Reference>::rb_iterator(const iterator& other)
        : m_node(other.m_node)
    {
    }

    template<class T, class Pointer, class Reference>
    rb_iterator<T, Pointer, Reference>::rb_iterator(const const_iterator& other)
        : m_node(other.m_node)
    {
    }

    template<class T, class Pointer, class Reference>
    typename rb_iterator<T, Pointer, Reference>::this_type&
    rb_iterator<T, Pointer, Reference>::operator=(const iterator& other)
    {
        if (this != &other)
            m_node = other.m_node;
        return *this;
    }

    template<class T, class Pointer, class Reference>
    typename rb_iterator<T, Pointer, Reference>::this_type&
    rb_iterator<T, Pointer, Reference>::operator=(const const_iterator& other)
    {
        if (this != &other)
            m_node = other.m_node;
        return *this;
    }

    template<class T, class Pointer, class Reference>
    typename rb_iterator<T, Pointer, Reference>::reference
    rb_iterator<T, Pointer, Reference>::operator*() const
    {
        return m_node->m_value;
    }

    template<class T, class Pointer, class Reference>
    typename rb_iterator<T, Pointer, Reference>::pointer
    rb_iterator<T, Pointer, Reference>::operator->() const
    {
        return &m_node->m_value;
    }

    template<class T, class Pointer, class Reference>
    typename rb_iterator<T, Pointer, Reference>::this_type&
    rb_iterator<T, Pointer, Reference>::operator++()
    {
        m_node = static_cast<node_type*>(rb_next(m_node));
        return *this;
    }

    template<class T, class Pointer, class Reference>
    typename rb_iterator<T, Pointer, Reference>::this_type
    rb_iterator<T, Pointer, Reference>::operator++(int)
    {
        this_type tmp(m_node);
        m_node = static_cast<node_type*>(rb_next(m_node));
        return tmp;
    }

    template<class T, class Pointer, class Reference>
    typename rb_iterator<T, Pointer, Reference>::this_type&
    rb_iterator<T, Pointer, Reference>::operator--()
    {
        m_node = static_cast<node_type*>(rb_prev(m_node));
        return *this;
    }

    template<class T, class Pointer, class Reference>
    typename rb_iterator<T, Pointer, Reference>::this_type
    rb_iterator<T, Pointer, Reference>::operator--(int)
    {
        this_type tmp(m_node);
        m_node = static_cast<node_type*>(rb_prev(m_node));
        return tmp;
    }

    template<class T, class Pointer, class Reference>
    bool rb_iterator<T, Pointer, Reference>::operator==(
            const typename rb_iterator<T, Pointer, Reference>::this_type& other)
    {
        return m_node == other.m_node;
    }

    template<class T, class Pointer, class Reference>
    bool rb_iterator<T, Pointer, Reference>::operator!=(
            const typename rb_iterator<T, Pointer, Reference>::this_type& other)
    {
        return m_node != other.m_node;
    }
} }

#endif //FT_CONTAINERS_RB_ITERATOR_IMPL_HPP
