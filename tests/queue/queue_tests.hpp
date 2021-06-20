#ifndef FT_CONTAINERS_QUEUE_TESTS_HPP
#define FT_CONTAINERS_QUEUE_TESTS_HPP

#include "tests/tests.hpp"

namespace ft
{
    void run_queue_tests();

    template<class Queue>
    void queue_test_suite(const std::string& name, const std::string& filename);

    template<class Queue>
    void queue_constructor(std::ostream& out);

    template<class Queue>
    void queue_empty(std::ostream& out);

    template<class Queue>
    void queue_size(std::ostream& out);

    template<class Queue>
    void queue_front(std::ostream& out);

    template<class Queue>
    void queue_back(std::ostream& out);

    template<class Queue>
    void queue_push(std::ostream& out);

    template<class Queue>
    void queue_pop(std::ostream& out);

    template<class Queue>
    void queue_relational_operators(std::ostream& out);
}

#include "queue_tests_impl.hpp"

#endif //FT_CONTAINERS_QUEUE_TESTS_HPP
