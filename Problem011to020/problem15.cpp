#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::int256_t;

int64_t Problem15()
{
    // Calculate 40 C 20 = 40! / (20! * 20!)

    const auto f40 = Utils::GetFactorial<int256_t>(40);
    const auto f20 = Utils::GetFactorial<int256_t>(20);

    const auto answer = f40 / (f20 * f20);

    return answer.convert_to<int64_t>();
}
