#include "Dummy.hpp"
#include <exception>

std::ostream* ft::Dummy::out = NULL;
int ft::Dummy::ExceptCounter = -1;

ft::Dummy::Dummy()
    :val(0)
{
    _checkToThrow();
    *out << "Dummy(): 0" << std::endl;
}

ft::Dummy::Dummy(int a)
    : val(a)
{
    _checkToThrow();
    *out << "Dummy(int): " << val << std::endl;
}

ft::Dummy::Dummy(const Dummy& o)
    : val(o.val)
{
    _checkToThrow();
    *out << "Dummy(const Dummy&): " << val << " | " << o.val << std::endl;
}

ft::Dummy::~Dummy()
{
    *out << "~Dummy(): " << val << std::endl;
}

ft::Dummy& ft::Dummy::operator=(const Dummy& o)
{
    _checkToThrow();
    *out << "Dummy::operator=(const Dummy&): " << val << " | " << o.val << std::endl;
    if (this != &o)
        val = o.val;
    return *this;
}

void ft::Dummy::function() const
{
    *out << "Dummy(" << val << ") function()" << std::endl;
}

void ft::Dummy::_checkToThrow()
{
    if (ExceptCounter > 0)
        ExceptCounter -= 1;
    else if (ExceptCounter == 0)
    {
        ExceptCounter = -1;
        throw std::runtime_error("ft::Dummy exception");
    }
}

bool ft::operator==(const Dummy& lhs, const Dummy& rhs)
{
    return lhs.val == rhs.val;
}

bool ft::operator!=(const Dummy& lhs, const Dummy& rhs)
{
    return lhs.val != rhs.val;
}

bool ft::operator<(const Dummy& lhs, const Dummy& rhs)
{
    return lhs.val < rhs.val;
}

bool ft::operator<=(const Dummy& lhs, const Dummy& rhs)
{
    return lhs.val <= rhs.val;
}

bool ft::operator>(const Dummy& lhs, const Dummy& rhs)
{
    return lhs.val > rhs.val;
}

bool ft::operator>=(const Dummy& lhs, const Dummy& rhs)
{
    return lhs.val >= rhs.val;
}

std::ostream& ft::operator<<(std::ostream& out, const Dummy& d)
{
    out << d.val;
    return out;
}

bool ft::is_near::operator()(const ft::Dummy& first, const ft::Dummy& second)
{
    return (std::abs(first.val - second.val) < 10);
}

template<>
ft::Dummy ft::CreateDummy(int value)
{
    return ft::Dummy(value);
}