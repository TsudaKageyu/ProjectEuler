#include <cstdint>
#include <array>
#include <intrin.h>

using namespace std;

namespace
{
    bool HasFourDistinctPrimeFactors(int32_t x)
    {
        int32_t count = 0;

        // Special care for the prime number 2.

        unsigned long index;
        ::_BitScanForward(&index, x);

        if (index != 0)
            count++;

        x >>= index;

        // Check for the prime numbers above 2.

        for (int32_t d = 3; d <= x; d += 2)
        {
            int32_t c = 0;
            while (x % d == 0)
            {
                c++;
                x /= d;
            }

            if (c != 0)
            {
                count++;

                if (count == 4)
                    return true;
            }
        }

        return false;
    }
}

int64_t Problem47()
{
    int32_t c = 0;
    for (int32_t n = 1; ; ++n)
    {
        if (HasFourDistinctPrimeFactors(n))
        {
            c++;
            if (c == 4)
                return n - 3;
        }
        else
        {
            c = 0;
        }
    }

    return 0;
}
