#ifndef FT_CONTAINERS_QUEUE_HPP
#define FT_CONTAINERS_QUEUE_HPP

#include "list.hpp"

namespace ft
{
    template <
             class T,
             class Container = ft::list<T>
    > class queue
    {
    public:
        typedef Container                               container_type;
        typedef typename container_type::value_type     value_type;
        typedef typename container_type::size_type      size_type;

    protected:
        container_type m_ctnr;

    public:
        explicit queue(const container_type& ctnr = container_type());

        bool empty() const;
        size_type size() const;

        value_type&         front();
        const value_type&   front() const;

        value_type&         back();
        const value_type&   back() const;

        void push(const value_type& val);
        void pop();

        template <class T1, class C1>
        friend
        bool operator==(const queue<T1,C1>& lhs, const queue<T1,C1>& rhs);

        template <class T1, class C1>
        friend
        bool operator<(const queue<T1,C1>& lhs, const queue<T1,C1>& rhs);
    };

    template <class T, class Container>
    bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs);

    template <class T, class Container>
    bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs);

    template <class T, class Container>
    bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs);

    template <class T, class Container>
    bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs);

    template <class T, class Container>
    bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs);

    template <class T, class Container>
    bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs);
}

#include "queue/queue_impl.hpp"

#endif //FT_CONTAINERS_QUEUE_HPP
