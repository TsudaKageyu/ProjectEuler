#include "stdafx.h"
#include "utils.h"

int64_t Problem50()
{
    const auto &primes = Utils::GetPrimeTable();
    const auto itMin = primes.begin();
    const auto itMax = std::lower_bound(primes.begin(), primes.end(), 1000000);

    int64_t answer = 0;
    size_t maxCount = 1;

    for (auto it1 = itMin + 2; it1 < itMax; ++it1)
    {
        auto it2 = itMin;
        auto it3 = itMin + 1;

        int64_t sum = *it2 + *it3;

        do
        {
            if (sum < *it1)
            {
                it3++;
                sum += *it3;
            }
            else if (sum > *it1)
            {
                sum -= *it2;
                it2++;
            }
            else
            {
                const size_t count = std::distance(it2, it3) + 1;
                if (count > maxCount)
                {
                    maxCount = count;
                    answer = *it1;
                }

                break;
            }
        }
        while (it2 < it3 && it3 < it1);
    }

    return answer;
}
