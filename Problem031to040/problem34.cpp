#include "stdafx.h"
#include "utils.h"

#define DIG(d, n) Utils::GetDigit<int64_t, d>(n)

int64_t Problem34()
{
    const std::array<int64_t, 10> F = {
        Utils::GetFactorial<int64_t>(0),
        Utils::GetFactorial<int64_t>(1),
        Utils::GetFactorial<int64_t>(2),
        Utils::GetFactorial<int64_t>(3),
        Utils::GetFactorial<int64_t>(4),
        Utils::GetFactorial<int64_t>(5),
        Utils::GetFactorial<int64_t>(6),
        Utils::GetFactorial<int64_t>(7),
        Utils::GetFactorial<int64_t>(8),
        Utils::GetFactorial<int64_t>(9)
    };

    const int64_t Limit = F[1] + F[9] * 6;

    std::vector<int64_t> nums;

    for (int64_t n = 3; n <= Limit; ++n)
    {
        const std::array<int64_t, 7> digits = {
            DIG(6, n), DIG(5, n), DIG(4, n), DIG(3, n), DIG(2, n), DIG(1, n), DIG(0, n)
        };

        const auto itBegin = std::find_if(digits.begin(), digits.end(), [](int64_t x) { return x != 0; });
        assert(itBegin != digits.end());

        int64_t sum = 0;
        for (auto it = itBegin; it != digits.end(); ++it)
            sum += F[*it];

        if (sum == n)
            nums.push_back(n);
    }

    return std::accumulate(nums.begin(), nums.end(), 0LL);
}
