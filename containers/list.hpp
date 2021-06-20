#ifndef FT_CONTAINERS_LIST_HPP
#define FT_CONTAINERS_LIST_HPP

#include "other/iterator.hpp"
#include "other/type_traits.hpp"
#include "other/algorithm.hpp"
#include "containers/list/detail/list_base.hpp"
#include "containers/list/detail/list_iterator.hpp"

namespace ft
{
    template<
            class T,
            class Allocator = std::allocator<T>
    > class list: private detail::list_base<T, Allocator>
    {
    private:
        typedef detail::list_base<T, Allocator>                 base_type;
        typedef list<T, Allocator>                              this_type;

    public:
        typedef typename base_type::value_type                  value_type;
        typedef typename base_type::allocator_type              allocator_type;
        typedef typename base_type::reference                   reference;
        typedef typename base_type::const_reference             const_reference;
        typedef typename base_type::pointer                     pointer;
        typedef typename base_type::const_pointer               const_pointer;
        typedef detail::list_iterator<T, T*, T&>                iterator;
        typedef detail::list_iterator<T, const T*, const T&>    const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
        typedef typename base_type::size_type                   size_type;
        typedef typename base_type::difference_type             difference_type;

    protected:
        typedef typename base_type::node_base_type              node_base_type;
        typedef typename base_type::node_base_pointer           node_base_pointer;
        typedef typename base_type::const_node_base_pointer     const_node_base_pointer;
        typedef typename base_type::node_type                   node_type;
        typedef typename base_type::node_allocator_type         node_allocator_type;
        typedef typename base_type::node_pointer                node_pointer;
        typedef typename base_type::const_node_pointer          const_node_pointer;
        typedef typename base_type::node_guard_type             node_guard_type;

    protected:
        using base_type::m_base;
        using base_type::m_alloc;
        using base_type::m_node_alloc;
        using base_type::m_size;

        using base_type::_init;
        using base_type::_clear;

    public:
        explicit list(const allocator_type& alloc = allocator_type());
        explicit list(size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        list(InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type(),
                typename enable_if<!is_arithmetic<InputIterator>::value>::type* = 0);
        list(const list& x);
        ~list();

        list& operator=(const list& x);

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

        reference       front();
        const_reference front() const;

        reference       back();
        const_reference back() const;

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                typename enable_if<!is_arithmetic<InputIterator>::value>::type* = 0);
        void assign(size_type n, const value_type& val);

        void push_front(const value_type& val);
        void pop_front();

        void push_back(const value_type& val);
        void pop_back();

        iterator insert(iterator position, const value_type& val);
        void insert(iterator position, size_type n, const value_type& val);
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename enable_if<!is_arithmetic<InputIterator>::value>::type* = 0);

        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);

        void swap(list& x);

        void resize(size_type n, value_type val = value_type());

        void clear();

        void splice(iterator position, list& x);
        void splice(iterator position, list& x, iterator i);
        void splice(iterator position, list& x, iterator first, iterator last);

        void remove(const value_type& val);

        template <class Predicate>
        void remove_if(Predicate pred);

        void unique();
        template <class BinaryPredicate>
        void unique(BinaryPredicate binary_pred);

        void merge(list& x);
        template <class Compare>
        void merge(list& x, Compare comp);

        void sort();
        template <class Compare>
        void sort(Compare comp);

        void reverse();

        allocator_type get_allocator() const;

    private:
        node_pointer _allocate_node();
        node_pointer _create_node(const value_type& val);
        template <class InputIterator>
        void _insert_iter(node_base_pointer p, InputIterator first, InputIterator last);
        void _insert(node_base_pointer p, size_type n, const value_type& val);
        void _insert_value(node_base_pointer p, const value_type& val);
        void _erase(node_pointer node);
        template <class Compare>
        iterator _merge_sort(iterator first, iterator last, size_type size, Compare& comp);
    };

    template <class T, class Alloc>
    bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

    template <class T, class Alloc>
    void swap(list<T,Alloc>& x, list<T,Alloc>& y);
}

#include "containers/list/list_impl.hpp"

#endif //FT_CONTAINERS_LIST_HPP