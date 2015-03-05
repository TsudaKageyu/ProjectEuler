#include "stdafx.h"
#include "utils.h"

int64_t Problem10()
{
    const auto primes = Utils::GetPrimeTable();

    const auto itMin = primes.begin();
    const auto itMax = std::lower_bound(primes.begin(), primes.end(), 1999999);

    return std::accumulate(itMin, itMax, 0LL);
}
