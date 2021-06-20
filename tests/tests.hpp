#ifndef FT_CONTAINERS_TESTS_HPP
#define FT_CONTAINERS_TESTS_HPP

#include <ostream>
#include <string>
#include "other/utility.hpp"
#include <utility>

namespace ft
{
    template<class T1, class T2>
    std::ostream& operator<<(std::ostream& out, const ft::pair<T1, T2>& p);

    template<class T1, class T2>
    std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& p);

    void print_header(const std::string& name, std::ostream& out);

    template<class Container>
    void print_const_container(const Container& cont, std::ostream& out);

    template<class Container>
    void print_const_container_reverse(const Container& cont, std::ostream& out);

    template<class Container>
    void test_suite(const std::string& name, std::ostream& out);

    template<class Container>
    void constructor_default(std::ostream& out);

    template<class Container>
    void constructor_fill(std::ostream& out);

    template<class Container>
    void constructor_range(std::ostream& out);

    template<class Container>
    void constructor_copy(std::ostream& out);

    template<class Container>
    void assign_operator(std::ostream& out);

    template<class Container>
    void iterator_bidirectional(std::ostream& out);

    template<class Container>
    void reverse_iterator_bidirectional(std::ostream& out);

    template<class Container>
    void capacity_functions(std::ostream& out);

    template<class Container>
    void modifiers_insert(std::ostream& out);

    template<class Container>
    void modifiers_insert_fill(std::ostream& out);

    template<class Container>
    void modifiers_erase(std::ostream& out);

    template<class Container>
    void modifiers_swap(std::ostream& out);

    template<class Container>
    void modifiers_clear(std::ostream& out);

    template<class Container>
    void modifiers_assign(std::ostream& out);

    template<class Container>
    void modifiers_push_pop_back(std::ostream& out);

    template<class Container>
    void modifiers_resize(std::ostream& out);

    template<class Container>
    void relational_operators(std::ostream& out);
}

#include "tests_impl.hpp"

#endif //FT_CONTAINERS_TESTS_HPP
