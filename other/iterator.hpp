#ifndef FT_CONTAINERS_ITERATOR_HPP
#define FT_CONTAINERS_ITERATOR_HPP

#include <memory>
#include "type_traits.hpp"

namespace ft
{
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag: public input_iterator_tag{};
    struct bidirectional_iterator_tag: public forward_iterator_tag {};
    struct random_access_iterator_tag: public  bidirectional_iterator_tag{};

    template <class Category, class T, class Distance = std::ptrdiff_t,
            class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };

    template <typename Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
    };

    template <typename T>
    struct iterator_traits<T*>
    {
        typedef random_access_iterator_tag  iterator_category;
        typedef T                           value_type;
        typedef std::ptrdiff_t              difference_type;
        typedef T*                          pointer;
        typedef T&                          reference;
    };

    template <typename T>
    struct iterator_traits<const T*>
    {
        typedef random_access_iterator_tag  iterator_category;
        typedef T                           value_type;
        typedef std::ptrdiff_t              difference_type;
        typedef const T*                    pointer;
        typedef const T&                    reference;
    };

    template<class InputIterator>
        typename iterator_traits<InputIterator>::difference_type
            distance(InputIterator first, InputIterator last);

    template <typename InputIterator>
        typename iterator_traits<InputIterator>::difference_type
            distance_impl(InputIterator first, InputIterator last, input_iterator_tag);

    template <typename InputIterator>
        typename iterator_traits<InputIterator>::difference_type
            distance_impl(InputIterator first, InputIterator last, random_access_iterator_tag);

    template <typename Iterator>
    class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
                                             typename iterator_traits<Iterator>::value_type,
                                             typename iterator_traits<Iterator>::difference_type,
                                             typename iterator_traits<Iterator>::pointer,
                                             typename iterator_traits<Iterator>::reference>
    {
    public:
        typedef Iterator                                            iterator_type;
        typedef typename iterator_traits<Iterator>::pointer         pointer;
        typedef typename iterator_traits<Iterator>::reference       reference;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;

    protected:
        iterator_type m_it;

    public:
        reverse_iterator();
        explicit reverse_iterator (iterator_type it);
        reverse_iterator(const reverse_iterator& rev_it);
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter>& rev_it);

        iterator_type base() const;

        reference operator*() const;
        reverse_iterator operator+(difference_type n) const;
        reverse_iterator& operator++();
        reverse_iterator  operator++(int);
        reverse_iterator& operator+=(difference_type n);
        reverse_iterator operator-(difference_type n) const;
        reverse_iterator& operator--();
        reverse_iterator  operator--(int);
        reverse_iterator& operator-= (difference_type n);
        pointer operator->() const;
        reference operator[] (difference_type n) const;
    };

    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs);

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs);

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs);

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs);

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs);

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs);

    template <class Iterator>
    reverse_iterator<Iterator> operator+(
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it);

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(
            const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs);
}

#include "iterator_impl.hpp"

#endif //FT_CONTAINERS_ITERATOR_HPP
