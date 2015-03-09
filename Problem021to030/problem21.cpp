#include "stdafx.h"
#include "utils.h"

namespace
{
    int64_t GetSumOfProperDivisors(int64_t num)
    {
        int64_t sum = 1;

        for (int64_t i = 2; i < static_cast<int64_t>(std::sqrt(num) + 1); ++i)
        {
            if (num % i == 0)
            {
                sum += i;

                if (num / i != i)
                    sum += num / i;
            }
        }

        return sum;
    }
}

int64_t Problem21()
{
    assert(GetSumOfProperDivisors(6) == 6);
    assert(GetSumOfProperDivisors(28) == 28);
    assert(GetSumOfProperDivisors(12) == 16);

    std::vector<int64_t> amiNums;

    for (int64_t i = 2; i <= 9999; ++i)
    {
        const int64_t j = GetSumOfProperDivisors(i);
        if (i >= j)
            continue;

        const int64_t k = GetSumOfProperDivisors(j);
        if (k == i)
        {
            amiNums.push_back(i);
            amiNums.push_back(j);
        }
    }

    return std::accumulate(amiNums.begin(), amiNums.end(), 0LL);
}
