#ifndef FT_CONTAINERS_VECTOR_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_ITERATOR_HPP

#include "other/iterator.hpp"

namespace ft { namespace detail
{
    template<class T, class Pointer, class Reference>
    struct vector_iterator: public iterator<ft::bidirectional_iterator_tag, T, ptrdiff_t, Pointer, Reference>
    {
        typedef iterator<ft::random_access_iterator_tag, T, ptrdiff_t, Pointer, Reference>  base_type;
        typedef vector_iterator<T, Pointer, Reference>                                      this_type;

        typedef typename base_type::value_type        value_type;
        typedef typename base_type::difference_type   difference_type;
        typedef typename base_type::pointer           pointer;
        typedef typename base_type::reference         reference;
        typedef typename base_type::iterator_category iterator_category;

        typedef vector_iterator<T, T*, T&>              iterator;
        typedef vector_iterator<T, const T*, const T&>  const_iterator;

        pointer m_p;

        vector_iterator();
        vector_iterator(pointer p);
        vector_iterator(const iterator& iter);
        vector_iterator(const const_iterator& iter);
        this_type& operator=(const this_type& other);

        reference operator*() const;
        this_type operator+(difference_type n) const;
        this_type& operator++();
        this_type  operator++(int);
        this_type& operator+=(difference_type n);
        this_type operator-(difference_type n) const;
        this_type& operator--();
        this_type  operator--(int);
        this_type& operator-= (difference_type n);
        pointer operator->() const;
        reference operator[] (difference_type n) const;
    };

    template<class T, class P, class R>
    bool operator==(const vector_iterator<T, P, R>& lhs,
            const vector_iterator<T, P, R>& rhs);

    template<class T, class P, class R>
    bool operator!=(const vector_iterator<T, P, R>& lhs,
            const vector_iterator<T, P, R>& rhs);

    template<class T, class P, class R>
    bool operator<(const vector_iterator<T, P, R>& lhs,
            const vector_iterator<T, P, R>& rhs);

    template<class T, class P, class R>
    bool operator<=(const vector_iterator<T, P, R>& lhs,
            const vector_iterator<T, P, R>& rhs);

    template<class T, class P, class R>
    bool operator>(const vector_iterator<T, P, R>& lhs,
            const vector_iterator<T, P, R>& rhs);

    template<class T, class P, class R>
    bool operator>=(const vector_iterator<T, P, R>& lhs,
            const vector_iterator<T, P, R>& rhs);

    template<class T, class P, class R>
    vector_iterator<T, P, R> operator+(
            typename vector_iterator<T, P, R>::difference_type n,
            const vector_iterator<T, P, R>& it);

    template<class T, class P, class R>
    typename vector_iterator<T, P, R>::difference_type operator-(
            const vector_iterator<T, P, R>& lhs,
            const vector_iterator<T, P, R>& rhs);
} }

#include "vector_iterator_impl.hpp"

#endif //FT_CONTAINERS_VECTOR_ITERATOR_HPP
