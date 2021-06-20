#ifndef FT_CONTAINERS_LIST_BASE_HPP
#define FT_CONTAINERS_LIST_BASE_HPP

#include <memory>
#include "list_node.hpp"

namespace ft { namespace detail
{
    template<
            class T,
            class Allocator = std::allocator<T>
    > class list_base
    {
    public:
        typedef T                                           value_type;
        typedef Allocator                                   allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef size_t                                      size_type;
        typedef ptrdiff_t                                   difference_type;

    protected:
        typedef list_node_base                                              node_base_type;
        typedef node_base_type*                                             node_base_pointer;
        typedef const node_base_type*                                       const_node_base_pointer;
        typedef list_node<T>                                                node_type;
        typedef typename allocator_type::template rebind<node_type>::other  node_allocator_type;
        typedef typename node_allocator_type::pointer                       node_pointer;
        typedef typename node_allocator_type::const_pointer                 const_node_pointer;

    protected:
        class list_node_guard
        {
        private:
            node_allocator_type&    m_node_alloc;
            node_pointer            m_node;

        public:
            list_node_guard(node_allocator_type& node_alloc, node_pointer node);
            ~list_node_guard();

            void release();
        };

        typedef list_node_guard   node_guard_type;

    protected:
        node_base_type      m_base;
        allocator_type      m_alloc;
        node_allocator_type m_node_alloc;
        size_t              m_size;

        explicit list_base(const allocator_type& alloc = allocator_type());
        ~list_base();

    protected:
        void _init();
        void _clear();
    };
} }

#include "list_base_impl.hpp"

#endif //FT_CONTAINERS_LIST_BASE_HPP