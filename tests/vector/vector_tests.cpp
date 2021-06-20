#include "vector_tests.hpp"
#include "tests/util/Dummy.hpp"
#include "containers/vector.hpp"
#include <vector>

typedef ft::vector<ft::Dummy> ft_vector_t;
typedef std::vector<ft::Dummy> std_vector_t;

void ft::run_vector_tests()
{
    vector_test_suite<ft_vector_t>("ft::vector", "results/vector_ft_result.txt");
    vector_test_suite<std_vector_t>("std::vector", "results/vector_std_result.txt");
}
