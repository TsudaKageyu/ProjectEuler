#include "stdafx.h"
#include "utils.h"

#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using boost::multiprecision::int256_t;

int256_t Factorial(int256_t n)
{
    int256_t f = 1;

    for (int64_t i = 2; i <= n; ++i)
        f *= i;

    return f;
}

int64_t Problem15()
{
    // Calculate 40 C 20 = 40! / (20! * 20!)

    const int256_t f40 = Factorial(40);
    const int256_t f20 = Factorial(20);

    const int256_t answer = f40 / (f20 * f20);

    return answer.convert_to<int64_t>();
}
