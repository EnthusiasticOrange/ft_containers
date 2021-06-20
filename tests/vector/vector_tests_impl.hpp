#ifndef FT_CONTAINERS_VECTOR_TESTS_IMPL_HPP
#define FT_CONTAINERS_VECTOR_TESTS_IMPL_HPP

#include "tests/util/Dummy.hpp"
#include <iostream>
#include <fstream>
#include "other/functional.hpp"

namespace ft
{
    template<class Vec>
    void vector_test_suite(const std::string& name, const std::string& filename)
    {
        std::ofstream out(filename.c_str());

        ft::Dummy::out = &out;
        test_suite<Vec>(name, out);

        vec_resize<Vec>(out);
        out << std::endl;
        vec_capacity<Vec>(out);
        out << std::endl;
        vec_reserve<Vec>(out);
        out << std::endl;
        vec_access<Vec>(out);
        out << std::endl;
        vec_random_access_iterators<Vec>(out);
        out << std::endl;
        vec_random_access_reverse_iterators<Vec>(out);
        out << std::endl;
    }

    template<class Vec>
    void vec_resize(std::ostream& out)
    {
        out << "=====               =====" << std::endl;
        out << "===== vector resize =====" << std::endl;
        out << "=====               =====" << std::endl;
        out << std::endl;
        out << "~~~ vector start ~~~" << std::endl;
        {
            typename Vec::iterator it;
            Vec vec;
            for (int i = 0; i < 5; ++i)
                vec.push_back(i);

            out << "~~~ resize to smaller ~~~" << std::endl;
            out << "save iterator at begin()" << std::endl;
            it = vec.begin();
            out << std::endl;
            vec.resize(3, ft::Dummy(-111));
            out << std::endl;
            out << "check if it == begin(): " << std::boolalpha << (it == vec.begin()) << std::endl;
            out << std::endl;

            out << "printing vector: " << std::endl;
            print_const_container(vec, out);
            out << std::endl;

            out << "~~~ resize to larger without new alloc ~~~" << std::endl;
            vec.resize(6, 100);
            out << std::endl;

            out << "printing vector: " << std::endl;
            print_const_container(vec, out);
            out << std::endl;

            out << "~~~ resize to larger with new alloc ~~~" << std::endl;
            vec.resize(10, ft::Dummy(123));
            out << std::endl;

            out << "~~~ exception check start ~~~" << std::endl;
            {
                try
                {
                    ft::Dummy::ExceptCounter = 3;
                    vec.resize(30, ft::Dummy(123));
                } catch (std::exception& e)
                {
                    out << "exception thrown: " << e.what() << std::endl;
                }
            }
            out << "~~~ exception check end ~~~" << std::endl;
            out << std::endl;

            out << "printing vector: " << std::endl;
            print_const_container(vec, out);
            out << std::endl;
        }
        out << "~~~ vector end ~~~" << std::endl;
    }

    template<class Vec>
    void vec_capacity(std::ostream& out)
    {
        out << "=====                 =====" << std::endl;
        out << "===== vector capacity =====" << std::endl;
        out << "=====                 =====" << std::endl;
        out << std::endl;
        out << "~~~ vector start ~~~" << std::endl;
        {
            Vec vec;
            out << "~~~ capacity in for loop ~~~" << std::endl;
            for (int i = 1; i <= 10; ++i)
            {
                out << "~~~ push_back start ~~~" << std::endl;
                vec.push_back(i);
                out << "~~~ push_back end ~~~" << std::endl;
                out << '\t' << "capacity: " << vec.capacity() << std::endl;
            }

            out << std::endl;
        }
        out << "~~~ vector end ~~~" << std::endl;
    }

