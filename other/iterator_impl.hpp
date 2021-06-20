#ifndef FT_CONTAINERS_ITERATOR_IMPL_HPP
#define FT_CONTAINERS_ITERATOR_IMPL_HPP

#include "iterator.hpp"

namespace ft
{
    namespace detail
    {
        template <typename InputIterator>
        typename iterator_traits<InputIterator>::difference_type
        distance_impl(InputIterator first, InputIterator last, input_iterator_tag)
        {
            typename iterator_traits<InputIterator>::difference_type n = 0;

            while(first != last)
            {
                ++first;
                ++n;
            }
            return n;
        }

        template <typename InputIterator>
        typename iterator_traits<InputIterator>::difference_type
        distance_impl(InputIterator first, InputIterator last, random_access_iterator_tag)
        {
            return last - first;
        }

        template<class InputIterator>
        void do_advance(InputIterator& it,
                typename iterator_traits<InputIterator>::difference_type n,
                input_iterator_tag)
        {
            while (n > 0) {
                --n;
                ++it;
            }
        }

        template<class InputIterator>
        void do_advance(InputIterator& it,
                typename iterator_traits<InputIterator>::difference_type n,
                bidirectional_iterator_tag)
        {
            while (n > 0) {
                --n;
                ++it;
            }
            while (n < 0) {
                ++n;
                --it;
            }
        }

        template<class InputIterator>
        void do_advance(InputIterator& it,
                typename iterator_traits<InputIterator>::difference_type n,
                random_access_iterator_tag)
        {
            it += n;
        }
    }

    template<class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
    distance(InputIterator first, InputIterator last)
    {
        return detail::distance_impl(first, last, typename iterator_traits<InputIterator>::iterator_category());
    }

    template<class InputIterator, class Distance>
    void advance(InputIterator& it, Distance n)
    {
        detail::do_advance(it, typename iterator_traits<InputIterator>::difference_type(n),
                typename iterator_traits<InputIterator>::iterator_category());
    }

    template<typename Iterator>
    reverse_iterator<Iterator>::reverse_iterator()
        : m_it()
    {
    }

    template<typename Iterator>
    reverse_iterator<Iterator>::reverse_iterator(iterator_type it)
        : m_it(it)
    {
    }

    template<typename Iterator>
    reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator& rev_it)
            : m_it(rev_it.m_it)
    {
    }

    template<typename Iterator>
    template<class Iter>
    reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& rev_it)
    : m_it(rev_it.base())
    {
    }

    template<typename Iterator>
    typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const
    {
        return m_it;
    }

    template<typename Iterator>
    typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const
    {
        iterator_type it(m_it);
        return *--it;
    }

    template<typename Iterator>
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+(difference_type n) const
    {
        return reverse_iterator(m_it - n);
    }

    template<typename Iterator>
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++()
    {
        --m_it;
        return *this;
    }

    template<typename Iterator>
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int)
    {
        reverse_iterator ri(*this);
        --m_it;
        return ri;
    }

    template<typename Iterator>
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+=(difference_type n)
    {
        m_it -= n;
        return *this;
    }

    template<typename Iterator>
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(difference_type n) const
    {
        return reverse_iterator(m_it + n);
    }

    template<typename Iterator>
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--()
    {
        ++m_it;
        return *this;
    }

    template<typename Iterator>
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int)
    {
        reverse_iterator ri(*this);
        ++m_it;
        return ri;
    }

    template<typename Iterator>
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-=(difference_type n)
    {
        m_it += n;
        return *this;
    }

    template<typename Iterator>
    typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const
    {
        return &(operator*());
    }

    template<typename Iterator>
    typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[](difference_type n) const
    {
        return m_it[-n - 1];
    }

    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() != rhs.base();
    }

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() > rhs.base();
    }

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() >= rhs.base();
    }

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() < rhs.base();
    }

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() <= rhs.base();
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+(
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it)
    {
        return reverse_iterator<Iterator>(rev_it.base() - n);
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(
            const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
    {
        return rhs.base() - lhs.base();
    }
}

#endif //FT_CONTAINERS_ITERATOR_IMPL_HPP
