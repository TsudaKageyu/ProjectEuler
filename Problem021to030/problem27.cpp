#include "stdafx.h"
#include "utils.h"

int64_t Problem27()
{
    const auto &primes = Utils::GetPrimeTable();

    int64_t answer  = 0;
    int64_t longest = 0;

    // b should be a prime. When n == 0, n * n + a * n + b == b.

    for (auto itB = primes.begin(); *itB <= 999; ++itB)
    {
        // a shoule be some prime - b - 1.
        // When n == 1, n * n + a * n + b == some prime.
        //              a == some prime - b - 1.

        for (auto itA = primes.begin(); ; ++itA)
        {
            const int64_t a = *itA - *itB - 1;
            if (a > 999)
                break;

            int64_t n;
            for (n = 2; ; ++n)
            {
                const int64_t p = n * n + a * n + *itB;
                if (p < 2)
                    break;

                const auto it = std::lower_bound(primes.begin(), primes.end(), p);
                if (it == primes.end() || *it != p)
                    break;
            }

            if (n > longest)
            {
                longest = n;
                answer  = a * *itB;
            }
        }
    }

    return answer;
}
