#include "stdafx.h"
#include "utils.h"

int64_t Problem46()
{
    const auto &primes = Utils::GetPrimeTable();
    auto it = primes.begin();

    for (int64_t i = 3; i <= Utils::PrimeMax; i += 2)
    {
        // Skip the prime numbers.

        while (*it < i)
            it++;

        if(it == primes.end())
            break;

        if (*it == i)
            continue;

        for (auto it2 = primes.begin(); it2 < it ; ++it2)
        {
            const double sq = std::sqrt(static_cast<double>(i - *it2) / 2);
            if (sq == std::floor(sq))
                goto SKIP;
        }

        return i;

    SKIP:
        ;
    }

    return 0;
}
