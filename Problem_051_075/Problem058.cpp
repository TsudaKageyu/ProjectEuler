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

int64_t Problem58()
{
    int32_t n = 1;
    int32_t c = 1;
    int32_t p = 0;

    for (int32_t i = 1; ; ++i)
    {
        for (int32_t j = 0; j < 4; ++j)
        {
            n += i * 2;

            if (IsPrime(n))
                p++;
        }

        c += 4;

        if (c > p * 10)
            return (i * 2 + 1);
    }
}
