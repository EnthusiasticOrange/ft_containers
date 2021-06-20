#ifndef FT_CONTAINERS_STACK_TESTS_IMPL_HPP
#define FT_CONTAINERS_STACK_TESTS_IMPL_HPP

#include "tests/util/Dummy.hpp"
#include <iostream>
#include <fstream>

namespace ft
{
    template<class StackList, class StackVec>
    void stack_test_suite(const std::string& name, const std::string& filename)
    {
        std::ofstream out(filename.c_str());

        ft::Dummy::out = &out;

        print_header(name + "(list)", out);
        stack_constructor<StackList>(out);
        out << std::endl;
        stack_empty<StackList>(out);
        out << std::endl;
        stack_size<StackList>(out);
        out << std::endl;
        stack_top<StackList>(out);
        out << std::endl;
        stack_push<StackList>(out);
        out << std::endl;
        stack_pop<StackList>(out);
        out << std::endl;
        stack_relational_operators<StackList>(out);
        out << std::endl;

        print_header(name + "(vector)", out);
        stack_constructor<StackVec>(out);
        out << std::endl;
        stack_empty<StackVec>(out);
        out << std::endl;
        stack_size<StackVec>(out);
        out << std::endl;
        stack_top<StackVec>(out);
        out << std::endl;
        stack_push<StackVec>(out);
        out << std::endl;
        stack_pop<StackVec>(out);
        out << std::endl;
        stack_relational_operators<StackVec>(out);
        out << std::endl;
    }

