#include "stdafx.h"
#include "utils.h"

int64_t Problem3()
{
    const int64_t num = 600851475143;

    // List the prime numbers no more than sqrt(num).

    const auto primes = Utils::GetPrimeTable();

    const auto itMin = primes.begin();
    const auto itMax = std::lower_bound(primes.begin(), primes.end(), std::sqrt(num) + 1);

    // Find the largest prime factor of num.

    int64_t answer = 0;

    for (auto it = itMax - 1; it >= itMin; --it)
    {
        if (*it < 0)
            continue;

        const auto d = std::div(num, static_cast<int64_t>(*it));
        if (d.rem == 0)
            return *it;
    }

    return 0;
}
