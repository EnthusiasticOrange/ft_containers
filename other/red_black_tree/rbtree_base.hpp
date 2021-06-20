#ifndef FT_CONTAINERS_RBTREE_BASE_HPP
#define FT_CONTAINERS_RBTREE_BASE_HPP

#include <memory>
#include "rb_node.hpp"

namespace ft { namespace detail
{
    template <
            class Value,
            class Compare,
            class Allocator
    > class rbtree_base
    {
    public:
        typedef Value                                       value_type;
        typedef Compare                                     value_compare;
        typedef Allocator                                   allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef size_t                                      size_type;
        typedef ptrdiff_t                                   difference_type;

    protected:
        typedef rb_node_base                                                node_base_type;
        typedef node_base_type*                                             node_base_pointer;
        typedef const node_base_type*                                       const_node_base_pointer;
        typedef rb_node<value_type>                                         node_type;
        typedef typename allocator_type::template rebind<node_type>::other  node_allocator_type;
        typedef typename node_allocator_type::pointer                       node_pointer;
        typedef typename node_allocator_type::const_pointer                 const_node_pointer;

    protected:
        class rb_node_guard
        {
        protected:
            node_allocator_type&    m_node_alloc;
            node_pointer            m_node;

        public:
            rb_node_guard(node_allocator_type& node_alloc, node_pointer node);
            ~rb_node_guard();

            void release();
        };

        typedef rb_node_guard   node_guard_type;

    protected:
        allocator_type      m_alloc;
        node_allocator_type m_node_alloc;
        value_compare       m_comp;
        size_type           m_size;
        node_base_type      m_base;

         explicit rbtree_base(const value_compare& comp = value_compare(),
                 const allocator_type& alloc = allocator_type());
        ~rbtree_base();

    protected:
        void _init();
        void _free_node(node_pointer node);
        void _free_subtree(node_pointer node);
    };
} }

#include "rbtree_base_impl.hpp"

#endif //FT_CONTAINERS_RBTREE_BASE_HPP
