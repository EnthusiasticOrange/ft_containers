#include "stack_tests.hpp"
#include "tests/util/Dummy.hpp"
#include "containers/list.hpp"
#include "containers/vector.hpp"
#include "containers/stack.hpp"
#include <list>
#include <vector>
#include <stack>

typedef ft::stack<ft::Dummy, ft::list<ft::Dummy> >      ft_stack_list_t;
typedef ft::stack<ft::Dummy, ft::vector<ft::Dummy> >    ft_stack_vec_t;
typedef std::stack<ft::Dummy, std::list<ft::Dummy> >    std_stack_list_t;
typedef std::stack<ft::Dummy, std::vector<ft::Dummy> >  std_stack_vec_t;


void ft::run_stack_tests()
{
    stack_test_suite<ft_stack_list_t, ft_stack_vec_t>("ft::stack", "results/stack_ft_result.txt");
    stack_test_suite<std_stack_list_t, std_stack_vec_t>("std::stack", "results/stack_std_result.txt");
}