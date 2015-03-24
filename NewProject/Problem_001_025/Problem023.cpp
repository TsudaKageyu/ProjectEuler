#include <cassert>
#include <cstdint>
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
    return 0;
}
