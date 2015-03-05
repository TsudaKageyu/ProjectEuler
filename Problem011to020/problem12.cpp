#include "stdafx.h"
#include "utils.h"

namespace
{
    int64_t GetDivisorCount(int64_t num)
    {
        const auto &primes = Utils::GetPrimeTable();

        int64_t c = 1;

        for (const auto prime : primes)
        {
            if (prime > num)
                break;

            int64_t r = 0;

            while (num % prime == 0)
            {
                num /= prime;
                r++;
            }

            c *= (r + 1);
        }

        return c;
    }
}

int64_t Problem12()
{
    int64_t tc = 1;

    for (int64_t i = 2; ; ++i)
    {
        tc += i;

        if (GetDivisorCount(tc) > 500)
            return tc;
    }
}
