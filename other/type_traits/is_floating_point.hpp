#ifndef FT_CONTAINERS_IS_FLOATING_POINT_HPP
#define FT_CONTAINERS_IS_FLOATING_POINT_HPP

#include "integral_constant.hpp"

namespace ft
{
    template <class T> struct is_floating_point: public false_type{};
    template <class T> struct is_floating_point<const T>: public is_floating_point<T>{};
    template <class T> struct is_floating_point<volatile const T> : public is_floating_point<T>{};
    template <class T> struct is_floating_point<volatile T> : public is_floating_point<T>{};
    template<> struct is_floating_point<float>: public true_type{};
    template<> struct is_floating_point<double>: public true_type{};
    template<> struct is_floating_point<long double>: public true_type{};
}

#endif //FT_CONTAINERS_IS_FLOATING_POINT_HPP