    template<class Vec>
    void vec_reserve(std::ostream& out)
    {
        out << "=====                =====" << std::endl;
        out << "===== vector reserve =====" << std::endl;
        out << "=====                =====" << std::endl;
        out << std::endl;
        out << "~~~ vector start ~~~" << std::endl;
        {
            Vec vec(4, ft::Dummy(123));
            out << std::endl;
            out << "initial capacity: " << vec.capacity() << std::endl;

            out << "~~~ reserve smaller ~~~" << std::endl;
            vec.reserve(2);
            out << std::endl;
            out << "capacity: " << vec.capacity() << std::endl;
            out << std::endl;

            out << "~~~ reserve larger ~~~" << std::endl;
            vec.reserve(100);
            out << std::endl;
            out << "capacity: " << vec.capacity() << std::endl;
            out << std::endl;

            out << "printing vector: " << std::endl;
            print_const_container(vec, out);
            out << std::endl;

            out << std::endl;
        }
        out << "~~~ vector end ~~~" << std::endl;
    }

    template<class Vec>
    void vec_access(std::ostream& out)
    {
        out << "=====                         =====" << std::endl;
        out << "===== vector access functions =====" << std::endl;
        out << "=====                         =====" << std::endl;
        out << std::endl;
        out << "~~~ vector start ~~~" << std::endl;
        {
            Vec vec(4, ft::Dummy(123));
            out << std::endl;

            out << "printing vector: " << std::endl;
            print_const_container(vec, out);
            out << std::endl;

            out << "~~~ change values via operator[] ~~~" << std::endl;
            for (size_t i = 0; i < vec.size(); ++i)
                vec[i] = ft::Dummy(static_cast<int>(i));
            out << std::endl;

            out << "printing vector: " << std::endl;
            print_const_container(vec, out);
            out << std::endl;

            out << "~~~ change values via at() ~~~" << std::endl;
            for (size_t i = 0; i < vec.size(); ++i)
                vec.at(i) = ft::Dummy(static_cast<int>(100 + i));
            out << std::endl;

            out << "~~~ trying access invalid element with at() ~~~" << std::endl;
            try {
                vec.at(123);
            } catch (std::exception& e)
            {
                out << "at() exception: " << e.what() << std::endl;
            }
            out << std::endl;

            out << "~~~ front() ~~~" << std::endl;
            out << "value: " << vec.front() << std::endl;
            out << std::endl;

            out << "~~~ back() ~~~" << std::endl;
            out << "value: " << vec.back() << std::endl;
            out << std::endl;

            out << std::endl;
        }
        out << "~~~ vector end ~~~" << std::endl;
    }

