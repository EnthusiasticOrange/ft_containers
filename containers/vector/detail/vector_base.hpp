
#ifndef FT_CONTAINERS_VECTOR_BASE_HPP
#define FT_CONTAINERS_VECTOR_BASE_HPP

namespace ft { namespace detail
{
    template<
            class T,
            class Allocator = std::allocator<T>
    > class vector_base
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
        class vector_guard
        {
        private:
            allocator_type&     m_alloc;
            pointer             m_begin;
            pointer             m_end;

        public:
            vector_guard(pointer begin, pointer end, allocator_type& alloc);
            ~vector_guard();

            pointer decBegin();
            pointer incBegin();
            pointer moveEnd();
            void release();
        };

        typedef vector_guard   guard_type;

    protected:
        allocator_type      m_alloc;
        pointer             m_begin;
        pointer             m_end;
        pointer             m_end_cap;

    public:
        explicit vector_base(const allocator_type& alloc = allocator_type());
        ~vector_base();
    };
} }

#include "vector_base_impl.hpp"

#endif //FT_CONTAINERS_VECTOR_BASE_HPP
