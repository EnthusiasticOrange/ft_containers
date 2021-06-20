#ifndef FT_CONTAINERS_MAP_TESTS_IMPL_HPP
#define FT_CONTAINERS_MAP_TESTS_IMPL_HPP

#include "tests/util/Dummy.hpp"
#include <iostream>
#include <fstream>

namespace ft
{
    template<class Map>
    void map_test_suite(const std::string& name, const std::string& filename)
    {
        std::ofstream out(filename.c_str());

        ft::Dummy::out = &out;

        print_header(name, out);

        constructor_default<Map>(out);
        out << std::endl;
        constructor_range<Map>(out);
        out << std::endl;
        constructor_copy<Map>(out);
        out << std::endl;
        assign_operator<Map>(out);
        out << std::endl;
        map_iterators<Map>(out);
        out << std::endl;
        map_reverse_iterators<Map>(out);
        out << std::endl;
        capacity_functions<Map>(out);
        out << std::endl;
        map_element_access<Map>(out);
        out << std::endl;
        map_insert<Map>(out);
        out << std::endl;
        map_insert_hint<Map>(out);
        out << std::endl;
        map_insert_range<Map>(out);
        out << std::endl;
        map_erase<Map>(out);
        out << std::endl;
        modifiers_swap<Map>(out);
        out << std::endl;
        modifiers_clear<Map>(out);
        out << std::endl;
        map_find<Map>(out);
        out << std::endl;
        map_count<Map>(out);
        out << std::endl;
        map_lower_bound<Map>(out);
        out << std::endl;
        map_upper_bound<Map>(out);
        out << std::endl;
        map_equal_range<Map>(out);
        out << std::endl;
        relational_operators<Map>(out);
        out << std::endl;
    }

    template<class Map>
    void map_iterators(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====               =====" << std::endl;
        out << "===== map iterators =====" << std::endl;
        out << "=====               =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            Map map;

            out << std::endl;
            out << "Empty map: begin() == end(): ";
            out << std::boolalpha << (map.begin() == map.end()) << std::endl;
            out << std::endl;

            map.insert(ft::CreateDummy<ValueType>(123));
            out << std::endl;
            out << "One elem map: begin() == end(): ";
            out << std::boolalpha << (map.begin() == map.end()) << std::endl;
            out << "*begin() = " << *map.begin() << std::endl;
            out << std::endl;

            out << "~~~ map helper start ~~~" << std::endl;
            {
                Map helper;
                helper.insert(ft::CreateDummy<ValueType>(1));
                helper.insert(ft::CreateDummy<ValueType>(2));
                helper.insert(ft::CreateDummy<ValueType>(3));
                out << std::endl;
                map.insert(helper.begin(), helper.end());
                out << std::endl;
            }
            out << "~~~ map helper end ~~~" << std::endl;
            out << std::endl;

            out << "printing with const_iterators: " << std::endl;
            print_const_container(map, out);
            out << std::endl;

            out << "iterator operations:" << std::endl;
            out << "start it = begin()" << std::endl;
            typename Map::iterator it = map.begin();

            out << "it == begin(): " << std::boolalpha << (it == map.begin()) << std::endl;
            out << "it != end(): " << std::boolalpha << (it != map.end()) << std::endl;
            out << "*it: " << *it << std::endl;
            out << "it->second.function(): " << std::endl;
            out << '\t';
            it->second.function();
            out << std::endl;

            out << "it->second = Dummy(456):" << std::endl;
            it->second = ft::Dummy(456);
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
            print_const_container(map, out);
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }

