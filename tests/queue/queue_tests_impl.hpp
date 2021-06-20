#ifndef FT_CONTAINERS_QUEUE_TESTS_IMPL_HPP
#define FT_CONTAINERS_QUEUE_TESTS_IMPL_HPP

#include "tests/util/Dummy.hpp"
#include <iostream>
#include <fstream>

namespace ft
{
    template<class Queue>
    void queue_test_suite(const std::string& name, const std::string& filename)
    {
        std::ofstream out(filename.c_str());

        ft::Dummy::out = &out;

        print_header(name + "(list)", out);
        queue_constructor<Queue>(out);
        out << std::endl;
        queue_empty<Queue>(out);
        out << std::endl;
        queue_size<Queue>(out);
        out << std::endl;
        queue_front<Queue>(out);
        out << std::endl;
        queue_back<Queue>(out);
        out << std::endl;
        queue_push<Queue>(out);
        out << std::endl;
        queue_pop<Queue>(out);
        out << std::endl;
        queue_relational_operators<Queue>(out);
        out << std::endl;
    }

    template<class Queue>
    void queue_constructor(std::ostream& out)
    {
        out << "=====                   =====" << std::endl;
        out << "===== queue constructor =====" << std::endl;
        out << "=====                   =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Queue::container_type cont(3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ queue start ~~~" << std::endl;
            {
                Queue queue(cont);
            }
            out << "~~~ queue end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Queue>
    void queue_empty(std::ostream& out)
    {
        out << "=====             =====" << std::endl;
        out << "===== queue empty =====" << std::endl;
        out << "=====             =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Queue::container_type cont(3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ non empty queue start ~~~" << std::endl;
            {
                Queue queue(cont);
                out << std::endl;

                out << "empty(): " << std::boolalpha << queue.empty() << std::endl;
                out << std::endl;
            }
            out << "~~~ non queue queue end ~~~" << std::endl;
            out << std::endl;

            out << "~~~ empty queue start ~~~" << std::endl;
            {
                Queue queue;
                out << std::endl;

                out << "empty(): " << std::boolalpha << queue.empty() << std::endl;
                out << std::endl;
            }
            out << "~~~ empty queue end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Queue>
    void queue_size(std::ostream& out)
    {
        out << "=====            =====" << std::endl;
        out << "===== queue size =====" << std::endl;
        out << "=====            =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Queue::container_type cont(3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ non empty queue start ~~~" << std::endl;
            {
                Queue queue(cont);
                out << std::endl;

                out << "size(): " << queue.size() << std::endl;
                out << std::endl;
            }
            out << "~~~ non empty queue end ~~~" << std::endl;
            out << std::endl;

            out << "~~~ empty queue start ~~~" << std::endl;
            {
                Queue queue;
                out << std::endl;

                out << "size(): " << queue.size() << std::endl;
                out << std::endl;
            }
            out << "~~~ empty queue end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Queue>
    void queue_front(std::ostream& out)
    {
        out << "=====             =====" << std::endl;
        out << "===== queue front =====" << std::endl;
        out << "=====             =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Queue::container_type cont(3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ queue start ~~~" << std::endl;
            {
                Queue queue(cont);
                out << std::endl;

                out << "front(): " << queue.front() << std::endl;
                out << std::endl;
            }
            out << "~~~ queue end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Queue>
    void queue_back(std::ostream& out)
    {
        out << "=====            =====" << std::endl;
        out << "===== queue back =====" << std::endl;
        out << "=====            =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Queue::container_type cont(3, ft::Dummy(444));
            out << std::endl;

            out << "~~~ queue start ~~~" << std::endl;
            {
                Queue queue(cont);
                out << std::endl;

                out << "back(): " << queue.back() << std::endl;
                out << std::endl;
            }
            out << "~~~ queue end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Queue>
    void queue_push(std::ostream& out)
    {
        out << "=====            =====" << std::endl;
        out << "===== queue push =====" << std::endl;
        out << "=====            =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Queue::container_type cont(3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ queue start ~~~" << std::endl;
            {
                Queue queue(cont);
                out << std::endl;

                out << "back(): " << queue.back() << std::endl;
                out << std::endl;
                out << "~~~ push() start ~~~" << std::endl;
                queue.push(444);
                out << "~~~ push() end ~~~" << std::endl;
                out << std::endl;
                out << "back(): " << queue.back() << std::endl;
                out << std::endl;
            }
            out << "~~~ queue end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Queue>
    void queue_pop(std::ostream& out)
    {
        out << "=====           =====" << std::endl;
        out << "===== queue pop =====" << std::endl;
        out << "=====           =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Queue::container_type cont;
            cont.push_back(1);
            cont.push_back(2);
            cont.push_back(3);
            out << std::endl;

            out << "~~~ queue start ~~~" << std::endl;
            {
                Queue queue(cont);
                out << std::endl;

                out << "front(): " << queue.front() << std::endl;
                out << std::endl;
                out << "~~~ pop() start ~~~" << std::endl;
                queue.pop();
                out << "~~~ pop() end ~~~" << std::endl;
                out << std::endl;
                out << "front(): " << queue.front() << std::endl;
                out << std::endl;
            }
            out << "~~~ queue end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Queue>
    void queue_relational_operators(std::ostream& out)
    {
        typedef typename Queue::container_type Container;
        out << "=====                      =====" << std::endl;
        out << "===== relational operators =====" << std::endl;
        out << "=====                      =====" << std::endl;
        out << std::endl;
        {
            out << "~~~ first underlying container start ~~~" << std::endl;
            Container cont1;
            cont1.push_back(10);
            cont1.push_back(20);
            cont1.push_back(30);
            out << std::endl;

            out << "~~~ second underlying container start ~~~" << std::endl;
            Container cont2(cont1);
            out << std::endl;

            out << "~~~ third underlying container start ~~~" << std::endl;
            Container cont3;
            cont3.push_back(30);
            cont3.push_back(20);
            cont3.push_back(10);
            cont3.push_back(0);
            out << std::endl;

            out << "first underlying container: " << std::endl;
            print_const_container(cont1, out);
            out << std::endl;

            out << "second underlying container: " << std::endl;
            print_const_container(cont2, out);
            out << std::endl;

            out << "third underlying container: " << std::endl;
            print_const_container(cont3, out);
            out << std::endl;

            out << "~~~ first queue start ~~~" << std::endl;
            Queue queue1(cont1);
            out << std::endl;

            out << "~~~ second queue start ~~~" << std::endl;
            Queue queue2(cont2);
            out << std::endl;

            out << "~~~ third queue start ~~~" << std::endl;
            Queue queue3(cont3);
            out << std::endl;

            out << "queue1 == queue2: " << std::boolalpha << (queue1 == queue2) << std::endl;
            out << "queue1 == cont3: " << std::boolalpha << (queue1 == queue3) << std::endl;
            out << "queue2 == cont3: " << std::boolalpha << (queue2 == queue3) << std::endl;
            out << std::endl;

            out << "queue1 != queue2: " << std::boolalpha << (queue1 != queue2) << std::endl;
            out << "queue1 != queue3: " << std::boolalpha << (queue1 != queue3) << std::endl;
            out << "queue2 != queue3: " << std::boolalpha << (queue2 != queue3) << std::endl;
            out << std::endl;

            out << "queue1 < queue2: " << std::boolalpha << (queue1 < queue2) << std::endl;
            out << "queue1 < queue3: " << std::boolalpha << (queue1 < queue3) << std::endl;
            out << "queue2 < queue3: " << std::boolalpha << (queue2 < queue3) << std::endl;
            out << std::endl;

            out << "queue1 <= queue2: " << std::boolalpha << (queue1 <= queue2) << std::endl;
            out << "queue1 <= queue3: " << std::boolalpha << (queue1 <= queue3) << std::endl;
            out << "queue2 <= queue3: " << std::boolalpha << (queue2 <= queue3) << std::endl;
            out << std::endl;

            out << "queue1 > queue2: " << std::boolalpha << (queue1 > queue2) << std::endl;
            out << "queue1 > queue3: " << std::boolalpha << (queue1 > queue3) << std::endl;
            out << "queue2 > queue3: " << std::boolalpha << (queue2 > queue3) << std::endl;
            out << std::endl;

            out << "queue1 >= queue2: " << std::boolalpha << (queue1 >= queue2) << std::endl;
            out << "queue1 >= queue3: " << std::boolalpha << (queue1 >= queue3) << std::endl;
            out << "queue2 >= queue3: " << std::boolalpha << (queue2 >= queue3) << std::endl;
            out << std::endl;
        }
        out << "~~~ all containers end ~~~" << std::endl;;
    }
}

#endif //FT_CONTAINERS_QUEUE_TESTS_IMPL_HPP
