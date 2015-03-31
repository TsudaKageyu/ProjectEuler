#include <cstdint>
#include <array>
#include <vector>

using namespace std;

int64_t Problem35()
{
    vector<int32_t> sieve(1000001);
    sieve[2] = 2;

    for (size_t i = 3; i < sieve.size(); i += 2)
        sieve[i] = static_cast<int32_t>(i);

    for (size_t i = 3; i * i <= sieve.size(); ++i)
    {
        if (sieve[i] == 0)
            continue;

        for (size_t j = i * 2; j < sieve.size(); j += i)
            sieve[j] = 0;
    }

    for (size_t i = 11; i < sieve.size(); i += 2)
    {
        std::array<int32_t, 6> ds = {};
        int32_t c = 0;
        int32_t t = sieve[i];
        while (t != 0)
        {
            const int32_t d = t % 10;
            t /= 10;
            if ((d & 1) == 0 || d == 5)
            {
                sieve[i] = 0;
                goto NEXT;
            }

            ds[c++] = d;
        }

        for (size_t j = 1; j < c; ++j)
        {
            int32_t p = 0;
            int32_t m = 1;

            for (int k = 0; k < c; ++k)
            {
                p += ds[(j + k) % c] * m;
                m *= 10;
            }

            if (sieve[p] == 0)
            {
                sieve[i] = 0;
                goto NEXT;
            }
        }

    NEXT:
        ;
    }

    return std::count_if(sieve.begin(), sieve.end(), [](int32_t x) { return x != 0; });
}
