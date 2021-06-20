#ifndef FT_CONTAINERS_RBTREE_HPP
#define FT_CONTAINERS_RBTREE_HPP
#include <iostream>
#include "other/algorithm.hpp"
#include "rbtree_base.hpp"
#include "rb_iterator.hpp"

namespace ft { namespace detail
{
    template <
            class Value,
            class Compare,
            class Allocator
    > class rbtree: private rbtree_base<Value, Compare, Allocator>
    {
    private:
        typedef rbtree_base<Value, Compare, Allocator>     base_type;
        typedef rbtree<Value, Compare, Allocator>          this_type;

    public:
        typedef typename base_type::value_type                              value_type;
        typedef typename base_type::value_compare                           value_compare;
        typedef typename base_type::allocator_type                          allocator_type;
        typedef typename base_type::reference                               reference;
        typedef typename base_type::const_reference                         const_reference;
        typedef typename base_type::pointer                                 pointer;
        typedef typename base_type::const_pointer                           const_pointer;
        typedef rb_iterator<value_type, pointer, reference>                 iterator;
        typedef rb_iterator<value_type, const_pointer, const_reference>     const_iterator;
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;
        typedef typename base_type::size_type                               size_type;
        typedef typename base_type::difference_type                         difference_type;

    public:
        typedef typename base_type::node_base_type              node_base_type;
        typedef typename base_type::node_base_pointer           node_base_pointer;
        typedef typename base_type::const_node_base_pointer     const_node_base_pointer;
        typedef typename base_type::node_type                   node_type;
        typedef typename base_type::node_allocator_type         node_allocator_type;
        typedef typename base_type::node_pointer                node_pointer;
        typedef typename base_type::const_node_pointer          const_node_pointer;
        typedef typename base_type::node_guard_type             node_guard_type;

    public:
        using base_type::m_alloc;
        using base_type::m_node_alloc;
        using base_type::m_comp;
        using base_type::m_size;
        using base_type::m_base;

        using base_type::_init;
        using base_type::_free_node;
        using base_type::_free_subtree;

    public:
        explicit rbtree(const value_compare& comp,
                const allocator_type& alloc);
        rbtree(const rbtree& x);

        iterator        begin();
        const_iterator  begin() const;
        iterator        end();
        const_iterator  end() const;

        reverse_iterator        rbegin();
        const_reverse_iterator  rbegin() const;
        reverse_iterator        rend();
        const_reverse_iterator  rend() const;

        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        pair<iterator, bool> insert(const_reference val);
        iterator insert(iterator hint, const_reference val);
        void erase(iterator position);

        iterator        find(const_reference val);
        const_iterator  find(const_reference val) const;

        void swap(this_type& x);

        void clear();

        value_compare value_comp() const;

        iterator        lower_bound(const value_type& val);
        const_iterator  lower_bound(const value_type& val) const;

        iterator        upper_bound(const value_type& val);
        const_iterator  upper_bound(const value_type& val) const;

        ft::pair<iterator,iterator>             equal_range(const value_type& val);
        ft::pair<const_iterator,const_iterator> equal_range(const value_type& val) const;

    public:
        node_pointer _allocate_node();
        node_pointer _create_node(const_reference val);
        node_pointer _create_and_insert(node_pointer parent, const_reference val);
        node_pointer _find(node_pointer& parent, const_reference val) const;
        void _rotate_left(node_base_pointer node);
        void _rotate_right(node_base_pointer node);
        void _insert_node(node_pointer parent, node_pointer node);
        void _balance_after_insert(node_base_pointer node);
        void _remove_node(node_base_pointer node);

    public:
        void debug_print() const;
        bool is_balanced() const;
    private:
        int _max_depth(node_base_pointer p) const;
        int _min_depth(node_base_pointer p) const;
    };
} }

#include "rbtree_impl.hpp"

#endif //FT_CONTAINERS_RBTREE_HPP
