#include <cassert>
#include <cstdint>
#include <vector>
#include <intrin.h>

namespace
{
    int64_t GetSumOfProperDivisors(int64_t x)
    {
        assert(x > 0);

        unsigned long zeros;
        ::_BitScanForward64(&zeros, x);

        int64_t sum = (2 << zeros) - 1;
        int64_t y = x >> zeros;

        for (int64_t p = 3; p <= y; p += 2)
        {
            int64_t z = p;

            while (y % p == 0)
            {
                y /= p;
                z *= p;
            }

            if (z != p)
                sum *= (z - 1) / (p - 1);
        }

        return sum - x;
    }
}

int64_t Problem23()
{
    const int64_t Limit = 28123;

    std::vector<int32_t> abundantNums;
    abundantNums.reserve(Limit);

    for (int32_t i = 1; i <= Limit; ++i)
    {
        if (GetSumOfProperDivisors(i) > i)
            abundantNums.push_back(i);
    }

    std::vector<bool> isAbundantSum(Limit * 2 + 1);

    for (size_t i = 0; i < abundantNums.size(); ++i)
    {
        for (size_t j = i; j < abundantNums.size(); ++j)
        {
            isAbundantSum[abundantNums[i] + abundantNums[j]] = true;
        }
    }

    int64_t answer = 0;

    for (int64_t i = 0; i <= Limit; ++i)
    {
        if (!isAbundantSum[i])
            answer += i;
    }

    return answer;
}
