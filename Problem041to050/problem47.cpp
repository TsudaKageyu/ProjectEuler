#include "stdafx.h"
#include "utils.h"

int64_t Problem47()
{
    const auto &primes = Utils::GetPrimeTable();

    std::vector<int64_t> counts(500000);
    const auto itMax = std::lower_bound(
        primes.begin(), primes.end(), static_cast<int64_t>(counts.size()) + 1);

    for (auto it = primes.begin(); it < itMax; ++it)
    {
        for (size_t j = *it * 2; j < counts.size(); j += *it)
            counts[j]++;
    }

    int64_t c = 0;

    for (size_t k = 0; k < counts.size(); ++k)
    {
        if (counts[k] == 4)
            c++;
        else
            c = 0;

        if (c == 4)
            return k - 3;
    }

    return 0;
}
