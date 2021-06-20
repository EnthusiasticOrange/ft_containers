#ifndef FT_CONTAINERS_UTILITY_IMPL_HPP
#define FT_CONTAINERS_UTILITY_IMPL_HPP

#include "utility.hpp"

namespace ft
{
    template<class T1, class T2>
    pair<T1, T2>::pair()
    {
    }

    template<class T1, class T2>
    template<class U, class V>
    pair<T1, T2>::pair(const pair<U, V>& pr)
        : first(pr.first), second(pr.second)
    {
    }

    template<class T1, class T2>
    pair<T1, T2>::pair(const T1& t1, const T2& t2)
        : first(t1), second(t2)
    {
    }

    template<class T1, class T2>
    pair<T1, T2>& pair<T1, T2>::operator=(const pair& p)
    {
        first = p.first;
        second = p.second;
        return *this;
    }

template<class T1, class T2>
    bool operator==(const pair<T1, T2>& left, const pair<T1, T2>& right)
    {
        return left.first == right.first && left.second == right.second;
    }

    template<class T1, class T2>
    bool operator<(const pair<T1, T2>& left, const pair<T1, T2>& right)
    {
        return left.first < right.first
                || (!(right.first < left.first) && left.second < right.second);
    }

    template<class T1, class T2>
    pair<T1, T2> make_pair(T1 t1, T2 t2)
    {
        return pair<T1, T2>(t1, t2);
    }
}

#endif //FT_CONTAINERS_UTILITY_IMPL_HPP
