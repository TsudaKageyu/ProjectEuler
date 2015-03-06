#include "stdafx.h"
#include "utils.h"

#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

cpp_int Factorial(int64_t n)
{
    cpp_int f = 1;

    for (int64_t i = 2; i <= n; ++i)
        f *= i;

    return f;
}

int64_t Problem15()
{
    // Calculate 40 C 20 = 40! / (20! * 20!)

    const cpp_int f40 = Factorial(40);
    const cpp_int f20 = Factorial(20);

    const cpp_int answer = f40 / (f20 * f20);

    return answer.convert_to<int64_t>();
}
