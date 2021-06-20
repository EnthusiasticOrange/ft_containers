#ifndef FT_CONTAINERS_DUMMY_HPP
#define FT_CONTAINERS_DUMMY_HPP

#include <ostream>
#include "other/type_traits.hpp"
#include "other/utility.hpp"

namespace ft
{
    class Dummy
    {
    public:
        static std::ostream* out;
        static int ExceptCounter;

    public:
        int val;

    public:
        Dummy();
        Dummy(int a);
        Dummy(const Dummy& o);
        ~Dummy();

        Dummy& operator=(const Dummy& o);

        void function() const;

    private:
        static void _checkToThrow();
    };

    struct is_near
    {
        bool operator()(const Dummy& first, const Dummy& second);
    };

    bool operator==(const Dummy& lhs, const Dummy& rhs);
    bool operator!=(const Dummy& lhs, const Dummy& rhs);
    bool operator<(const Dummy& lhs, const Dummy& rhs);
    bool operator<=(const Dummy& lhs, const Dummy& rhs);
    bool operator>(const Dummy& lhs, const Dummy& rhs);
    bool operator>=(const Dummy& lhs, const Dummy& rhs);

    std::ostream& operator<<(std::ostream& out, const Dummy& d);

    template<class ValueType>
    ValueType CreateDummy(int value)
    {
        return ValueType(value, std::rand() % 10);
    }

    template<>
    ft::Dummy CreateDummy(int value);
}

#endif //FT_CONTAINERS_DUMMY_HPP
