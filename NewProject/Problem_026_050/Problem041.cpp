#include <cstdint>
#include <vector>

using namespace std;

namespace
{
    bool IsPandigital(int32_t x)
    {
        int32_t t = x;
        int32_t m = 0;
        int32_t u = 0;
        while (t != 0)
        {
            u |= 1 << (t % 10);
            m = (m << 1) | 2;
            t /= 10;
        }

        return (m == u);
    }

    bool IsPrime(int32_t x)
    {
        if (x <= 1)
            return false;
        else if (x == 2)
            return true;
        else if ((x & 1) == 0)
            return false;

        for (int32_t p = 3; p * p < x; p += 2)
        {
            if (x % p == 0)
                return false;
        }

        return true;
    }
}

int64_t Problem41()
{
    for (int32_t n = 7654321; n >= 0; n -= 2)
    {
        if (IsPandigital(n) && IsPrime(n))
            return n;
    }

    return 0;
}
