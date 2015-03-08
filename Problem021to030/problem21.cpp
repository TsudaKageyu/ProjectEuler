#include "stdafx.h"
#include "utils.h"

namespace
{
    int64_t GetSumOfDivisors(int64_t num)
    {
        const auto &primes = Utils::GetPrimeTable();

        int64_t sum = 1;

        for (int64_t i = 2; i <= static_cast<int64_t>(std::sqrt(num) + 1); ++i)
        {
            if (num % i == 0)
            {
                sum += i;
                sum += num / i;
            }
        }

        return sum;
    }
}

int64_t Problem21()
{
    std::vector<int64_t> amiNums;

    for (int64_t i = 2; i <= 9999; ++i)
    {
        const int64_t j = GetSumOfDivisors(i);
        if (i >= j)
            continue;

        const int64_t k = GetSumOfDivisors(j);
        if (k == i)
        {
            amiNums.push_back(i);
            amiNums.push_back(j);
        }
    }

    return std::accumulate(amiNums.begin(), amiNums.end(), 0LL);
}
