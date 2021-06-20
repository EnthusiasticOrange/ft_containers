#ifndef FT_CONTAINERS_LIST_NODE_HPP
#define FT_CONTAINERS_LIST_NODE_HPP

namespace ft { namespace detail
{
    struct list_node_base
    {
        list_node_base*  m_prev;
        list_node_base*  m_next;

        void insert(list_node_base* next);
        void remove();
        void splice(list_node_base* first, list_node_base* last);
    };

    template<class T>
    struct list_node: public list_node_base
    {
        T m_value;
    };
} }

#endif //FT_CONTAINERS_LIST_NODE_HPP
