#ifndef FT_CONTAINERS_FUNCTIONAL_HPP
#define FT_CONTAINERS_FUNCTIONAL_HPP

namespace ft
{
    template <class Arg, class Result>
    struct unary_function
    {
        typedef Arg argument_type;
        typedef Result result_type;
    };

    template <class Arg1, class Arg2, class Result>
    struct binary_function
    {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };

    template <class Operation> class binder1st
        : public unary_function <typename Operation::second_argument_type, typename Operation::result_type>
    {
    protected:
        Operation op;
        typename Operation::first_argument_type value;

    public:
        binder1st(const Operation& x, const typename Operation::first_argument_type& y): op(x), value(y)
        {}
        typename Operation::result_type operator()(const typename Operation::second_argument_type& x) const
        { return op(value, x); }
    };

    template <class Operation> class binder2nd
        : public unary_function <typename Operation::first_argument_type, typename Operation::result_type>
    {
    protected:
        Operation op;
        typename Operation::second_argument_type value;
    public:
        binder2nd(const Operation& x, const typename Operation::second_argument_type& y): op (x), value(y)
        {}
        typename Operation::result_type operator() (const typename Operation::first_argument_type& x) const
        { return op(x,value); }
    };

    template <class Operation, class T>
    binder1st<Operation> bind1st(const Operation& op, const T& x)
    {
        return binder1st<Operation>(op, typename Operation::first_argument_type(x));
    }

    template <class Operation, class T>
    binder2nd<Operation> bind2nd(const Operation& op, const T& x)
    {
        return binder2nd<Operation>(op, typename Operation::second_argument_type(x));
    }

    template <class T> struct less: binary_function <T, T, bool>
    {
        bool operator()(const T& x, const T& y) const { return x < y; }
    };

    template <class T> struct greater: binary_function <T, T, bool>
    {
        bool operator()(const T& x, const T& y) const { return x > y; }
    };


template <class T> struct equal_to: binary_function <T, T, bool>
    {
        bool operator()(const T& x, const T& y) const { return x == y; }
    };
}

#endif //FT_CONTAINERS_FUNCTIONAL_HPP
