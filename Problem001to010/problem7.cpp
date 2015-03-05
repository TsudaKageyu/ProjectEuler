#include "stdafx.h"
#include "utils.h"

int64_t Problem7()
{
    for (int n = 100000;; n += 100000)
    {
        const auto primes = Utils::GetPrimeNumbers<int64_t>(n);
        if (primes.size() >= 10001)
            return primes[10000];
    }
}
