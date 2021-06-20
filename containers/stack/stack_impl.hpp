#ifndef FT_CONTAINERS_STACK_IMPL_HPP
#define FT_CONTAINERS_STACK_IMPL_HPP

#include "containers/stack.hpp"

namespace ft
{
    template <class T, class Container>
    stack<T, Container>::stack(const container_type& ctnr)
        : m_ctnr(ctnr)
    {
    }

    template <class T, class Container>
    bool stack<T, Container>::empty() const
    {
        return m_ctnr.empty();
    }

    template <class T, class Container>
    typename stack<T, Container>::size_type stack<T, Container>::size() const
    {
        return m_ctnr.size();
    }

    template <class T, class Container>
    typename stack<T, Container>::value_type& stack<T, Container>::top()
    {
        return m_ctnr.back();
    }

    template <class T, class Container>
    const typename stack<T, Container>::value_type& stack<T, Container>::top() const
    {
        return m_ctnr.back();
    }

    template <class T, class Container>
    void stack<T, Container>::push(const value_type& val)
    {
        m_ctnr.push_back(val);
    }

    template <class T, class Container>
    void stack<T, Container>::pop()
    {
        m_ctnr.pop_back();
    }

    template <class T, class Container>
    bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs.m_ctnr == rhs.m_ctnr;
    }

    template <class T, class Container>
    bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Container>
    bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs.m_ctnr < rhs.m_ctnr;
    }

    template <class T, class Container>
    bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return !(rhs < lhs);
    }

    template <class T, class Container>
    bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return rhs < lhs;
    }

    template <class T, class Container>
    bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return !(lhs < rhs);
    }
}

#endif //FT_CONTAINERS_STACK_IMPL_HPP