    template<class Vec>
    void vec_random_access_iterators(std::ostream& out)
    {
        out << "=====                                =====" << std::endl;
        out << "===== vector random access iterators =====" << std::endl;
        out << "=====                                =====" << std::endl;
        out << std::endl;
        out << "~~~ vector start ~~~" << std::endl;
        {
            typename Vec::iterator it, it2;
            Vec vec;
            vec.reserve(10);
            out << std::endl;

            out << "~~~ init vector ~~~" << std::endl;
            for (size_t i = 0; i < vec.capacity(); ++i)
                vec.push_back(i);
            out << std::endl;

            out << "printing vector: " << std::endl;
            print_const_container(vec, out);
            out << std::endl;

            out << "~~~ it + n ~~~" << std::endl;
            out << "it = begin(), n = 3" << std::endl;
            it = vec.begin();
            it = it + 3;
            out << "*it == vec[3]: "
            << std::boolalpha << (*it == vec[3]) << " "
            << "(*it: " << *it << " | " << "vec[3]: " << vec[3] << ")" << std::endl;
            out << std::endl;

            out << "~~~ n + it ~~~" << std::endl;
            out << "it = begin(), n = 7" << std::endl;
            it = vec.begin();
            it = 7 + it;
            out << "*it == vec[7]: "
                << std::boolalpha << (*it == vec[7]) << " "
                << "(*it: " << *it << " | " << "vec[7]: " << vec[7] << ")" << std::endl;
            out << std::endl;

            out << "~~~ it - n ~~~" << std::endl;
            out << "it = end(), n = 4" << std::endl;
            it = vec.end();
            it = it - 4;
            out << "*it == vec[size() - 4]: "
                << std::boolalpha << (*it == vec[vec.size() - 4]) << " "
                << "(*it: " << *it << " | " << "vec[size() - 4]: " << vec[vec.size() - 4] << ")" << std::endl;
            out << std::endl;

            out << "~~~ it - it2 ~~~" << std::endl;
            out << "it = end(), it2 = begin()" << std::endl;
            it = vec.end();
            it2 = vec.begin();
            out << "it - it2 == size(): "
                << std::boolalpha << (static_cast<size_t>(it - it2) == vec.size()) << " "
                << "(it - it2: " << it - it2 << " | " << "size(): " << vec.size() << ")" << std::endl;
            out << std::endl;

            out << "~~~ inequality relational operators ~~~" << std::endl;
            out << "begin() < end(): " << std::boolalpha
                << (vec.begin() < vec.end()) << std::endl;
            out << "begin() > begin() + 3: " << std::boolalpha
                << (vec.begin() > vec.begin() + 3) << std::endl;
            out << "begin() + 4 <= begin() + 2: " << std::boolalpha
                << (vec.begin() + 4 <= vec.begin() + 6) << std::endl;
            out << "end() - 1 >= end(): " << std::boolalpha
                << (vec.end() - 1 >= vec.end()) << std::endl;
            out << std::endl;

            out << "~~~ it += n ~~~" << std::endl;
            out << "it = begin(), n = 2" << std::endl;
            it = vec.begin();
            it += 2;
            out << "*it == vec[2]: "
                << std::boolalpha << (*it == vec[2]) << " "
                << "(*it: " << *it << " | " << "vec[2]: " << vec[2] << ")" << std::endl;
            out << std::endl;

            out << "~~~ it -= n ~~~" << std::endl;
            out << "it = end(), n = 1" << std::endl;
            it = vec.end();
            it -= 1;
            out << "*it == vec[size() - 1]: "
                << std::boolalpha << (*it == vec[vec.size() - 1]) << " "
                << "(*it: " << *it << " | " << "vec[size() - 1]: " << vec[vec.size() - 1] << ")" << std::endl;
            out << std::endl;


            out << "~~~ dereference operator[] ~~~" << std::endl;
            out << "it = begin() + 2, n = 3" << std::endl;
            it = vec.begin() + 2;
            out << "it[3] == vec[5]: "
                << std::boolalpha << (it[3] == vec[5]) << " "
                << "(it[3]: " << it[3] << " | " << "vec[5]: " << vec[5] << ")" << std::endl;
            out << std::endl;

            out << "it = begin() + 6, n = -2" << std::endl;
            it = vec.begin() + 6;
            out << "it[-2] == vec[4]: "
                << std::boolalpha << (it[-2] == vec[4]) << " "
                << "(it[-2]: " << it[-2] << " | " << "vec[4]: " << vec[4] << ")" << std::endl;
            out << std::endl;
        }
        out << "~~~ vector end ~~~" << std::endl;
    }

