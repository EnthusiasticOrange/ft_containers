#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include "other/iterator.hpp"
#include "other/type_traits.hpp"
#include "other/algorithm.hpp"
#include "containers/vector/detail/vector_base.hpp"
#include "containers/vector/detail/vector_iterator.hpp"

namespace ft
{
    template<
            class T,
            class Allocator = std::allocator<T>
    > class vector: private detail::vector_base<T, Allocator>
    {
    private:
        typedef detail::vector_base<T, Allocator>               base_type;
        typedef vector<T, Allocator>                            this_type;

    public:
        typedef typename base_type::value_type                  value_type;
        typedef typename base_type::allocator_type              allocator_type;
        typedef typename base_type::reference                   reference;
        typedef typename base_type::const_reference             const_reference;
        typedef typename base_type::pointer                     pointer;
        typedef typename base_type::const_pointer               const_pointer;
        typedef detail::vector_iterator<T, T*, T&>              iterator;
        typedef detail::vector_iterator<T, const T*, const T&>  const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
        typedef typename base_type::size_type                   size_type;
        typedef typename base_type::difference_type             difference_type;

    protected:
        typedef typename base_type::guard_type                  guard_type;

    protected:
        using base_type::m_alloc;
        using base_type::m_begin;
        using base_type::m_end;
        using base_type::m_end_cap;

    public:
        explicit vector(const allocator_type& alloc = allocator_type());
        explicit vector(size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        vector(InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type(),
                typename enable_if<!is_arithmetic<InputIterator>::value>::type* = 0);
        vector(const vector& x);
        ~vector();

        vector& operator=(const vector& x);

        iterator        begin();
        const_iterator  begin() const;
        iterator        end();
        const_iterator  end() const;

        reverse_iterator        rbegin();
        const_reverse_iterator  rbegin() const;
        reverse_iterator        rend();
        const_reverse_iterator  rend() const;

        size_type size() const;
        size_type max_size() const;
        void resize(size_type n, value_type val = value_type());
        size_type capacity() const;
        bool empty() const;
        void reserve(size_type n);

        reference       operator[] (size_type n);
        const_reference operator[] (size_type n) const;
        reference       at(size_type n);
        const_reference at(size_type n) const;
        reference       front();
        const_reference front() const;
        reference       back();
        const_reference back() const;

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                typename enable_if<!is_arithmetic<InputIterator>::value>::type* = 0);
        void assign(size_type n, const value_type& val);
        void push_back(const value_type& val);
        void pop_back();
        iterator insert(iterator position, const value_type& val);
        void insert(iterator position, size_type n, const value_type& val);
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename enable_if<!is_arithmetic<InputIterator>::value>::type* = 0);
        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);
        void swap(vector& x);
        void clear();

        allocator_type get_allocator() const;

    private:
        size_type _get_new_capacity(size_type new_size);
        void _reserve_empty(size_t n);
        void _construct_at_end(size_type n, const_reference val);
        template <class InputIterator>
        void _construct_at_end(InputIterator first, InputIterator last,
                typename enable_if<!is_arithmetic<InputIterator>::value>::type* = 0);
        void _destruct_at_end(pointer new_end);
        void _append(size_t n, const_reference val);
        template <class InputIterator>
        void _assign_from_iter(InputIterator first, InputIterator last, ft::false_type);
        template <class ForwardIterator>
        void _assign_from_iter(ForwardIterator first, ForwardIterator last, ft::true_type);
        void _insert_value(iterator position, size_t n, const_reference val);
        void _insert_realloc(iterator position, size_t n, const_reference val);
        template <class InputIterator>
        void _insert_from_iter(iterator position, InputIterator first, InputIterator last, ft::false_type);
        template <class ForwardIterator>
        void _insert_from_iter(iterator position, ForwardIterator first, ForwardIterator last, ft::true_type);
        template <class ForwardIterator>
        void _insert_realloc_from_iter(iterator position, size_t n, ForwardIterator first, ForwardIterator last);
        template <class ForwardIterator>
        void _insert_value_from_iter(iterator position, size_t n, ForwardIterator first, ForwardIterator last);
    };

    template <class T, class Alloc>
    bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    void swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#include "containers/vector/vector_impl.hpp"

#endif //FT_CONTAINERS_VECTOR_HPP
