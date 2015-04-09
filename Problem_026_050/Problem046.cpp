#include <cstdint>

namespace
{
    bool IsPrime(int32_t x)
    {
        if (x <= 1)
            return false;
        else if (x == 2)
            return true;
        else if ((x & 1) == 0)
            return false;

        for (int32_t p = 3; p * p <= x; p += 2)
        {
            if (x % p == 0)
                return false;
        }

        return true;
    }
}

int64_t Problem46()
{
    for (int32_t n = 35; ; n += 2)
    {
        if (IsPrime(n))
            continue;

        for (int32_t m = 1; m * m < n / 2; ++m)
        {
            if (IsPrime(n - m * m * 2))
                goto NEXT;
        }

        return n;

    NEXT:
        ;
    }
}
