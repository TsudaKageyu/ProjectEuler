#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::cpp_int;
using boost::multiprecision::pow;

int64_t Problem48()
{
    cpp_int sum(0);

    for (uint32_t i = 1; i <= 1000; ++i)
        sum += pow(cpp_int(i), i);

    auto s = sum.str();
    s = s.substr(s.size() - 10);

    return ::atoll(s.c_str());
}
