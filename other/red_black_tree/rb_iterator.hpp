#ifndef FT_CONTAINERS_RB_ITERATOR_HPP
#define FT_CONTAINERS_RB_ITERATOR_HPP

#include "other/iterator.hpp"
#include "rb_node.hpp"

namespace ft { namespace detail
{
    template<class T, class Pointer, class Reference>
    struct rb_iterator: public ft::iterator<bidirectional_iterator_tag, T, ptrdiff_t, Pointer, Reference>
    {
        typedef ft::iterator<bidirectional_iterator_tag, T, ptrdiff_t, Pointer, Reference>  base_type;
        typedef rb_iterator<T, Pointer, Reference>                                          this_type;

        typedef typename base_type::value_type        value_type;
        typedef typename base_type::difference_type   difference_type;
        typedef typename base_type::pointer           pointer;
        typedef typename base_type::reference         reference;
        typedef typename base_type::iterator_category iterator_category;

        typedef rb_node<T>    node_type;

        typedef rb_iterator<T, T*, T&>              iterator;
        typedef rb_iterator<T, const T*, const T&>  const_iterator;

        node_type* m_node;

        rb_iterator();
        rb_iterator(node_type* node);
        rb_iterator(const iterator& iter);
        rb_iterator(const const_iterator& iter);
        this_type& operator=(const iterator& other);
        this_type& operator=(const const_iterator& other);

        reference   operator*() const;
        pointer     operator->() const;

        this_type&  operator++();
        this_type   operator++(int);
        this_type&  operator--();
        this_type   operator--(int);

        bool operator==(const this_type& other);
        bool operator!=(const this_type& other);
    };
} }

#include "rb_iterator_impl.hpp"

#endif //FT_CONTAINERS_RB_ITERATOR_HPP
