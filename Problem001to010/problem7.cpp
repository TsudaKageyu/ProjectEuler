#include "stdafx.h"
#include "utils.h"

int64_t Problem7()
{
    const auto primes = Utils::GetPrimeTable();
    if (primes.size() >= 10001)
        return primes[10000];
    else
        return 0;
}
