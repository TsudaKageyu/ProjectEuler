#include <cstdint>
#include <algorithm>

using namespace std;

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

int64_t Problem27()
{
    int32_t nextN  = 40;
    int32_t answer = 0;

    for (int32_t b = 2; b <= 999; ++b)
    {
        if (!IsPrime(b))
            continue;

        for (int32_t a = 1 - b; a <= 999; ++a)
        {
            for (int32_t n = nextN; n >= 1; --n)
            {
                if (!IsPrime(n * n + a * n + b))
                    goto NEXT;
            }

            answer = a * b;

            for (int32_t n = nextN + 1; ; ++n)
            {
                nextN = n;

                if (!IsPrime(n * n + a * n + b))
                    break;
            }

        NEXT:
            ;
        }
    }

    return answer;
}
