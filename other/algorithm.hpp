#ifndef FT_CONTAINERS_ALGORITHM_HPP
#define FT_CONTAINERS_ALGORITHM_HPP

namespace ft
{
    template<class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template<class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, InputIterator2 last2)
    {
        while (first2 != last2)
        {
            if (first1 == last1 || (*first1 < *first2))
                return true;
            if (*first2 < *first1)
                return false;
            ++first1; ++first2;
        }
        return false;
    }

    template <class T> const T& max(const T& a, const T& b)
    {
        return (a < b) ? b : a;
    }

    template <class T> const T& min(const T& a, const T& b)
    {
        return !(b < a) ? a : b;
    }

    template <class T> void ft_swap(T& a, T& b)
    {
        T c(a);
        a=b;
        b=c;
    }
}

#endif //FT_CONTAINERS_ALGORITHM_HPP
