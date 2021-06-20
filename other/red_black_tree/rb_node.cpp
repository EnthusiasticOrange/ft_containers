#include "rb_node.hpp"

bool ft::detail::rb_is_left_child(rb_node_base* node)
{
    return node == node->m_parent->m_left;
}

bool ft::detail::rb_is_right_child(rb_node_base* node)
{
    return node == node->m_parent->m_right;
}

ft::detail::rb_node_base* ft::detail::rb_min(rb_node_base* node)
{
    while (node->m_left)
        node = node->m_left;
    return node;
}

ft::detail::rb_node_base* ft::detail::rb_max(rb_node_base* node)
{
    while (node->m_right)
        node = node->m_right;
    return node;
}

ft::detail::rb_node_base* ft::detail::rb_next(rb_node_base* node)
{
    if (node->m_right)
        return rb_min(node->m_right);
    while (rb_is_right_child(node))
        node = node->m_parent;
    if (node->m_right != node->m_parent)
        node = node->m_parent;
    return node;
}

ft::detail::rb_node_base* ft::detail::rb_prev(rb_node_base* node)
{
    if (node->m_parent->m_parent == node && node->m_color == rb_node_base::red)
        return node->m_right;
    if (node->m_left)
        return rb_max(node->m_left);
    while (rb_is_left_child(node))
        node = node->m_parent;
    return node->m_parent;
}
