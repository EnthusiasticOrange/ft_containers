#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP

#include "other/red_black_tree/rbtree.hpp"
#include "other/functional.hpp"

namespace ft
{
    template <
            class Key,
            class T,
            class Compare = ft::less<Key>,
            class Alloc = std::allocator<ft::pair<const Key,T> >
    > class map
    {
    public:
        typedef Key                                      key_type;
        typedef T                                        mapped_type;
        typedef ft::pair<const key_type, mapped_type>    value_type;
        typedef Compare                                  key_compare;
        typedef Alloc                                    allocator_type;
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;

        class value_compare: public binary_function<value_type, value_type, bool>
        {
            friend class map;
        protected:
            key_compare comp;
            value_compare(key_compare c): comp(c) {}
        public:
            typedef bool        result_type;
            typedef value_type  first_argument_type;
            typedef value_type  second_argument_type;
            bool operator() (const value_type& x, const value_type& y) const
            {
                return comp(x.first, y.first);
            }
        };

    private:
        typedef detail::rbtree<value_type, value_compare, allocator_type>   tree_type;
        typedef map<key_type, mapped_type, key_compare, allocator_type>     this_type;

    public:
        typedef typename tree_type::iterator            iterator;
        typedef typename tree_type::const_iterator      const_iterator;
        typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

    private:
        tree_type m_tree;

    private:
        typedef typename tree_type::node_base_type              node_base_type;
        typedef typename tree_type::node_base_pointer           node_base_pointer;
        typedef typename tree_type::const_node_base_pointer     const_node_base_pointer;
        typedef typename tree_type::node_type                   node_type;
        typedef typename tree_type::node_allocator_type         node_allocator_type;
        typedef typename tree_type::node_pointer                node_pointer;
        typedef typename tree_type::const_node_pointer          const_node_pointer;
        typedef typename tree_type::node_guard_type             node_guard_type;

    private:
        class map_node_guard: public node_guard_type
        {
        protected:
            using node_guard_type::m_node_alloc;
            using node_guard_type::m_node;

        public:
            bool    m_is_first_constructed;
            bool    m_is_second_constructed;

        public:
            map_node_guard(node_allocator_type& node_alloc, node_pointer node);
            ~map_node_guard();

            using node_guard_type::release;
        };

    public:
        explicit map(const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type());
        map(const map& x);
        ~map();

        map& operator=(const map& x);

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

        mapped_type& operator[](const key_type& k);

        pair<iterator,bool> insert(const value_type& val);
        iterator insert(iterator position, const value_type& val);
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last,
                    typename enable_if<!is_arithmetic<InputIterator>::value>::type* = 0);

        void erase(iterator position);
        size_type erase(const key_type& k);
        void erase(iterator first, iterator last);

        void swap(map& x);

        void clear();

        key_compare key_comp() const;
        value_compare value_comp() const;

        iterator        find(const key_type& k);
        const_iterator  find(const key_type& k) const;

        size_type count(const key_type& k) const;

        iterator        lower_bound(const key_type& k);
        const_iterator  lower_bound(const key_type& k) const;

        iterator        upper_bound(const key_type& k);
        const_iterator  upper_bound(const key_type& k) const;

        ft::pair<iterator,iterator>             equal_range(const key_type& k);
        ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const;

        allocator_type get_allocator() const;

    private:
        node_pointer _find_by_key(node_pointer& parent, const key_type& k) const;
        node_pointer _lower_bound(const key_type& k);
        node_pointer _upper_bound(const key_type& k);
        ft::pair<node_pointer, node_pointer> _equal_range(const key_type& k);
    };

    template<class K, class T, class C, class A>
    bool operator==(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs);

    template<class K, class T, class C, class A>
    bool operator!=(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs);

    template<class K, class T, class C, class A>
    bool operator<(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs);

    template<class K, class T, class C, class A>
    bool operator<=(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs);

    template<class K, class T, class C, class A>
    bool operator>(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs);

    template<class K, class T, class C, class A>
    bool operator>=(const map<K, T, C, A>& lhs, const map<K, T, C, A>& rhs);

    template<class K, class T, class C, class A>
    void swap(map<K, T, C, A>& x, map<K, T, C, A>& y);
}

#include "containers/map/map_impl.hpp"

#endif //FT_CONTAINERS_MAP_HPP
