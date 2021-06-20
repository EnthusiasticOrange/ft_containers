#include "list_tests.hpp"
#include "tests/util/Dummy.hpp"
#include "containers/list.hpp"
#include <list>

typedef ft::list<ft::Dummy> ft_list_t;
typedef std::list<ft::Dummy> std_list_t;

void ft::run_list_tests()
{
    list_test_suite<ft_list_t>("ft::list", "results/list_ft_result.txt");
    list_test_suite<std_list_t>("std::list", "results/list_std_result.txt");
}