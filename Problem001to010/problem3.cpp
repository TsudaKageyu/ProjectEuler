#include "stdafx.h"
#include "utils.h"

int64_t Problem3()
{
    const int64_t num = 600851475143;

    const auto &primes = Utils::GetPrimeTable();

    for (auto it = primes.crbegin(); it != primes.crend(); ++it)
    {
        if (num % *it == 0)
            return *it;
    }

    return 0;
}