    template<class Stack>
    void stack_constructor(std::ostream& out)
    {
        out << "=====                   =====" << std::endl;
        out << "===== stack constructor =====" << std::endl;
        out << "=====                   =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Stack::container_type cont(3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ stack start ~~~" << std::endl;
            {
                Stack stack(cont);
            }
            out << "~~~ stack end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Stack>
    void stack_empty(std::ostream& out)
    {
        out << "=====             =====" << std::endl;
        out << "===== stack empty =====" << std::endl;
        out << "=====             =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Stack::container_type cont(3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ non empty stack start ~~~" << std::endl;
            {
                Stack stack(cont);
                out << std::endl;

                out << "empty(): " << std::boolalpha << stack.empty() << std::endl;
                out << std::endl;
            }
            out << "~~~ non empty stack end ~~~" << std::endl;
            out << std::endl;

            out << "~~~ empty stack start ~~~" << std::endl;
            {
                Stack stack;
                out << std::endl;

                out << "empty(): " << std::boolalpha << stack.empty() << std::endl;
                out << std::endl;
            }
            out << "~~~ empty stack end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Stack>
    void stack_size(std::ostream& out)
    {
        out << "=====            =====" << std::endl;
        out << "===== stack size =====" << std::endl;
        out << "=====            =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Stack::container_type cont(3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ non empty stack start ~~~" << std::endl;
            {
                Stack stack(cont);
                out << std::endl;

                out << "size(): " << stack.size() << std::endl;
                out << std::endl;
            }
            out << "~~~ non empty stack end ~~~" << std::endl;
            out << std::endl;

            out << "~~~ empty stack start ~~~" << std::endl;
            {
                Stack stack;
                out << std::endl;

                out << "size(): " << stack.size() << std::endl;
                out << std::endl;
            }
            out << "~~~ empty stack end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Stack>
    void stack_top(std::ostream& out)
    {
        out << "=====           =====" << std::endl;
        out << "===== stack top =====" << std::endl;
        out << "=====           =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Stack::container_type cont(3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ stack start ~~~" << std::endl;
            {
                Stack stack(cont);
                out << std::endl;

                out << "top(): " << stack.top() << std::endl;
                out << std::endl;
            }
            out << "~~~ stack end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Stack>
    void stack_push(std::ostream& out)
    {
        out << "=====            =====" << std::endl;
        out << "===== stack push =====" << std::endl;
        out << "=====            =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Stack::container_type cont(3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ stack start ~~~" << std::endl;
            {
                Stack stack(cont);
                out << std::endl;

                out << "top(): " << stack.top() << std::endl;
                out << std::endl;
                out << "~~~ push() start ~~~" << std::endl;
                stack.push(444);
                out << "~~~ push() end ~~~" << std::endl;
                out << std::endl;
                out << "top(): " << stack.top() << std::endl;
                out << std::endl;
            }
            out << "~~~ stack end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Stack>
    void stack_pop(std::ostream& out)
    {
        out << "=====           =====" << std::endl;
        out << "===== stack pop =====" << std::endl;
        out << "=====           =====" << std::endl;
        out << std::endl;
        out << "~~~ underlying container start ~~~" << std::endl;
        {
            typename Stack::container_type cont;
            cont.push_back(1);
            cont.push_back(2);
            cont.push_back(3);
            out << std::endl;

            out << "~~~ stack start ~~~" << std::endl;
            {
                Stack stack(cont);
                out << std::endl;

                out << "top(): " << stack.top() << std::endl;
                out << std::endl;
                out << "~~~ pop() start ~~~" << std::endl;
                stack.pop();
                out << "~~~ pop() end ~~~" << std::endl;
                out << std::endl;
                out << "top(): " << stack.top() << std::endl;
                out << std::endl;
            }
            out << "~~~ stack end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ underlying container end ~~~" << std::endl;
    }

    template<class Stack>
    void stack_relational_operators(std::ostream& out)
    {
        typedef typename Stack::container_type Container;
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

            out << "~~~ first stack start ~~~" << std::endl;
            Stack stack1(cont1);
            out << std::endl;

            out << "~~~ second stack start ~~~" << std::endl;
            Stack stack2(cont2);
            out << std::endl;

            out << "~~~ third stack start ~~~" << std::endl;
            Stack stack3(cont3);
            out << std::endl;

            out << "stack1 == stack2: " << std::boolalpha << (stack1 == stack2) << std::endl;
            out << "stack1 == cont3: " << std::boolalpha << (stack1 == stack3) << std::endl;
            out << "stack2 == cont3: " << std::boolalpha << (stack2 == stack3) << std::endl;
            out << std::endl;

            out << "stack1 != stack2: " << std::boolalpha << (stack1 != stack2) << std::endl;
            out << "stack1 != stack3: " << std::boolalpha << (stack1 != stack3) << std::endl;
            out << "stack2 != stack3: " << std::boolalpha << (stack2 != stack3) << std::endl;
            out << std::endl;

            out << "stack1 < stack2: " << std::boolalpha << (stack1 < stack2) << std::endl;
            out << "stack1 < stack3: " << std::boolalpha << (stack1 < stack3) << std::endl;
            out << "stack2 < stack3: " << std::boolalpha << (stack2 < stack3) << std::endl;
            out << std::endl;

            out << "stack1 <= stack2: " << std::boolalpha << (stack1 <= stack2) << std::endl;
            out << "stack1 <= stack3: " << std::boolalpha << (stack1 <= stack3) << std::endl;
            out << "stack2 <= stack3: " << std::boolalpha << (stack2 <= stack3) << std::endl;
            out << std::endl;

            out << "stack1 > stack2: " << std::boolalpha << (stack1 > stack2) << std::endl;
            out << "stack1 > stack3: " << std::boolalpha << (stack1 > stack3) << std::endl;
            out << "stack2 > stack3: " << std::boolalpha << (stack2 > stack3) << std::endl;
            out << std::endl;

            out << "stack1 >= stack2: " << std::boolalpha << (stack1 >= stack2) << std::endl;
            out << "stack1 >= stack3: " << std::boolalpha << (stack1 >= stack3) << std::endl;
            out << "stack2 >= stack3: " << std::boolalpha << (stack2 >= stack3) << std::endl;
            out << std::endl;
        }
        out << "~~~ all containers end ~~~" << std::endl;;
    }
}

#endif //FT_CONTAINERS_STACK_TESTS_IMPL_HPP
