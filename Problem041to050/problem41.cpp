#include "stdafx.h"
#include "utils.h"

int64_t Problem41()
{
    const auto &prime = Utils::GetPrimeTable();

    auto itMin = std::lower_bound(prime.begin(), prime.end(), 1000000);
    auto itMax = std::lower_bound(prime.begin(), prime.end(), 7654321);

    for (auto p = itMax - 1; p >= itMin; --p)
    {
        std::array<bool, 10> used
            = { true, false, false, false, false, false, false, false, true, true };

        int64_t tmp = *p;
        for (int i = 0; i < 7; ++i)
        {
            const int64_t d = tmp % 10;
            if (used[d])
                goto SKIP;

            used[d] = true;
            tmp /= 10;
        }

        return *p;

    SKIP:
        ;
    }

    return 0;
}
