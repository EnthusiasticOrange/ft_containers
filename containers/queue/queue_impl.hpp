#ifndef FT_CONTAINERS_QUEUE_IMPL_HPP
#define FT_CONTAINERS_QUEUE_IMPL_HPP

#include "containers/queue.hpp"

namespace ft
{
    template <class T, class Container>
    queue<T, Container>::queue(const container_type& ctnr)
        : m_ctnr(ctnr)
    {
    }

    template <class T, class Container>
    bool queue<T, Container>::empty() const
    {
        return m_ctnr.empty();
    }

    template <class T, class Container>
    typename queue<T, Container>::size_type queue<T, Container>::size() const
    {
        return m_ctnr.size();
    }

    template <class T, class Container>
    typename queue<T, Container>::value_type& queue<T, Container>::front()
    {
        return m_ctnr.front();
    }

    template <class T, class Container>
    const typename queue<T, Container>::value_type& queue<T, Container>::front() const
    {
        return m_ctnr.front();
    }

    template <class T, class Container>
    typename queue<T, Container>::value_type& queue<T, Container>::back()
    {
        return m_ctnr.back();
    }

    template <class T, class Container>
    const typename queue<T, Container>::value_type& queue<T, Container>::back() const
    {
        return m_ctnr.back();
    }

    template <class T, class Container>
    void queue<T, Container>::push(const value_type& val)
    {
        m_ctnr.push_back(val);
    }

    template <class T, class Container>
    void queue<T, Container>::pop()
    {
        m_ctnr.pop_front();
    }

    template <class T, class Container>
    bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs.m_ctnr == rhs.m_ctnr;
    }

    template <class T, class Container>
    bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Container>
    bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs.m_ctnr < rhs.m_ctnr;
    }

    template <class T, class Container>
    bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return !(rhs < lhs);
    }

    template <class T, class Container>
    bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return rhs < lhs;
    }

    template <class T, class Container>
    bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return !(lhs < rhs);
    }
}

#endif //FT_CONTAINERS_QUEUE_IMPL_HPP
