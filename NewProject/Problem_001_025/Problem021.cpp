#include <cassert>
#include <cstdint>
#include <algorithm>
#include <numeric>
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

int64_t Problem21()
{
    const size_t Limit = 10000;

    int64_t answer = 0;

    for (int64_t num = 2; num < Limit; ++num)
    {
        const int64_t sum = GetSumOfProperDivisors(num);
        if (sum <= num || sum >= Limit)
            continue;

        if (num == GetSumOfProperDivisors(sum))
            answer += num + sum;
    }

    return answer;
}
