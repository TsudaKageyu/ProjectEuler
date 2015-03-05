#include "../common.h"

int64_t Problem3()
{
    const int64_t num = 600851475143;

    // List the prime numbers no more than sqrt(num).

    const auto primes = Utils::GetPrimeNumbers<int64_t>(static_cast<int64_t>(std::sqrt(num) + 1));

    // Find the largest prime factor of num.

    int64_t answer = 0;

    for (auto it = primes.rbegin(); it != primes.rend(); ++it)
    {
        if (*it < 0)
            continue;

        const auto d = std::div(num, static_cast<int64_t>(*it));
        if (d.rem == 0)
            return *it;
    }

    return 0;
}
