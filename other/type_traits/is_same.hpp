#ifndef FT_CONTAINERS_IS_SAME_HPP
#define FT_CONTAINERS_IS_SAME_HPP

#include "integral_constant.hpp"

namespace ft
{
    template <class T, class U> struct is_same : public false_type {};
    template <class T> struct is_same<T,T> : public true_type {};
}

#endif //FT_CONTAINERS_IS_SAME_HPP
