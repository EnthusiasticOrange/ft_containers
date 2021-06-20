#ifndef FT_CONTAINERS_TESTS_IMPL_HPP
#define FT_CONTAINERS_TESTS_IMPL_HPP

#include "tests/util/Dummy.hpp"
#include <iomanip>
#include <list>

namespace ft
{
    template<class T1, class T2>
    std::ostream& operator<<(std::ostream& out, const ft::pair<T1, T2>& p)
    {
        out << "pair(" << p.first << ", " << p.second << ')';
        return out;
    }

    template<class T1, class T2>
    std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& p)
    {
        out << "pair(" << p.first << ", " << p.second << ')';
        return out;
    }

    template<class Container>
    void print_const_container(const Container& cont, std::ostream& out)
    {
        for (typename Container::const_iterator cit = cont.begin(); cit != cont.end(); ++cit)
        {
            out << *cit;
            typename Container::const_iterator next(cit);
            ++next;
            if (next != cont.end())
                out << ", ";
        }
        out << std::endl;
    }

    template<class Container>
    void print_const_container_reverse(const Container& cont, std::ostream& out)
    {
        for (typename Container::const_reverse_iterator cit = cont.rbegin(); cit != cont.rend(); ++cit)
        {
            out << *cit;
            typename Container::const_reverse_iterator next(cit);
            ++next;
            if (next != cont.rend())
                out << ", ";
        }
        out << std::endl;
    }

    template<class Container>
    void test_suite(const std::string& name, std::ostream& out)
    {
        print_header(name, out);
        out << std::endl;
        constructor_default<Container>(out);
        out << std::endl;
        constructor_fill<Container>(out);
        out << std::endl;
        constructor_range<Container>(out);
        out << std::endl;
        constructor_copy<Container>(out);
        out << std::endl;
        assign_operator<Container>(out);
        out << std::endl;
        iterator_bidirectional<Container>(out);
        out << std::endl;
        reverse_iterator_bidirectional<Container>(out);
        out << std::endl;
        capacity_functions<Container>(out);
        out << std::endl;
        modifiers_insert<Container>(out);
        out << std::endl;
        modifiers_insert_fill<Container>(out);
        out << std::endl;
        modifiers_erase<Container>(out);
        out << std::endl;
        modifiers_swap<Container>(out);
        out << std::endl;
        modifiers_clear<Container>(out);
        out << std::endl;
        modifiers_assign<Container>(out);
        out << std::endl;
        modifiers_push_pop_back<Container>(out);
        out << std::endl;
        modifiers_resize<Container>(out);
        out << std::endl;
        relational_operators<Container>(out);
        out << std::endl;
    }

    template<class Container>
    void constructor_default(std::ostream& out)
    {
        out << "=====                     =====" << std::endl;
        out << "===== constructor default =====" << std::endl;
        out << "=====                     =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void constructor_fill(std::ostream& out)
    {
        out << "=====                  =====" << std::endl;
        out << "===== constructor fill =====" << std::endl;
        out << "=====                  =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont(3, ft::Dummy(123));
        }
        out << "~~~ container end ~~~" << std::endl;
        out << std::endl;

        out << "~~~ exception check start ~~~" << std::endl;
        {
            try
            {
                ft::Dummy::ExceptCounter = 3;
                Container cont(3, ft::Dummy(123));
            } catch (std::exception& e)
            {
                out << "exception thrown: " << e.what() << std::endl;
            }
        }
        out << "~~~ exception check end ~~~" << std::endl;
    }

    template<class Container>
    void constructor_range(std::ostream& out)
    {
        out << "=====                   =====" << std::endl;
        out << "===== constructor range =====" << std::endl;
        out << "=====                   =====" << std::endl;
        out << std::endl;
        out << "~~~ container helper start ~~~" << std::endl;
        Container helper;
        for (size_t i = 0; i < 5; ++i)
            helper.insert(helper.end(), ft::CreateDummy<typename Container::value_type>(i));
        out << std::endl;

        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont(helper.begin(), helper.end());
        }
        out << "~~~ container end ~~~" << std::endl;
        out << std::endl;

        out << "~~~ exception check start ~~~" << std::endl;
        {
            try
            {
                ft::Dummy::ExceptCounter = 3;
                Container cont(helper.begin(), helper.end());
            } catch (std::exception& e)
            {
                out << "exception thrown: " << e.what() << std::endl;
            }
        }
        out << "~~~ exception check end ~~~" << std::endl;
        out << std::endl;

        out << "~~~ container helper end ~~~" << std::endl;
    }

    template<class Container>
    void constructor_copy(std::ostream& out)
    {
        out << "=====                  =====" << std::endl;
        out << "===== constructor copy =====" << std::endl;
        out << "=====                  =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont;
            for (size_t i = 0; i < 4; ++i)
                cont.insert(cont.end(), ft::CreateDummy<typename Container::value_type>(i * 10));
            out << std::endl;

            out << std::endl;
            out << "~~~ container copy start ~~~" << std::endl;
            {
                Container cont_copy(cont);
            }
            out << "~~~ container copy end ~~~" << std::endl;
            out << std::endl;

            out << "~~~ exception check start ~~~" << std::endl;
            {
                try
                {
                    ft::Dummy::ExceptCounter = 3;
                    Container cont_copy(cont);
                } catch (std::exception& e)
                {
                    out << "exception thrown: " << e.what() << std::endl;
                }
            }
            out << "~~~ exception check end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void assign_operator(std::ostream& out)
    {
        out << "=====             =====" << std::endl;
        out << "===== operator=() =====" << std::endl;
        out << "=====             =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont;
            for (size_t i = 1; i <= 3; ++i)
                cont.insert(cont.end(), ft::CreateDummy<typename Container::value_type>(i * 10));

            out << std::endl;
            out << "~~~ container assign start ~~~" << std::endl;
            {
                Container cont_assign;
                for (size_t i = 1; i <= 5; ++i)
                    cont.insert(cont.end(), ft::CreateDummy<typename Container::value_type>(i * -10));
                out << std::endl;
                out << "~~~ container operator= start ~~~" << std::endl;
                cont_assign = cont;
                out << "~~~ container operator= end ~~~" << std::endl;
                out << std::endl;
            }
            out << "~~~ container assign end ~~~" << std::endl;
            out << std::endl;

            out << "~~~ exception check start ~~~" << std::endl;
            {
                try
                {
                    Container cont_assign;
                    for (size_t i = 1; i <= 5; ++i)
                        cont.insert(cont.end(), ft::CreateDummy<typename Container::value_type>(i * -10));
                    out << std::endl;
                    out << "~~~ container operator= start ~~~" << std::endl;
                    ft::Dummy::ExceptCounter = 3;
                    cont_assign = cont;
                    out << "~~~ container operator= end ~~~" << std::endl;
                    out << std::endl;
                } catch (std::exception& e)
                {
                    out << "exception thrown: " << e.what() << std::endl;
                }
            }
            out << "~~~ exception check end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void iterator_bidirectional(std::ostream& out)
    {
        out << "=====           =====" << std::endl;
        out << "===== iterators =====" << std::endl;
        out << "=====           =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont;

            out << std::endl;
            out << "Empty container: begin() == end(): ";
            out << std::boolalpha << (cont.begin() == cont.end()) << std::endl;
            out << std::endl;

            cont.insert(cont.begin(), ft::Dummy(123));
            out << std::endl;
            out << "One elem container: begin() == end(): ";
            out << std::boolalpha << (cont.begin() == cont.end()) << std::endl;
            out << "*begin() = " << *cont.begin() << std::endl;
            out << std::endl;

            out << "~~~ container helper start ~~~" << std::endl;
            {
                Container helper;
                helper.push_back(Dummy(1));
                helper.push_back(Dummy(2));
                helper.push_back(Dummy(3));
                out << std::endl;
                cont.insert(cont.end(), helper.begin(), helper.end());
                out << std::endl;
            }
            out << "~~~ container helper end ~~~" << std::endl;
            out << std::endl;

            out << "printing with const_iterators: " << std::endl;
            print_const_container(cont, out);
            out << std::endl;

            out << "iterator operations:" << std::endl;
            out << "start it = begin()" << std::endl;
            typename Container::iterator it = cont.begin();

            out << "it == begin(): " << std::boolalpha << (it == cont.begin()) << std::endl;
            out << "it != end(): " << std::boolalpha << (it != cont.end()) << std::endl;
            out << "*it: " << *it << std::endl;
            out << "it->function(): " << std::endl;
            out << '\t';
            it->function();
            out << std::endl;

            out << "*it = Dummy(456):" << std::endl;
            *it = Dummy(456);
            out << "*it: " << *it << std::endl;
            out << std::endl;
            out << "++it: " << std::endl;
            ++it;
            out << '\t' << *it << std::endl;
            out << "it++: " << std::endl;
            it++;
            out << '\t' << *it << std::endl;
            out << "*it++ | *it: " << std::endl;
            out << '\t' << *it++;
            out << " | " << *it << std::endl;
            out << std::endl;

            out << "--it: " << std::endl;
            --it;
            out << '\t' << *it << std::endl;
            out << "it--: " << std::endl;
            it--;
            out << '\t' << *it << std::endl;
            out << "*it-- | *it: " << std::endl;
            out << '\t' << *it-- << " | ";
            out << *it << std::endl;
            out << std::endl;

            out << "printing with const_iterators: " << std::endl;
            print_const_container(cont, out);
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void reverse_iterator_bidirectional(std::ostream& out)
    {
        out << "=====                   =====" << std::endl;
        out << "===== reverse_iterators =====" << std::endl;
        out << "=====                   =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont;

            out << std::endl;
            out << "Empty container: rbegin() == rend(): ";
            out << std::boolalpha << (cont.rbegin() == cont.rend()) << std::endl;
            out << std::endl;

            cont.insert(cont.begin(), Dummy(123));
            out << std::endl;
            out << "One elem container: rbegin() == rend(): ";
            out << std::boolalpha << (cont.rbegin() == cont.rend()) << std::endl;
            out << "*rbegin() = " << *cont.rbegin() << std::endl;
            out << std::endl;

            out << "~~~ container helper start ~~~" << std::endl;
            {
                Container helper;
                helper.push_back(Dummy(1));
                helper.push_back(Dummy(2));
                helper.push_back(Dummy(3));
                out << std::endl;
                cont.insert(cont.end(), helper.begin(), helper.end());
                out << std::endl;
            }
            out << "~~~ container helper end ~~~" << std::endl;
            out << std::endl;

            out << "iterator operations:" << std::endl;
            out << "start it = rbegin()" << std::endl;
            typename Container::reverse_iterator it = cont.rbegin();

            out << "it == rbegin(): " << std::boolalpha << (it == cont.rbegin()) << std::endl;
            out << "it != rend(): " << std::boolalpha << (it != cont.rend()) << std::endl;
            out << "*it: " << *it << std::endl;
            out << "it->function(): " << std::endl;
            out << '\t';
            it->function();
            out << std::endl;

            out << "*it = Dummy(456):" << std::endl;
            *it = Dummy(456);
            out << "*it: " << *it << std::endl;
            out << std::endl;
            out << "++it: " << std::endl;
            ++it;
            out << '\t' << *it << std::endl;
            out << "it++: " << std::endl;
            it++;
            out << '\t' << *it << std::endl;
            out << "*it++ | *it: " << std::endl;
            out << '\t' << *it++ << " | " << *it << std::endl;
            out << std::endl;

            out << "--it: " << std::endl;
            --it;
            out << '\t' << *it << std::endl;
            out << "it--: " << std::endl;
            it--;
            out << '\t' << *it << std::endl;
            out << "*it-- | *it: " << std::endl;
            out << '\t' << *it-- << " | " << *it << std::endl;
            out << std::endl;

            out << "printing with reverse_const_iterators: " << std::endl;
            print_const_container_reverse(cont, out);
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void capacity_functions(std::ostream& out)
    {
        typedef typename Container::value_type ValueType;
        out << "=====                    =====" << std::endl;
        out << "===== capacity functions =====" << std::endl;
        out << "=====                    =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont;

            out << std::endl;
            out << "empty container:" << std::endl;
            out << "empty(): " << std::boolalpha << cont.empty() << std::endl;
            out << "size(): " << cont.size() << std::endl;
            out << std::endl;

            cont.insert(cont.begin(), ft::CreateDummy<ValueType>(21));

            out << std::endl;
            out << "empty(): " << std::boolalpha << cont.empty() << std::endl;
            out << "size(): " << cont.size() << std::endl;
            out << std::endl;

            out << "max_size(): " << cont.max_size() << std::endl;
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void modifiers_insert(std::ostream& out)
    {
        out << "=====                 =====" << std::endl;
        out << "===== modifier insert =====" << std::endl;
        out << "=====                 =====" << std::endl;
        out << std::endl;

        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont;
            typename Container::iterator it;
            typename Container::iterator it2;

            out << "~~~ insert() single elem ~~~" << std::endl;

            out << "insert at the end():" << std::endl;
            it = cont.insert(cont.end(), Dummy(42));
            out << "\t*it: " << *it << std::endl;
            out << "\t++it == end(): " << std::boolalpha << (++it == cont.end()) << std::endl;
            out << std::endl;

            out << "insert at the begin():" << std::endl;
            it = cont.insert(cont.begin(), Dummy(21));
            out << "\tit == begin(): " << std::boolalpha << (it == cont.begin()) << std::endl;
            out << "\t*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ insert() range ~~~" << std::endl;
            {
                out << "~~~ container helper start ~~~" << std::endl;

                Container helper;
                helper.push_back(ft::Dummy(1111));
                helper.push_back(ft::Dummy(2222));
                helper.push_back(ft::Dummy(3333));
                out << std::endl;

                out << "insert at end():" << std::endl;
                cont.insert(cont.end(), helper.begin(), helper.end());
            }
            out << "~~~ container helper end ~~~" << std::endl;
            out << std::endl;

            out << "~~~ exception check start ~~~" << std::endl;
            {
                try
                {
                    ft::Dummy::ExceptCounter = 1;
                    cont.insert(cont.end(), Dummy(666));
                } catch (std::exception& e)
                {
                    out << "exception thrown: " << e.what() << std::endl;
                }
            }
            out << "~~~ exception check end ~~~" << std::endl;
            out << std::endl;

            out << "printing with const_iterators: " << std::endl;
            print_const_container(cont, out);
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void modifiers_insert_fill(std::ostream& out)
    {
        out << "=====                      =====" << std::endl;
        out << "===== modifier insert fill =====" << std::endl;
        out << "=====                      =====" << std::endl;
        out << std::endl;

        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont;
            cont.insert(cont.begin(), ft::Dummy(-444));

            out << "~~~ insert() fill ~~~" << std::endl;
            out << "insert after begin() (++begin()):" << std::endl;
            cont.insert(++cont.begin(), 3, ft::Dummy(123));
            out << std::endl;

            out << "~~~ exception check start ~~~" << std::endl;
            {
                try
                {
                    ft::Dummy::ExceptCounter = 1;
                    cont.insert(cont.begin(), 3, ft::Dummy(-123));
                } catch (std::exception& e)
                {
                    out << "exception thrown: " << e.what() << std::endl;
                }
            }
            out << "~~~ exception check end ~~~" << std::endl;
            out << std::endl;

            out << "printing with const_iterators: " << std::endl;
            print_const_container(cont, out);
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void modifiers_erase(std::ostream& out)
    {
        out << "=====                =====" << std::endl;
        out << "===== modifier erase =====" << std::endl;
        out << "=====                =====" << std::endl;
        out << std::endl;

        out << "~~~ container start ~~~" << std::endl;
        {
            typename Container::iterator it;
            typename Container::iterator it2;
            Container cont;
            cont.insert(cont.end(), ft::Dummy(-666));
            cont.insert(cont.end(), ft::Dummy(-555));
            cont.insert(cont.end(), ft::Dummy(-444));
            cont.insert(cont.end(), ft::Dummy(-333));
            cont.insert(cont.end(), ft::Dummy(-222));
            cont.insert(cont.end(), ft::Dummy(-111));

            out << std::endl;
            out << "~~~ iterator erase(iterator) ~~~" << std::endl;
            out << "save it = ++begin()" << std::endl;
            it = ++cont.begin();
            out << "\t*it:" << *it << std::endl;
            out << "erase single elem at begin(), returned iterator will be new begin()" << std::endl;
            it2 = cont.erase(cont.begin());
            out << "it2 == begin(): " << std::boolalpha << (it2 == cont.begin()) << std::endl;
            out << "check if saved it is valid" << std::endl;
            out << "\t*it:" << *it << std::endl;
            out << "and it == it2: " << std::boolalpha << (it == it2) << std::endl;
            out << std::endl;

            out << "~~~ iterator erase(iterator first, iterator last) ~~~" << std::endl;
            out << "save it = ++begin()" << std::endl;
            it = ++cont.begin();
            out << "\t*it:" << *it << std::endl;
            out << "erase last two elements:" << std::endl;
            it2 = cont.end(); --it2; --it2;
            it2 = cont.erase(it2, cont.end());
            out << "returned iterator == end(): "
                << std::boolalpha << (it2 == cont.end()) << std::endl;
            out << "it is still the same (it is ++begin()): "
                << std::boolalpha << (it == ++cont.begin()) << std::endl;
            out << "\t*it:" << *it << std::endl;
            out << std::endl;

            out << "printing with const_iterators: " << std::endl;
            print_const_container(cont, out);
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void modifiers_swap(std::ostream& out)
    {
        typedef typename Container::value_type ValueType;
        out << "=====                =====" << std::endl;
        out << "===== modifiers swap =====" << std::endl;
        out << "=====                =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            typename Container::iterator it;
            typename Container::iterator it2;
            Container cont;
            for (int i = 0; i < 5; ++i)
                cont.insert(cont.end(), ft::CreateDummy<ValueType>(i + 2));
            out << std::endl;

            out << "~~~ swap() ~~~" << std::endl;
            out << "~~~ container helper start ~~~" << std::endl;
            {
                Container cont_helper;
                for (int i = 0; i < 3; ++i)
                    cont_helper.insert(cont_helper.end(), ft::CreateDummy<ValueType>(i - 12));

                out << std::endl;
                out << "printing container: " << std::endl;
                print_const_container(cont, out);
                out << std::endl;

                out << "printing container helper: " << std::endl;
                print_const_container(cont_helper, out);
                out << std::endl;

                out << "saving iterators from both containers:" << std::endl;
                it = cont.begin();
                it2 = cont_helper.begin();
                out << "\tit = cont.begin(): " << *it << std::endl;
                out << "\tit2 = cont_helper.begin(): " << *it2 << std::endl;
                out << std::endl;

                out << "swapping" << std::endl;
                cont.swap(cont_helper);
                out << std::endl;

                out << "checking saved iterators from both containers:" << std::endl;
                out << "\tit == cont_helper.begin(): "
                    << std::boolalpha << (it == cont_helper.begin())  << " | "
                    << *it << std::endl;
                out << "\tit2 == cont.begin(): "
                    << std::boolalpha << (it2 == cont.begin())  << " | "
                    << *it2 << std::endl;
                out << std::endl;

                out << "printing container: " << std::endl;
                print_const_container(cont, out);
                out << std::endl;

                out << "printing container helper: " << std::endl;
                print_const_container(cont_helper, out);
                out << std::endl;
            }
            out << "~~~ container helper end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void modifiers_clear(std::ostream& out)
    {
        typedef typename Container::value_type ValueType;
        out << "=====                =====" << std::endl;
        out << "===== modifier clear =====" << std::endl;
        out << "=====                =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont;
            for (int i = 0; i < 5; ++i)
                cont.insert(cont.end(), ft::CreateDummy<ValueType>(21));
            out << std::endl;
            out << "~~~ clear() start ~~~" << std::endl;
            cont.clear();
            out << "~~~ clear() end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void modifiers_assign(std::ostream& out)
    {
        out << "=====                 =====" << std::endl;
        out << "===== modifier assign =====" << std::endl;
        out << "=====                 =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont(5, ft::Dummy(21));
            out << std::endl;

            out << "~~~ assign() fill ~~~" << std::endl;
            out << "~~~ assign() start ~~~" << std::endl;
            cont.assign(2, ft::Dummy(42));
            out << "~~~ assign() end ~~~" << std::endl;
            out << std::endl;

            out << "~~~ assign() range ~~~" << std::endl;
            out << "~~~ container helper start ~~~" << std::endl;
            {
                Container cont_helper(5, ft::Dummy(123));

                out << std::endl;
                out << "~~~ assign() start ~~~" << std::endl;
                cont.assign(cont_helper.begin(), cont_helper.end());
                out << "~~~ assign() end ~~~" << std::endl;
                out << std::endl;
            }
            out << "~~~ container helper end ~~~" << std::endl;
            out << std::endl;

            out << "~~~ exception check start ~~~" << std::endl;
            {
                try
                {
                    ft::Dummy::ExceptCounter = 3;
                    cont.assign(3, ft::Dummy(42));
                } catch (std::exception& e)
                {
                    out << "exception thrown: " << e.what() << std::endl;
                }
            }
            out << "~~~ exception check end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void modifiers_push_pop_back(std::ostream& out)
    {
        out << "=====                        =====" << std::endl;
        out << "===== modifier push pop back =====" << std::endl;
        out << "=====                        =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont(2, ft::Dummy(21));
            out << std::endl;

            out << "~~~ push_back ~~~" << std::endl;
            cont.push_back(ft::Dummy(42));
            out << std::endl;

            out << "~~~ exception check start ~~~" << std::endl;
            {
                try
                {
                    ft::Dummy::ExceptCounter = 1;
                    cont.push_back(ft::Dummy(-42));
                } catch (std::exception& e)
                {
                    out << "exception thrown: " << e.what() << std::endl;
                }
            }
            out << "~~~ exception check end ~~~" << std::endl;
            out << std::endl;

            out << "printing container: " << std::endl;
            print_const_container(cont, out);
            out << std::endl;

            out << "~~~ pop_back ~~~" << std::endl;
            cont.pop_back();
            out << std::endl;

            out << "printing container: " << std::endl;
            print_const_container(cont, out);
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void modifiers_resize(std::ostream& out)
    {
        out << "=====                 =====" << std::endl;
        out << "===== modifier resize =====" << std::endl;
        out << "=====                 =====" << std::endl;
        out << std::endl;
        out << "~~~ container start ~~~" << std::endl;
        {
            Container cont(4, ft::Dummy(21));
            out << std::endl;

            out << "~~~ resize to smaller ~~~" << std::endl;
            cont.resize(2, ft::Dummy(42));
            out << std::endl;

            out << "printing container: " << std::endl;
            print_const_container(cont, out);
            out << std::endl;

            out << "~~~ resize to larger ~~~" << std::endl;
            cont.resize(6, ft::Dummy(-24));
            out << std::endl;

            out << "printing container: " << std::endl;
            print_const_container(cont, out);
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template<class Container>
    void relational_operators(std::ostream& out)
    {
        typedef typename Container::value_type ValueType;
        out << "=====                      =====" << std::endl;
        out << "===== relational operators =====" << std::endl;
        out << "=====                      =====" << std::endl;
        out << std::endl;
        {
            out << "~~~ first container start ~~~" << std::endl;
            Container cont1;
            cont1.insert(cont1.end(), ft::CreateDummy<ValueType>(10));
            cont1.insert(cont1.end(), ft::CreateDummy<ValueType>(20));
            cont1.insert(cont1.end(), ft::CreateDummy<ValueType>(30));
            out << std::endl;

            out << "~~~ second container start ~~~" << std::endl;
            Container cont2(cont1);
            out << std::endl;

            out << "~~~ third container start ~~~" << std::endl;
            Container cont3;
            cont3.insert(cont3.end(), ft::CreateDummy<ValueType>(30));
            cont3.insert(cont3.end(), ft::CreateDummy<ValueType>(20));
            cont3.insert(cont3.end(), ft::CreateDummy<ValueType>(10));
            cont3.insert(cont3.end(), ft::CreateDummy<ValueType>(0));
            out << std::endl;

            out << "first container: " << std::endl;
            print_const_container(cont1, out);
            out << std::endl;

            out << "second container: " << std::endl;
            print_const_container(cont2, out);
            out << std::endl;

            out << "third container: " << std::endl;
            print_const_container(cont3, out);
            out << std::endl;

            out << "cont1 == cont2: " << std::boolalpha << (cont1 == cont2) << std::endl;
            out << "cont1 == cont3: " << std::boolalpha << (cont1 == cont3) << std::endl;
            out << "cont2 == cont3: " << std::boolalpha << (cont2 == cont3) << std::endl;
            out << std::endl;

            out << "cont1 != cont2: " << std::boolalpha << (cont1 != cont2) << std::endl;
            out << "cont1 != cont3: " << std::boolalpha << (cont1 != cont3) << std::endl;
            out << "cont2 != cont3: " << std::boolalpha << (cont2 != cont3) << std::endl;
            out << std::endl;

            out << "cont1 < cont2: " << std::boolalpha << (cont1 < cont2) << std::endl;
            out << "cont1 < cont3: " << std::boolalpha << (cont1 < cont3) << std::endl;
            out << "cont2 < cont3: " << std::boolalpha << (cont2 < cont3) << std::endl;
            out << std::endl;

            out << "cont1 <= cont2: " << std::boolalpha << (cont1 <= cont2) << std::endl;
            out << "cont1 <= cont3: " << std::boolalpha << (cont1 <= cont3) << std::endl;
            out << "cont2 <= cont3: " << std::boolalpha << (cont2 <= cont3) << std::endl;
            out << std::endl;

            out << "cont1 > cont2: " << std::boolalpha << (cont1 > cont2) << std::endl;
            out << "cont1 > cont3: " << std::boolalpha << (cont1 > cont3) << std::endl;
            out << "cont2 > cont3: " << std::boolalpha << (cont2 > cont3) << std::endl;
            out << std::endl;

            out << "cont1 >= cont2: " << std::boolalpha << (cont1 >= cont2) << std::endl;
            out << "cont1 >= cont3: " << std::boolalpha << (cont1 >= cont3) << std::endl;
            out << "cont2 >= cont3: " << std::boolalpha << (cont2 >= cont3) << std::endl;
            out << std::endl;
        }
        out << "~~~ containers end ~~~" << std::endl;;
    }
}

#endif //FT_CONTAINERS_TESTS_IMPL_HPP
