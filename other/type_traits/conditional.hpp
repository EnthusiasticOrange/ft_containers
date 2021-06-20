#ifndef FT_CONTAINERS_CONDITIONAL_HPP
#define FT_CONTAINERS_CONDITIONAL_HPP

namespace ft
{
    template <bool b, class T, class U> struct conditional { typedef T type; };
    template <class T, class U> struct conditional<false, T, U> { typedef U type; };
}

#endif //FT_CONTAINERS_CONDITIONAL_HPP
