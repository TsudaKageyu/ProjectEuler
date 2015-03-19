#include "stdafx.h"
#include "utils.h"

int64_t Problem61()
{
    std::array<std::vector<int64_t>, 6> nums;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        int64_t n = 1;

        for (int64_t j = 1;; ++j)
        {
            n += j * (i + 1) + 1;

            if (n < 1000)
                continue;
            else if (n > 9999)
                break;

            nums[i].push_back(n);
        }
    }

    std::array<size_t, 6> order = { 0, 1, 2, 3, 4, 5 };

    do
    {
        auto nums2 = nums;

        while (true)
        {
            for (size_t i = 0; i < nums2.size(); ++i)
            {
                const size_t j = (i + nums2.size() - 1) % nums2.size();

                const size_t ii = order[i];
                const size_t jj = order[j];

                std::set<int64_t> tmp;

                for (const auto x : nums2[jj])
                {
                    for (const auto y : nums2[ii])
                    {
                        if (x % 100 == y / 100)
                            tmp.insert(y);
                    }
                }

                nums2[ii].assign(tmp.begin(), tmp.end());
            }

            const bool empty = std::any_of(
                nums2.begin(),
                nums2.end(),
                [](const std::vector<int64_t> &v) { return v.empty(); });
            if (empty)
                break;

            const bool finish = std::all_of(
                nums2.begin(),
                nums2.end(),
                [](const std::vector<int64_t> &v) { return (v.size() == 1); });
            if (finish)
            {
                int64_t answer = 0;
                for (const auto num : nums2)
                    answer += num[0];

                return answer;
            }
        }

    } while (std::next_permutation(order.begin(), order.end()));

    return 0;
}