    template<class Map>
    void map_reverse_iterators(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====                   =====" << std::endl;
        out << "===== reverse_iterators =====" << std::endl;
        out << "=====                   =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            Map map;

            out << std::endl;
            out << "Empty map: rbegin() == rend(): ";
            out << std::boolalpha << (map.rbegin() == map.rend()) << std::endl;
            out << std::endl;

            map.insert(map.begin(), ft::CreateDummy<ValueType>(123));
            out << std::endl;
            out << "One elem map: rbegin() == rend(): ";
            out << std::boolalpha << (map.rbegin() == map.rend()) << std::endl;
            out << "*rbegin() = " << *map.rbegin() << std::endl;
            out << std::endl;

            out << "~~~ map helper start ~~~" << std::endl;
            {
                Map helper;
                helper.insert(ft::CreateDummy<ValueType>(1));
                helper.insert(ft::CreateDummy<ValueType>(2));
                helper.insert(ft::CreateDummy<ValueType>(3));
                out << std::endl;
                map.insert(helper.begin(), helper.end());
                out << std::endl;
            }
            out << "~~~ map helper end ~~~" << std::endl;
            out << std::endl;

            out << "iterator operations:" << std::endl;
            out << "start it = rbegin()" << std::endl;
            typename Map::reverse_iterator it = map.rbegin();

            out << "it == rbegin(): " << std::boolalpha << (it == map.rbegin()) << std::endl;
            out << "it != rend(): " << std::boolalpha << (it != map.rend()) << std::endl;
            out << "*it: " << *it << std::endl;
            out << "it->second->function(): " << std::endl;
            out << '\t';
            it->second.function();
            out << std::endl;

            out << "it->second = Dummy(456):" << std::endl;
            it->second = Dummy(456);
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
            print_const_container_reverse(map, out);
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }

