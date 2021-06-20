#include "map_tests.hpp"
#include "tests/util/Dummy.hpp"
#include "containers/map.hpp"
#include <map>

typedef ft::map<ft::Dummy, ft::Dummy> ft_map_t;
typedef std::map<ft::Dummy, ft::Dummy> std_map_t;

void ft::run_map_tests()
{
    std::srand(21);
    map_test_suite<ft_map_t>("ft::map", "results/map_ft_result.txt");
    std::srand(21);
    map_test_suite<std_map_t>("std::map", "results/map_std_result.txt");
}

