#include "stdafx.h"
#include "utils.h"

int64_t Problem32()
{
    std::array<int64_t, 9> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::set<int64_t> products;

    do
    {
        const int64_t a = nums[0] * (nums[1] * 1000 + nums[2] * 100 + nums[3] * 10 + nums[4]);
        const int64_t b = (nums[0] * 1000 + nums[1] * 100 + nums[2] * 10 + nums[3]) * nums[4];
        const int64_t c = (nums[0] * 10 + nums[1]) * (nums[2] * 100 + nums[3] * 10 + nums[4]);
        const int64_t d = (nums[0] * 100 + nums[1] * 10 + nums[2]) * (nums[3] * 10 + nums[4]);
        const int64_t e = nums[5] * 1000 + nums[6] * 100 + nums[7] * 10 + nums[8];

        if (a == e || b == e || c == e || d == e)
            products.insert(e);

    } while (std::next_permutation(nums.begin(), nums.end()));

    return std::accumulate(products.begin(), products.end(), 0LL);
}