    template<class Vec>
    void vec_random_access_reverse_iterators(std::ostream& out)
    {
        out << "=====                                        =====" << std::endl;
        out << "===== vector random reverse access iterators =====" << std::endl;
        out << "=====                                        =====" << std::endl;
        out << std::endl;
        out << "~~~ vector start ~~~" << std::endl;
        {
            typename Vec::reverse_iterator it, it2;
            Vec vec;
            vec.reserve(10);
            out << std::endl;

            out << "~~~ init vector ~~~" << std::endl;
            for (size_t i = 0; i < vec.capacity(); ++i)
                vec.push_back(i);
            out << std::endl;

            out << "printing vector: " << std::endl;
            print_const_container(vec, out);
            out << std::endl;

            out << "~~~ it + n ~~~" << std::endl;
            out << "it = rbegin(), n = 3" << std::endl;
            it = vec.rbegin();
            it = it + 3;
            out << "*it == vec[size() - 1 - 3]: "
                << std::boolalpha << (*it == vec[vec.size() - 1 - 3]) << " "
                << "(*it: " << *it << " | " << "vec[size() - 1 - 3]: " << vec[vec.size() - 1 - 3] << ")" << std::endl;
            out << std::endl;

            out << "~~~ n + it ~~~" << std::endl;
            out << "it = rbegin(), n = 7" << std::endl;
            it = vec.rbegin();
            it = 7 + it;
            out << "*it == vec[size() - 1 - 7]: "
                << std::boolalpha << (*it == vec[vec.size() - 1 - 7]) << " "
                << "(*it: " << *it << " | " << "vec[size() - 1 - 7]: " << vec[vec.size() - 1 - 7] << ")" << std::endl;
            out << std::endl;

            out << "~~~ it - n ~~~" << std::endl;
            out << "it = rend(), n = 4" << std::endl;
            it = vec.rend();
            it = it - 4;
            out << "*it == vec[4 - 1]: "
                << std::boolalpha << (*it == vec[4 - 1]) << " "
                << "(*it: " << *it << " | " << "vec[4 - 1]: " << vec[4 - 1] << ")" << std::endl;
            out << std::endl;

            out << "~~~ it - it2 ~~~" << std::endl;
            out << "it = rend(), it2 = rbegin()" << std::endl;
            it = vec.rend();
            it2 = vec.rbegin();
            out << "it - it2 == size(): "
                << std::boolalpha << (static_cast<size_t>(it - it2) == vec.size()) << " "
                << "(it - it2: " << it - it2 << " | " << "size(): " << vec.size() << ")" << std::endl;
            out << std::endl;

            out << "~~~ inequality relational operators ~~~" << std::endl;
            out << "rbegin() < rend(): " << std::boolalpha
                << (vec.rbegin() < vec.rend()) << std::endl;
            out << "rbegin() > rbegin() + 3: " << std::boolalpha
                << (vec.rbegin() > vec.rbegin() + 3) << std::endl;
            out << "rbegin() + 4 <= rbegin() + 2: " << std::boolalpha
                << (vec.rbegin() + 4 <= vec.rbegin() + 6) << std::endl;
            out << "rend() - 1 >= rend(): " << std::boolalpha
                << (vec.rend() - 1 >= vec.rend()) << std::endl;
            out << std::endl;

            out << "~~~ it += n ~~~" << std::endl;
            out << "it = rbegin(), n = 2" << std::endl;
            it = vec.rbegin();
            it += 2;
            out << "*it == vec[size() - 1 - 2]: "
                << std::boolalpha << (*it == vec[vec.size() - 1 - 2]) << " "
                << "(*it: " << *it << " | " << "vec[size() - 1 - 2]: " << vec[vec.size() - 1 - 2] << ")" << std::endl;
            out << std::endl;

            out << "~~~ it -= n ~~~" << std::endl;
            out << "it = rend(), n = 1" << std::endl;
            it = vec.rend();
            it -= 1;
            out << "*it == vec[1 - 1]: "
                << std::boolalpha << (*it == vec[1 - 1]) << " "
                << "(*it: " << *it << " | " << "vec[1 - 1]: " << vec[1] << ")" << std::endl;
            out << std::endl;


            out << "~~~ dereference operator[] ~~~" << std::endl;
            out << "it = rbegin() + 2, n = 3" << std::endl;
            it = vec.rbegin() + 2;
            out << "it[3] == vec[size() - 1 - 5]: "
                << std::boolalpha << (it[3] == vec[vec.size() - 1 - 5]) << " "
                << "(it[3]: " << it[3] << " | " << "vec[size() - 1 - 5]: " << vec[vec.size() - 1 - 5] << ")" << std::endl;
            out << std::endl;

            out << "it = rbegin() + 6, n = -2" << std::endl;
            it = vec.rbegin() + 6;
            out << "it[-2] == vec[size() - 1 - 4]: "
                << std::boolalpha << (it[-2] == vec[vec.size() - 1 - 4]) << " "
                << "(it[-2]: " << it[-2] << " | " << "vec[size() - 1 - 4]: " << vec[vec.size() - 1 - 4] << ")" << std::endl;
            out << std::endl;
        }
        out << "~~~ vector end ~~~" << std::endl;
    }
}

#endif //FT_CONTAINERS_VECTOR_TESTS_IMPL_HPP
