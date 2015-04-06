#include <cstdint>

int64_t Problem48()
{
    const int64_t Mod = 10000000000LL;

    int64_t answer = 0;

    for (int64_t n = 1; n <= 999; ++n)
    {
        int64_t p = n;
        for (int64_t m = 2; m <= n; ++m)
            p = (p * n) % Mod;

        answer = (answer + p) % Mod;
    }

    return answer;
}
