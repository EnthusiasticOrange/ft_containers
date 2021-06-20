#ifndef FT_CONTAINERS_LIST_TESTS_IMPL_HPP
#define FT_CONTAINERS_LIST_TESTS_IMPL_HPP

#include "tests/util/Dummy.hpp"
#include <iostream>
#include <fstream>
#include "other/functional.hpp"

namespace ft
{
    template<class List>
    void list_test_suite(const std::string& name, const std::string& filename)
    {
        std::ofstream out(filename.c_str());

        ft::Dummy::out = &out;
        test_suite<List>(name, out);
        list_push_pop_front<List>(out);
        out << std::endl;
        list_access<List>(out);
        out << std::endl;
        list_splice<List>(out);
        out << std::endl;
        list_remove<List>(out);
        out << std::endl;
        list_unique<List>(out);
        out << std::endl;
        list_merge<List>(out);
        out << std::endl;
        list_sort<List>(out);
        out << std::endl;
        list_reverse<List>(out);
        out << std::endl;
    }

    template<class List>
    void list_push_pop_front(std::ostream& out)
    {
        out << "=====                     =====" << std::endl;
        out << "===== list push pop front =====" << std::endl;
        out << "=====                     =====" << std::endl;
        out << std::endl;
        out << "~~~ list start ~~~" << std::endl;
        {
            List lst(2, ft::Dummy(21));
            out << std::endl;

            out << "~~~ push_front ~~~" << std::endl;
            lst.push_front(ft::Dummy(42));
            out << std::endl;

            out << "~~~ exception check start ~~~" << std::endl;
            {
                try
                {
                    ft::Dummy::ExceptCounter = 1;
                    lst.push_front(ft::Dummy(-42));
                } catch (std::exception& e)
                {
                    out << "exception thrown: " << e.what() << std::endl;
                }
            }
            out << "~~~ exception check end ~~~" << std::endl;
            out << std::endl;

            out << "printing container: " << std::endl;
            print_const_container(lst, out);
            out << std::endl;

            out << "~~~ pop_front ~~~" << std::endl;
            lst.pop_front();
            out << std::endl;

            out << "printing container: " << std::endl;
            print_const_container(lst, out);
            out << std::endl;
        }
        out << "~~~ list end ~~~" << std::endl;
    }

    template<class List>
    void list_access(std::ostream& out)
    {
        out << "=====             =====" << std::endl;
        out << "===== list access =====" << std::endl;
        out << "=====             =====" << std::endl;
        out << std::endl;
        out << "~~~ list start ~~~" << std::endl;
        {
            List lst(4, ft::Dummy(21));
            out << std::endl;

            out << "~~~ front() ~~~" << std::endl;
            out << lst.front() << std::endl;
            out << std::endl;

            out << "~~~ back() ~~~" << std::endl;
            out << lst.back() << std::endl;
            out << std::endl;
        }
        out << "~~~ list end ~~~" << std::endl;
    }

    template<class List>
    void list_splice(std::ostream& out)
    {
        out << "=====             =====" << std::endl;
        out << "===== list splice =====" << std::endl;
        out << "=====             =====" << std::endl;
        out << std::endl;
        {
            List lst1, lst2;
            typename List::iterator it;

            out << "~~~ fill list1 ~~~" << std::endl;
            for (int i = 1; i <= 4; ++i)
                lst1.push_back(i);
            out << std::endl;

            out << "~~~ fill list2 ~~~" << std::endl;
            for (int i = 1; i <= 3; ++i)
                lst2.push_back(i * 10);
            out << std::endl;

            it = lst1.begin();
            ++it;

            out << "~~~ splice entire list ~~~" << std::endl;
            lst1.splice(it, lst2);
            out << std::endl;

            out << "lst1: ";
            print_const_container(lst1, out);
            out << std::endl;

            out << "lst2: ";
            print_const_container(lst2, out);
            out << std::endl;

            out << "~~~ splice single element ~~~" << std::endl;
            out << "*it: " << *it << std::endl;
            out << std::endl;
            lst2.splice(lst2.begin(), lst1, it);

            out << "lst1: ";
            print_const_container(lst1, out);
            out << std::endl;

            out << "lst2: ";
            print_const_container(lst2, out);
            out << std::endl;

            out << "it == lst2.begin(): " << std::boolalpha << (it == lst2.begin()) << std::endl;
            out << std::endl;

            out << "~~~ splice single element ~~~" << std::endl;
            out << "it point to elem in lst1" << std::endl;
            out << "splice same container" << std::endl;
            it = lst1.begin(); ++it; ++it; ++it;
            lst1.splice(lst1.begin(), lst1, it, lst1.end());
            out << std::endl;

            out << "lst1: ";
            print_const_container(lst1, out);
            out << std::endl;
        }
        out << "~~~ list end ~~~" << std::endl;
    }

