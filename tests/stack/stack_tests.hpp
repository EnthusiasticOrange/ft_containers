#ifndef FT_CONTAINERS_STACK_TESTS_HPP
#define FT_CONTAINERS_STACK_TESTS_HPP

#include "tests/tests.hpp"

namespace ft
{
    void run_stack_tests();

    template<class StackList, class StackVec>
    void stack_test_suite(const std::string& name, const std::string& filename);

    template<class Stack>
    void stack_constructor(std::ostream& out);

    template<class Stack>
    void stack_empty(std::ostream& out);

    template<class Stack>
    void stack_size(std::ostream& out);

    template<class Stack>
    void stack_top(std::ostream& out);

    template<class Stack>
    void stack_push(std::ostream& out);

    template<class Stack>
    void stack_pop(std::ostream& out);

    template<class Stack>
    void stack_relational_operators(std::ostream& out);
}

#include "stack_tests_impl.hpp"

#endif //FT_CONTAINERS_STACK_TESTS_HPP
