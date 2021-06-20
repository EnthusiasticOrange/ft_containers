#ifndef FT_CONTAINERS_VECTOR_TESTS_HPP
#define FT_CONTAINERS_VECTOR_TESTS_HPP

#include "tests/tests.hpp"

namespace ft
{
    void run_vector_tests();

    template<class Vec>
    void vector_test_suite(const std::string& name, const std::string& filename);

    template<class Vec>
    void vec_resize(std::ostream& out);

    template<class Vec>
    void vec_capacity(std::ostream& out);

    template<class Vec>
    void vec_reserve(std::ostream& out);

    template<class Vec>
    void vec_access(std::ostream& out);

    template<class Vec>
    void vec_random_access_iterators(std::ostream& out);

    template<class Vec>
    void vec_random_access_reverse_iterators(std::ostream& out);
}

#include "vector_tests_impl.hpp"

#endif //FT_CONTAINERS_VECTOR_TESTS_HPP
