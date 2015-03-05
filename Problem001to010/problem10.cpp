#include "../common.h"

int64_t Problem10()
{
    // List the prime numbers below two million.

    const auto primes = Utils::GetPrimeNumbers<int64_t>(1999999);

    // Calculate the sum.

    return std::accumulate(primes.begin(), primes.end(), 0LL);
}
