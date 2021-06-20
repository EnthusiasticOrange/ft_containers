#ifndef FT_CONTAINERS_IS_ARITHMETIC_HPP
#define FT_CONTAINERS_IS_ARITHMETIC_HPP

#include "is_integral.hpp"
#include "is_floating_point.hpp"

namespace ft
{
    template<class T>
    struct is_arithmetic: integral_constant<bool, is_integral<T>::value || is_floating_point<T>::value> {};
}

#endif //FT_CONTAINERS_IS_ARITHMETIC_HPP