    template<class List>
    void list_remove(std::ostream& out)
    {
        out << "=====             =====" << std::endl;
        out << "===== list remove =====" << std::endl;
        out << "=====             =====" << std::endl;
        out << std::endl;
        out << "~~~ list start ~~~" << std::endl;
        {
            int myints[]= {15,36,7,17,20,39,4,1};
            List lst(myints, myints + sizeof(myints) / sizeof(int));
            out << std::endl;

            out << "~~~ remove() ~~~" << std::endl;
            lst.remove(17);
            out << std::endl;

            out << "list: ";
            print_const_container(lst, out);
            out << std::endl;

            out << "~~~ remove_if() ~~~" << std::endl;
            lst.remove_if(ft::bind2nd(ft::less<ft::Dummy>(), ft::Dummy(10)));
            out << std::endl;

            out << "list: ";
            print_const_container(lst, out);
            out << std::endl;
        }
        out << "~~~ list end ~~~" << std::endl;
    }

    template<class List>
    void list_unique(std::ostream& out)
    {
        out << "=====             =====" << std::endl;
        out << "===== list unique =====" << std::endl;
        out << "=====             =====" << std::endl;
        out << std::endl;
        out << "~~~ list start ~~~" << std::endl;
        {
            int myints[]= {1,4,4,7,15,17,17,20,36,36,39};
            List lst(myints, myints + sizeof(myints) / sizeof(int));
            out << std::endl;

            out << "list: ";
            print_const_container(lst, out);
            out << std::endl;

            out << "~~~ unique() ~~~" << std::endl;
            lst.unique();
            out << std::endl;

            out << "list: ";
            print_const_container(lst, out);
            out << std::endl;

            out << "~~~ unique(BinaryPredicate) ~~~" << std::endl;
            lst.unique(ft::is_near());
            out << std::endl;

            out << "list: ";
            print_const_container(lst, out);
            out << std::endl;
        }
        out << "~~~ list end ~~~" << std::endl;
    }

    template<class List>
    void list_merge(std::ostream& out)
    {
        out << "=====            =====" << std::endl;
        out << "===== list merge =====" << std::endl;
        out << "=====            =====" << std::endl;
        out << std::endl;
        out << "~~~ list start ~~~" << std::endl;
        {
            List lst1, lst2;

            out << "~~~ fill list1 ~~~" << std::endl;
            for (int i = 0; i < 10; i += 2)
                lst1.push_back(i);
            out << std::endl;

            out << "~~~ fill list2 ~~~" << std::endl;
            for (int i = 1; i < 10; i += 2)
                lst2.push_back(i);
            out << std::endl;

            out << "list1: ";
            print_const_container(lst1, out);
            out << std::endl;

            out << "list2: ";
            print_const_container(lst2, out);
            out << std::endl;

            out << "~~~ merge() ~~~" << std::endl;
            lst1.merge(lst2);
            out << std::endl;

            out << "list1: ";
            print_const_container(lst1, out);
            out << std::endl;

            out << "~~~ merge(BinaryPredicate) ~~~" << std::endl;
            out << "~~~ update list2 ~~~" << std::endl;
            for (int i = 10; i < 20; i += 2)
                lst2.push_back(i);
            out << std::endl;

            out << "list2: ";
            print_const_container(lst2, out);
            out << std::endl;

            lst2.merge(lst1, ft::greater<ft::Dummy>());

            out << "list2: ";
            print_const_container(lst2, out);
            out << std::endl;
        }
        out << "~~~ list end ~~~" << std::endl;
    }

    template<class List>
    void list_sort(std::ostream& out)
    {
        out << "=====           =====" << std::endl;
        out << "===== list sort =====" << std::endl;
        out << "=====           =====" << std::endl;
        out << std::endl;
        out << "~~~ list start ~~~" << std::endl;
        {
            int myints[]= {15,36,7,17,20,39,4,1};
            List lst(myints, myints + sizeof(myints) / sizeof(int));
            out << std::endl;

            out << "list: ";
            print_const_container(lst, out);
            out << std::endl;

            out << "~~~ sort() ~~~" << std::endl;
            lst.sort();
            out << std::endl;

            out << "list: ";
            print_const_container(lst, out);
            out << std::endl;
        }
        out << "~~~ list end ~~~" << std::endl;
    }

    template<class List>
    void list_reverse(std::ostream& out)
    {
        out << "=====              =====" << std::endl;
        out << "===== list reverse =====" << std::endl;
        out << "=====              =====" << std::endl;
        out << std::endl;
        out << "~~~ list start ~~~" << std::endl;
        {
            List lst;
            for (int i = 0; i < 10; ++i)
                lst.push_back(i);
            out << std::endl;

            out << "list: ";
            print_const_container(lst, out);
            out << std::endl;

            out << "~~~ reverse() ~~~" << std::endl;
            lst.reverse();
            out << std::endl;

            out << "list: ";
            print_const_container(lst, out);
            out << std::endl;
        }
        out << "~~~ list end ~~~" << std::endl;
    }
}

#endif //FT_CONTAINERS_LIST_TESTS_IMPL_HPP
