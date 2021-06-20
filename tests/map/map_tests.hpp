#ifndef FT_CONTAINERS_MAP_TESTS_HPP
#define FT_CONTAINERS_MAP_TESTS_HPP

#include "tests/tests.hpp"

namespace ft
{
    void run_map_tests();

    template<class Map>
    void map_test_suite(const std::string& name, const std::string& filename);

    template<class Map>
    void map_iterators(std::ostream& out);

    template<class Map>
    void map_reverse_iterators(std::ostream& out);

    template<class Map>
    void map_element_access(std::ostream& out);

    template<class Map>
    void map_insert(std::ostream& out);

    template<class Map>
    void map_insert_hint(std::ostream& out);

    template<class Map>
    void map_insert_range(std::ostream& out);

    template<class Map>
    void map_erase(std::ostream& out);

    template<class Map>
    void map_find(std::ostream& out);

    template<class Map>
    void map_count(std::ostream& out);

    template<class Map>
    void map_lower_bound(std::ostream& out);

    template<class Map>
    void map_upper_bound(std::ostream& out);

    template<class Map>
    void map_equal_range(std::ostream& out);
}

#include "map_tests_impl.hpp"

#endif //FT_CONTAINERS_MAP_TESTS_HPP
