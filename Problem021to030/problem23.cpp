#include "stdafx.h"
#include "utils.h"

int64_t Problem23()
{
    const int Limit = 28123;

    std::vector<int> nums;
    nums.reserve(10000);

    for (int n = 1; n < Limit; ++n)
    {
        if (Utils::GetSumOfProperDivisors(n) > n)
            nums.push_back(n);
    }

    std::vector<int> sums(Limit);
    for (int n = 1; n < Limit; ++n)
        sums[n] = n;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        for (size_t j = i; j < nums.size(); ++j)
        {
            const size_t n = nums[i] + nums[j];
            if (n < sums.size())
                sums[n] = 0;
        }
    }

    return std::accumulate(sums.begin(), sums.end(), 0LL);
}
