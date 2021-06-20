#ifndef FT_CONTAINERS_LIST_ITERATOR_HPP
#define FT_CONTAINERS_LIST_ITERATOR_HPP

#include "other/iterator.hpp"
#include "list_base.hpp"
#include "list_node.hpp"

namespace ft { namespace detail
{
    template<class T, class Pointer, class Reference>
    struct list_iterator: public iterator<bidirectional_iterator_tag, T, ptrdiff_t, Pointer, Reference>
    {
        typedef iterator<bidirectional_iterator_tag, T, ptrdiff_t, Pointer, Reference>  base_type;
        typedef list_iterator<T, Pointer, Reference>                                    this_type;

        typedef typename base_type::value_type        value_type;
        typedef typename base_type::difference_type   difference_type;
        typedef typename base_type::pointer           pointer;
        typedef typename base_type::reference         reference;
        typedef typename base_type::iterator_category iterator_category;

        typedef list_iterator<T, T*, T&>              iterator;
        typedef list_iterator<T, const T*, const T&>  const_iterator;

        typedef list_node<T>    node_type;

        node_type* m_node;

        list_iterator();
        list_iterator(node_type* node);
        list_iterator(const iterator & other);
        list_iterator(const const_iterator& other);
        this_type& operator=(const this_type& other);

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

#include "list_iterator_impl.hpp"

#endif //FT_CONTAINERS_LIST_ITERATOR_HPP