    template <class Map>
    void map_element_access(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====                =====" << std::endl;
        out << "===== map operator[] =====" << std::endl;
        out << "=====                =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            Map map;
            for (int i = 0; i < 4; i++)
                map.insert(ft::CreateDummy<ValueType>(i));
            out << std::endl;

            out << "printing map: " << std::endl;
            print_const_container(map, out);
            out << std::endl;

            out << "~~~ map access existing element ~~~" << std::endl;
            out << "map[3]: " << map[3] << std::endl;
            out << std::endl;

            out << "~~~ map access element not in the map ~~~" << std::endl;
            out << "map[123]: " << std::endl;
            out << '\t' << map[123] << std::endl;
            out << std::endl;

            out << "~~~ exception check start ~~~" << std::endl;
            {
                try
                {
                    ft::Dummy::ExceptCounter = 2;
                    map[666];
                } catch (std::exception& e)
                {
                    out << "exception thrown: " << e.what() << std::endl;
                }
            }
            out << "~~~ exception check end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }

    template <class Map>
    void map_insert(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====                           =====" << std::endl;
        out << "===== map insert single element =====" << std::endl;
        out << "=====                           =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            Map map;
            out << "~~~ insert int empty map ~~~" << std::endl;
            bool is_inserted = map.insert(ft::CreateDummy<ValueType>(123)).second;
            out << std::endl;
            out << "insertion result: " << std::boolalpha << is_inserted << std::endl;
            out << std::endl;

            out << "~~~ insert element already in map ~~~" << std::endl;
            is_inserted = map.insert(ft::CreateDummy<ValueType>(123)).second;
            out << std::endl;
            out << "insertion result: " << std::boolalpha << is_inserted << std::endl;
            out << std::endl;

            out << "~~~ insert new element to check iterator~~~" << std::endl;
            typename Map::iterator it = map.insert(ft::CreateDummy<ValueType>(222)).first;
            out << std::endl;
            out << "*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ insert again to check iterator~~~" << std::endl;
            it = map.insert(ft::CreateDummy<ValueType>(222)).first;
            out << std::endl;
            out << "*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ exception check start ~~~" << std::endl;
            {
                try
                {
                    ft::Dummy::ExceptCounter = 3;
                    map.insert(ft::CreateDummy<ValueType>(123));
                } catch (std::exception& e)
                {
                    out << "exception thrown: " << e.what() << std::endl;
                }
            }
            out << "~~~ exception check end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }

    template <class Map>
    void map_insert_hint(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====                      =====" << std::endl;
        out << "===== map insert with hint =====" << std::endl;
        out << "=====                      =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            Map map;
            out << "~~~ insert int empty map ~~~" << std::endl;
            typename Map::iterator it = map.insert(map.begin(), ft::CreateDummy<ValueType>(123));
            out << std::endl;
            out << "*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ insert element already in map ~~~" << std::endl;
            it = map.insert(map.begin(), ft::CreateDummy<ValueType>(123));
            out << std::endl;
            out << "*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ insert with iter hint ~~~" << std::endl;
            it = map.insert(it, ft::CreateDummy<ValueType>(222));
            out << std::endl;
            out << "*it: " << *it << std::endl;
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }

    template <class Map>
    void map_insert_range(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====                   =====" << std::endl;
        out << "===== map insert range =====" << std::endl;
        out << "=====                   =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            Map map;
            for (int i = 0; i < 3; ++i)
                map.insert(ft::CreateDummy<ValueType>(i));
            out << std::endl;

            {
                out << "~~~ std::list helper start ~~~" << std::endl;

                std::list<ValueType> helper;
                helper.push_back(ft::CreateDummy<ValueType>(1111));
                helper.push_back(ft::CreateDummy<ValueType>(3333));
                helper.push_back(ft::CreateDummy<ValueType>(2222));
                out << std::endl;

                out << "insert:" << std::endl;
                map.insert(helper.begin(), helper.end());
                out << std::endl;
                out << "~~~ std::list helper end ~~~" << std::endl;
            }
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }

    template<class Map>
    void map_erase(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====           =====" << std::endl;
        out << "===== map erase =====" << std::endl;
        out << "=====           =====" << std::endl;
        out << std::endl;

        out << "~~~ map start ~~~" << std::endl;
        {
            typename Map::iterator it;
            typename Map::iterator it2;
            Map map;
            map.insert(ft::CreateDummy<ValueType>(-666));
            map.insert(ft::CreateDummy<ValueType>(-555));
            map.insert(ft::CreateDummy<ValueType>(-444));
            map.insert(ft::CreateDummy<ValueType>(-333));
            map.insert(ft::CreateDummy<ValueType>(-222));
            map.insert(ft::CreateDummy<ValueType>(-111));
            out << std::endl;

            out << "~~~ erase(iterator) ~~~" << std::endl;
            out << "save it = ++begin()" << std::endl;
            it = ++map.begin();
            out << "\t*it:" << *it << std::endl;
            out << "erase single elem at begin()" << std::endl;
            map.erase(map.begin());
            out << "check if saved it is valid" << std::endl;
            out << "\t*it:" << *it << std::endl;
            out << std::endl;

            out << "~~~ size_t erase(key) ~~~" << std::endl;
            out << "erase valid key:" << std::endl;
            size_t res = map.erase(-222);
            out << "return value: " << res << std::endl;
            out << std::endl;
            out << "erase invalid key:" << std::endl;
            res = map.erase(-1234);
            out << "return value: " << res << std::endl;
            out << std::endl;

            out << "~~~ erase(iterator first, iterator last) ~~~" << std::endl;
            out << "save it = ++begin()" << std::endl;
            it = ++map.begin();
            out << "\t*it:" << *it << std::endl;
            out << "erase last two elements:" << std::endl;
            it2 = map.end(); --it2; --it2;
            map.erase(it2, map.end());
            out << "it is still the same (it is ++begin()): "
                << std::boolalpha << (it == ++map.begin()) << std::endl;
            out << "\t*it:" << *it << std::endl;
            out << std::endl;

            out << "printing with const_iterators: " << std::endl;
            print_const_container(map, out);
            out << std::endl;
        }
        out << "~~~ container end ~~~" << std::endl;
    }

    template <class Map>
    void map_find(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====          =====" << std::endl;
        out << "===== map find =====" << std::endl;
        out << "=====          =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            typename Map::iterator it;
            typename Map::const_iterator cit;
            Map map;
            for (int i = 0; i < 3; ++i)
                map.insert(ft::CreateDummy<ValueType>(i));
            out << std::endl;

            out << "~~~ find with valid key ~~~" << std::endl;
            it = map.find(0);
            out << "*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ find with invalid key ~~~" << std::endl;
            it = map.find(-123);
            out << "it == end(): " << std::boolalpha << (it == map.end()) << std::endl;
            out << std::endl;

            out << "~~~ const map start ~~~" << std::endl;
            {
                const Map const_map(map);
                out << std::endl;

                out << "~~~ find() with valid key ~~~" << std::endl;
                cit = const_map.find(1);
                out << "*cit: " << *cit << std::endl;
                out << std::endl;

                out << "~~~ find() with invalid key ~~~" << std::endl;
                cit = const_map.find(-666);
                out << "cit == end(): " << std::boolalpha << (cit == const_map.end()) << std::endl;
                out << std::endl;
            }
            out << "~~~ const map end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }

    template <class Map>
    void map_count(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====           =====" << std::endl;
        out << "===== map count =====" << std::endl;
        out << "=====           =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            size_t count;
            Map map;
            for (int i = 0; i < 3; ++i)
                map.insert(ft::CreateDummy<ValueType>(i));
            out << std::endl;

            out << "~~~ count() with valid key ~~~" << std::endl;
            count = map.count(0);
            out << "count: " << count << std::endl;
            out << std::endl;

            out << "~~~ count() with invalid key ~~~" << std::endl;
            count = map.count(-123);
            out << "count: " << count << std::endl;
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }

    template <class Map>
    void map_lower_bound(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====                 =====" << std::endl;
        out << "===== map lower_bound =====" << std::endl;
        out << "=====                 =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            typename Map::iterator it;
            typename Map::const_iterator cit;
            Map map;
            for (int i = 0; i <= 10; i += 2)
                map.insert(ft::CreateDummy<ValueType>(i));
            out << std::endl;

            out << "~~~ lower_bound() on first element ~~~" << std::endl;
            it = map.lower_bound(map.begin()->first);
            out << "it == begin(): " << std::boolalpha << (it == map.begin()) << std::endl;
            out << "*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ lower_bound() on key = 7 ~~~" << std::endl;
            it = map.lower_bound(7);
            out << "*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ lower_bound() on invalid element ~~~" << std::endl;
            it = map.lower_bound(-123);
            out << "it == end(): " << std::boolalpha << (it == map.end()) << std::endl;
            out << std::endl;

            out << "~~~ const map start ~~~" << std::endl;
            {
                const Map const_map(map);
                out << std::endl;

                out << "~~~ lower_bound() on first element ~~~" << std::endl;
                cit = const_map.lower_bound(const_map.begin()->first);
                out << "cit == begin(): " << std::boolalpha << (cit == const_map.begin()) << std::endl;
                out << "*cit: " << *cit << std::endl;
                out << std::endl;

                out << "~~~ lower_bound() on key = 9 ~~~" << std::endl;
                cit = const_map.lower_bound(9);
                out << "*cit: " << *cit << std::endl;
                out << std::endl;

                out << "~~~ lower_bound() on greater element ~~~" << std::endl;
                cit = const_map.lower_bound(333);
                out << "cit == end(): " << std::boolalpha << (cit == const_map.end()) << std::endl;
                out << std::endl;
            }
            out << "~~~ const map end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }

    template <class Map>
    void map_upper_bound(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====                 =====" << std::endl;
        out << "===== map upper_bound =====" << std::endl;
        out << "=====                 =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            typename Map::iterator it;
            typename Map::const_iterator cit;
            Map map;
            for (int i = 0; i <= 10; i += 2)
                map.insert(ft::CreateDummy<ValueType>(i));
            out << std::endl;

            out << "~~~ upper_bound() on first element ~~~" << std::endl;
            it = map.upper_bound(map.begin()->first);
            out << "it == ++begin(): " << std::boolalpha << (it == ++map.begin()) << std::endl;
            out << "*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ upper_bound() on key = 7 ~~~" << std::endl;
            it = map.upper_bound(7);
            out << "*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ upper_bound() on greater element ~~~" << std::endl;
            it = map.upper_bound(123);
            out << "it == end(): " << std::boolalpha << (it == map.end()) << std::endl;
            out << std::endl;

            out << "~~~ const map start ~~~" << std::endl;
            {
                const Map const_map(map);
                out << std::endl;

                out << "~~~ upper_bound() on first element ~~~" << std::endl;
                cit = const_map.upper_bound(const_map.begin()->first);
                out << "cit == ++begin(): " << std::boolalpha << (cit == ++const_map.begin()) << std::endl;
                out << "*cit: " << *cit << std::endl;
                out << std::endl;

                out << "~~~ upper_bound() on key = 7 ~~~" << std::endl;
                cit = const_map.upper_bound(7);
                out << "*cit: " << *cit << std::endl;
                out << std::endl;

                out << "~~~ upper_bound() on greater element ~~~" << std::endl;
                cit = const_map.upper_bound(123);
                out << "cit == end(): " << std::boolalpha << (cit == const_map.end()) << std::endl;
                out << std::endl;
            }
            out << "~~~ const map end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }

    template <class Map>
    void map_equal_range(std::ostream& out)
    {
        typedef typename Map::value_type ValueType;
        out << "=====                 =====" << std::endl;
        out << "===== map equal_range =====" << std::endl;
        out << "=====                 =====" << std::endl;
        out << std::endl;
        out << "~~~ map start ~~~" << std::endl;
        {
            typename Map::iterator it, it2;
            typename Map::const_iterator cit, cit2;
            Map map;
            for (int i = 0; i <= 10; i += 2)
                map.insert(ft::CreateDummy<ValueType>(i));
            out << std::endl;

            out << "~~~ equal_range() on first element ~~~" << std::endl;
            it = map.equal_range(map.begin()->first).first;
            it2 = map.equal_range(map.begin()->first).second;
            out << "it == begin(): " << std::boolalpha << (it == map.begin()) << std::endl;
            out << "it2 == ++begin(): " << std::boolalpha << (it2 == ++map.begin()) << std::endl;
            out << "*it: " << *it << std::endl;
            out << "*it2: " << *it2 << std::endl;
            out << std::endl;

            out << "~~~ equal_range() on key = 7 ~~~" << std::endl;
            it = map.equal_range(7).first;
            it2 = map.equal_range(7).second;
            out << "*it: " << *it << std::endl;
            out << "*it2: " << *it2 << std::endl;
            out << std::endl;

            out << "~~~ equal_range() on last element ~~~" << std::endl;
            it = map.equal_range((--map.end())->first).first;
            it2 = map.equal_range((--map.end())->first).second;
            out << "it2 == end(): " << std::boolalpha << (it2 == map.end()) << std::endl;
            out << "*it: " << *it << std::endl;
            out << std::endl;

            out << "~~~ equal_range() on greater element ~~~" << std::endl;
            it = map.equal_range(213).first;
            it2 = map.equal_range(213).second;
            out << "it == end(): " << std::boolalpha << (it == map.end()) << std::endl;
            out << "it2 == end(): " << std::boolalpha << (it2 == map.end()) << std::endl;
            out << std::endl;

            out << "~~~ const map start ~~~" << std::endl;
            {
                const Map const_map(map);
                out << std::endl;

                out << "~~~ equal_range() on first element ~~~" << std::endl;
                cit = const_map.equal_range(const_map.begin()->first).first;
                cit2 = const_map.equal_range(const_map.begin()->first).second;
                out << "cit == begin(): " << std::boolalpha << (cit == const_map.begin()) << std::endl;
                out << "cit2 == ++begin(): " << std::boolalpha << (cit2 == ++const_map.begin()) << std::endl;
                out << "*cit: " << *cit << std::endl;
                out << "*cit2: " << *cit2 << std::endl;
                out << std::endl;

                out << "~~~ equal_range() on key = 7 ~~~" << std::endl;
                cit = const_map.equal_range(7).first;
                cit2 = const_map.equal_range(7).second;
                out << "*cit: " << *cit << std::endl;
                out << "*cit2: " << *cit2 << std::endl;
                out << std::endl;

                out << "~~~ equal_range() on last element ~~~" << std::endl;
                cit = const_map.equal_range((--const_map.end())->first).first;
                cit2 = const_map.equal_range((--const_map.end())->first).second;
                out << "cit2 == end(): " << std::boolalpha << (cit2 == const_map.end()) << std::endl;
                out << "*cit: " << *cit << std::endl;
                out << std::endl;

                out << "~~~ equal_range() on greater element ~~~" << std::endl;
                cit = const_map.equal_range(213).first;
                cit2 = const_map.equal_range(213).second;
                out << "cit == end(): " << std::boolalpha << (cit == const_map.end()) << std::endl;
                out << "cit2 == end(): " << std::boolalpha << (cit2 == const_map.end()) << std::endl;
                out << std::endl;
            }
            out << "~~~ const map end ~~~" << std::endl;
            out << std::endl;
        }
        out << "~~~ map end ~~~" << std::endl;
    }
}

#endif //FT_CONTAINERS_MAP_TESTS_IMPL_HPP
