#include "queue_tests.hpp"
#include "tests/util/Dummy.hpp"
#include "containers/list.hpp"
#include "containers/vector.hpp"
#include "containers/queue.hpp"
#include <list>
#include <vector>
#include <queue>

typedef ft::queue<ft::Dummy, ft::list<ft::Dummy> >      ft_queue_t;
typedef std::queue<ft::Dummy, std::list<ft::Dummy> >    std_queue_t;

void ft::run_queue_tests()
{
    queue_test_suite<ft_queue_t>("ft::queue", "results/queue_ft_result.txt");
    queue_test_suite<std_queue_t>("std::queue", "results/queue_std_result.txt");
}