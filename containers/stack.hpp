#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include "list.hpp"

namespace ft
{
    template <
             class T,
             class Container = ft::list<T>
    > class stack
    {
    public:
        typedef Container                               container_type;
        typedef typename container_type::value_type     value_type;
        typedef typename container_type::size_type      size_type;

    protected:
        container_type m_ctnr;

    public:
        explicit stack(const container_type& ctnr = container_type());

        bool empty() const;
        size_type size() const;

        value_type&         top();
        const value_type&   top() const;

        void push(const value_type& val);
        void pop();

        template <class T1, class C1>
        friend
        bool operator==(const stack<T1,C1>& lhs, const stack<T1,C1>& rhs);

        template <class T1, class C1>
        friend
        bool operator<(const stack<T1,C1>& lhs, const stack<T1,C1>& rhs);
    };

    template <class T, class Container>
    bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

    template <class T, class Container>
    bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

    template <class T, class Container>
    bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

    template <class T, class Container>
    bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

    template <class T, class Container>
    bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

    template <class T, class Container>
    bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
}

#include "stack/stack_impl.hpp"

#endif //FT_CONTAINERS_STACK_HPP
