#include "tests/list/list_tests.hpp"
#include "tests/vector/vector_tests.hpp"
#include "tests/map/map_tests.hpp"
#include "tests/stack/stack_tests.hpp"
#include "tests/queue/queue_tests.hpp"

int main()
{
    ft::run_list_tests();
    ft::run_vector_tests();
    ft::run_map_tests();
    ft::run_stack_tests();
    ft::run_queue_tests();
    return 0;
}