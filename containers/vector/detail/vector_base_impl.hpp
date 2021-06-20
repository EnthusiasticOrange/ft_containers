#ifndef FT_CONTAINERS_VECTOR_BASE_IMPL_HPP
#define FT_CONTAINERS_VECTOR_BASE_IMPL_HPP

#include "vector_base.hpp"

namespace ft { namespace detail
{
    template<class T, class Allocator>
    vector_base<T, Allocator>::vector_base(const allocator_type& alloc)
        : m_alloc(alloc)
        , m_begin(NULL), m_end(NULL)
        , m_end_cap(NULL)
    {
    }

    template<class T, class Allocator>
    vector_base<T, Allocator>::~vector_base()
    {
        if (m_begin)
            m_alloc.deallocate(m_begin, m_end_cap - m_begin);
    }

    template<class T, class Allocator>
    vector_base<T, Allocator>::vector_guard::vector_guard(pointer begin, pointer end, allocator_type& alloc)
        : m_alloc(alloc)
        , m_begin(begin), m_end(end)
    {
    }

    template<class T, class Allocator>
    vector_base<T, Allocator>::vector_guard::~vector_guard()
    {
        for (; m_begin != m_end; ++m_begin)
        {
            m_alloc.destroy(m_begin);
        }
    }

    template<class T, class Allocator>
    typename vector_base<T, Allocator>::pointer vector_base<T, Allocator>::vector_guard::decBegin()
    {
        --m_begin;
        return m_begin;
    }

    template<class T, class Allocator>
    typename vector_base<T, Allocator>::pointer vector_base<T, Allocator>::vector_guard::incBegin()
    {
        ++m_begin;
        return m_begin;
    }

    template<class T, class Allocator>
    typename vector_base<T, Allocator>::pointer vector_base<T, Allocator>::vector_guard::moveEnd()
    {
        ++m_end;
        return m_end;
    }

    template<class T, class Allocator>
    void vector_base<T, Allocator>::vector_guard::release()
    {
        m_begin = m_end;
    }
} }

#endif //FT_CONTAINERS_VECTOR_BASE_IMPL_HPP
