#ifndef FT_CONTAINERS_UTILITY_HPP
#define FT_CONTAINERS_UTILITY_HPP

#include <ostream>

namespace ft
{
    template<class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair();
        template<class U, class V> pair(const pair<U,V>& pr);
        pair(const first_type& a, const second_type& b);
        pair& operator=(const pair& p);
    };

    template<class T1, class T2>
    bool operator==(const pair<T1, T2>& left, const pair<T1, T2>& right);

    template<class T1, class T2>
    bool operator<(const pair<T1, T2>& left, const pair<T1, T2>& right);

    template<class T1, class T2>
    pair<T1, T2> make_pair(T1 t1, T2 t2);
}

#include "utility_impl.hpp"

#endif //FT_CONTAINERS_UTILITY_HPP
