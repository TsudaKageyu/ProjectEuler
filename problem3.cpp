#include "common.h"

namespace problem3
{
    void Solve()
    {
        StopWatch sw;

        const int64_t num = 600851475143;

        // List the prime numbers no more than sqrt(num).

        const auto primes = Utils::GetPrimeNumbers<int>(static_cast<int>(std::sqrt(num) + 1));

        // Find the largest prime factor of num.

        int answer = 0;

        for (auto it = primes.rbegin(); it != primes.rend(); ++it)
        {
            if (*it < 0)
                continue;

            const auto d = std::div(num, static_cast<int64_t>(*it));
            if (d.rem == 0) {
                answer = *it;
                break;
            }
        }

        const auto time = sw.GetElapsedMilliseconds();
        Utils::PrintResult(3, answer, time);
    }
}
