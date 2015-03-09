#include "stdafx.h"
#include "utils.h"

int64_t Problem21()
{
    assert(Utils::GetSumOfProperDivisors(6) == 6);
    assert(Utils::GetSumOfProperDivisors(28) == 28);
    assert(Utils::GetSumOfProperDivisors(12) == 16);

    std::vector<int64_t> amiNums;

    for (int64_t i = 2; i <= 9999; ++i)
    {
        const int64_t j = Utils::GetSumOfProperDivisors(i);
        if (i >= j)
            continue;

        const int64_t k = Utils::GetSumOfProperDivisors(j);
        if (k == i)
        {
            amiNums.push_back(i);
            amiNums.push_back(j);
        }
    }

    return std::accumulate(amiNums.begin(), amiNums.end(), 0LL);
}
