#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::cpp_int;
using boost::multiprecision::pow;

int64_t Problem29()
{
    int dupCount = 0;

    std::vector<cpp_int> nums(9801);

    for (int r = 2; r <= 100; ++r)
    {
        for (int c = 2; c <= 100; ++c)
            nums[(r - 2) * 99 + (c - 2)] = pow(cpp_int(r), c);
    }

    std::sort(nums.begin(), nums.end());

    return (std::unique(nums.begin(), nums.end()) - nums.begin());
}
