#ifndef FT_CONTAINERS_RB_NODE_HPP
#define FT_CONTAINERS_RB_NODE_HPP

namespace ft { namespace detail
{
    struct rb_node_base
    {
        enum color { red, black };

        rb_node_base*   m_right;
        rb_node_base*   m_left;
        rb_node_base*   m_parent;
        color           m_color;
    };

    template <class T>
    struct rb_node: public rb_node_base
    {
        T m_value;
    };

    bool rb_is_left_child(rb_node_base* node);
    bool rb_is_right_child(rb_node_base* node);
    rb_node_base* rb_min(rb_node_base* node);
    rb_node_base* rb_max(rb_node_base* node);
    rb_node_base* rb_next(rb_node_base* node);
    rb_node_base* rb_prev(rb_node_base* node);
} }

#endif //FT_CONTAINERS_RB_NODE_HPP
