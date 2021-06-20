#include "list_node.hpp"

void ft::detail::list_node_base::insert(list_node_base* next)
{
    m_next = next;
    m_prev = next->m_prev;
    next->m_prev->m_next = this;
    next->m_prev = this;
}

void ft::detail::list_node_base::remove()
{
    m_next->m_prev = m_prev;
    m_prev->m_next = m_next;
}

void ft::detail::list_node_base::splice(list_node_base* first, list_node_base* last)
{
    last->m_prev->m_next  = this;
    first->m_prev->m_next = last;
    this->m_prev->m_next  = first;

    list_node_base* temp = this->m_prev;
    this->m_prev  = last->m_prev;
    last->m_prev  = first->m_prev;
    first->m_prev = temp;
}

