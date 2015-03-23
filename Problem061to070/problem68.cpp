#include "stdafx.h"
#include "utils.h"

int64_t Problem68()
{
    std::array<int32_t, 10> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int64_t answer = 0;

    do
    {
        if (nums[0] == 10 || nums[1] == 10 || nums[2] == 10 || nums[3] == 10 || nums[4] == 10)
            continue;

        const int32_t sum0 = nums[5] + nums[0] + nums[4];
        const int32_t sum1 = nums[6] + nums[1] + nums[0];
        if (sum1 != sum0)
            continue;

        const int32_t sum2 = nums[7] + nums[2] + nums[1];
        if (sum2 != sum0)
            continue;

        const int32_t sum3 = nums[8] + nums[3] + nums[2];
        if (sum3 != sum0)
            continue;

        const int32_t sum4 = nums[9] + nums[4] + nums[3];
        if (sum4 != sum0)
            continue;

        const size_t n = std::min_element(nums.begin() + 5, nums.end()) - (nums.begin() + 5);

        std::stringstream ss;
        for (size_t i = 0; i < 5; ++i)
        {
            const size_t j = (n + i) % 5;

            ss << nums[j + 5] << nums[j] << nums[(j + 4) % 5];
        }

        const auto s = ss.str();
        if (s.size() != 16)
            continue;

        int64_t val = ::atoll(s.c_str());
        if (val > answer)
            answer = val;

    } while (std::next_permutation(nums.begin(), nums.end()));

    return answer;
}
