#ifndef FT_CONTAINERS_LIST_TESTS_HPP
#define FT_CONTAINERS_LIST_TESTS_HPP

#include "tests/tests.hpp"

namespace ft
{
    void run_list_tests();

    template<class List>
    void list_test_suite(const std::string& name, const std::string& filename);

    template<class List>
    void list_push_pop_front(std::ostream& out);

    template<class List>
    void list_access(std::ostream& out);

    template<class List>
    void list_splice(std::ostream& out);

    template<class List>
    void list_remove(std::ostream& out);

    template<class List>
    void list_unique(std::ostream& out);

    template<class List>
    void list_merge(std::ostream& out);

    template<class List>
    void list_sort(std::ostream& out);

    template<class List>
    void list_reverse(std::ostream& out);
}

#include "list_tests_impl.hpp"

#endif //FT_CONTAINERS_LIST_TESTS_HPP
