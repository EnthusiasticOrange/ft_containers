#ifndef FT_CONTAINERS_VECTOR_ITERATOR_IMPL_HPP
#define FT_CONTAINERS_VECTOR_ITERATOR_IMPL_HPP

namespace ft { namespace detail
{
    template<class T, class P, class R>
    vector_iterator<T, P, R>::vector_iterator()
        : m_p()
    {
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R>::vector_iterator(pointer p)
            : m_p(p)
    {
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R>::vector_iterator(const iterator& other)
        : m_p(other.m_p)
    {
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R>::vector_iterator(const const_iterator& other)
        : m_p(other.m_p)
    {
    }

    template<class T, class P, class R>
    typename vector_iterator<T, P, R>::this_type&
    vector_iterator<T, P, R>::operator=(const this_type& other)
    {
        if (this != &other)
            m_p = other.m_p;
        return *this;
    }

    template<class T, class P, class R>
    typename vector_iterator<T, P, R>::reference vector_iterator<T, P, R>::operator*() const
    {
        return *m_p;
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R> vector_iterator<T, P, R>::operator+(difference_type n) const
    {
        this_type it(*this);
        it += n;
        return it;
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R>& vector_iterator<T, P, R>::operator++()
    {
        ++m_p;
        return *this;
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R> vector_iterator<T, P, R>::operator++(int)
    {
        this_type it(*this);
        ++m_p;
        return it;
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R>& vector_iterator<T, P, R>::operator+=(difference_type n)
    {
        m_p += n;
        return *this;
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R> vector_iterator<T, P, R>::operator-(difference_type n) const
    {
        this_type it(*this);
        it -= n;
        return it;
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R>& vector_iterator<T, P, R>::operator--()
    {
        --m_p;
        return *this;
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R> vector_iterator<T, P, R>::operator--(int)
    {
        this_type it(*this);
        --m_p;
        return it;
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R>& vector_iterator<T, P, R>::operator-=(difference_type n)
    {
        m_p -= n;
        return *this;
    }

    template<class T, class P, class R>
    typename vector_iterator<T, P, R>::pointer vector_iterator<T, P, R>::operator->() const
    {
        return &(operator*());
    }

    template<class T, class P, class R>
    typename vector_iterator<T, P, R>::reference vector_iterator<T, P, R>::operator[](difference_type n) const
    {
        return m_p[n];
    }

    template<class T, class P, class R>
    bool operator==(const vector_iterator<T, P, R>& lhs, const vector_iterator<T, P, R>& rhs)
    {
        return lhs.m_p == rhs.m_p;
    }

    template<class T, class P, class R>
    bool operator!=(const vector_iterator<T, P, R>& lhs, const vector_iterator<T, P, R>& rhs)
    {
        return lhs.m_p != rhs.m_p;
    }

    template<class T, class P, class R>
    bool operator<(const vector_iterator<T, P, R>& lhs, const vector_iterator<T, P, R>& rhs)
    {
        return lhs.m_p < rhs.m_p;
    }

    template<class T, class P, class R>
    bool operator<=(const vector_iterator<T, P, R>& lhs, const vector_iterator<T, P, R>& rhs)
    {
        return lhs.m_p <= rhs.m_p;
    }

    template<class T, class P, class R>
    bool operator>(const vector_iterator<T, P, R>& lhs, const vector_iterator<T, P, R>& rhs)
    {
        return lhs.m_p > rhs.m_p;
    }

    template<class T, class P, class R>
    bool operator>=(const vector_iterator<T, P, R>& lhs, const vector_iterator<T, P, R>& rhs)
    {
        return lhs.m_p >= rhs.m_p;
    }

    template<class T, class P, class R>
    vector_iterator<T, P, R> operator+(typename vector_iterator<T, P, R>::difference_type n,
            const vector_iterator<T, P, R>& it)
    {
        return it.m_p + n;
    }

    template<class T, class P, class R>
    typename vector_iterator<T, P, R>::difference_type operator-(
            const vector_iterator<T, P, R>& lhs,
            const vector_iterator<T, P, R>& rhs)
    {
        return lhs.m_p - rhs.m_p;
    }
} }

#endif //FT_CONTAINERS_VECTOR_ITERATOR_IMPL_HPP
