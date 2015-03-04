#include "common.h"

namespace problem10
{
    void Solve()
    {
        StopWatch sw;

        // List the prime numbers below two million.

        const auto primes = Utils::GetPrimeNumbers<int64_t>(1999999);

        // Calculate the sum.

        const int64_t answer = std::accumulate(primes.begin(), primes.end(), 0LL);

        const auto time = sw.GetElapsedMilliseconds();
        Utils::PrintResult(10, answer, time);
    }
}
