#include <cstdint>
#include <vector>

using namespace std;

int64_t Problem51()
{
    vector<int32_t> sieve(1000000);
    sieve[2] = 2;

    for (size_t i = 3; i < sieve.size(); i += 2)
        sieve[i] = static_cast<int32_t>(i);

    for (size_t i = 3; i * i <= sieve.size(); i += 2)
    {
        if (sieve[i] == 0)
            continue;

        for (size_t j = i * 2; j < sieve.size(); j += i)
            sieve[j] = 0;
    }

    for (size_t p = 100000; p < sieve.size(); ++p)
    {
        if (sieve[p] == 0)
            continue;

        for (size_t m = 0x02; m <= 0x3e; m += 2)
        {
            size_t p2 = 0;
            size_t c = 0;
            for (size_t n = 0; n <= 9; ++n)
            {
                if (m >= 32 && n == 0)
                    continue;

                size_t i = 1;
                size_t j = 1;
                size_t t = p;
                size_t u = 0;

                while (t != 0)
                {
                    if (m & i)
                        u += n * j;
                    else
                        u += (t % 10) * j;

                    i <<= 1;
                    j *= 10;
                    t /= 10;
                }

                if (u >= 100000 && sieve[u] != 0)
                {
                    if (p2 == 0)
                        p2 = u;

                    c++;
                }
            }

            if (c == 8)
                return p2;
        }
    }

    return 0;
}
