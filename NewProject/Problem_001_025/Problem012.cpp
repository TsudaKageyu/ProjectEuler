#include <cstdint>
#include <vector>
#include <intrin.h>

namespace
{
    int32_t GetDivisorCount(int32_t n)
    {
        std::vector<int32_t> buf;

        // Special care for the prime number 2.

        unsigned long index;
        ::_BitScanForward(&index, n);

        if (index != 0)
            buf.push_back(index);

        int32_t tmp = n >> index;

        // Check for the prime numbers above 2.

        for (int32_t d = 3; d <= tmp; d += 2)
        {
            int32_t c = 0;
            while (tmp % d == 0)
            {
                c++;
                tmp /= d;
            }

            if (c != 0)
                buf.push_back(c);
        }

        int32_t count = 1;
        for (const auto c : buf)
            count *= (c + 1);

        return count;
    }
}

int64_t Problem12()
{
    int32_t number = 1;

    for (int32_t i = 2; ;++i)
    {
        number += i;

        const int divCount = GetDivisorCount(number);
        if (divCount > 500)
            return number;
    }
}
