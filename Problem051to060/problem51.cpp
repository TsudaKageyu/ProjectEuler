#include "stdafx.h"
#include "utils.h"

struct Number
{
    std::string num;
    std::vector<size_t> digits;

    bool operator==(const Number &x) { return num == x.num; }
    bool operator<(const Number &x) { return num < x.num; }
};

int64_t Problem51()
{
    const auto &primes = Utils::GetPrimeTable();
    const auto itMin = std::lower_bound(primes.begin(), primes.end(), 10000);
    const auto itMax = std::lower_bound(primes.begin(), primes.end(), 999999);

    std::vector<Number> nums;

    for (auto it = itMin; it < itMax; ++it)
    {
        char buf[10];
        ::sprintf_s(buf, "%lld", *it);

        Number n;
        n.num = buf;

        for (size_t i = 0; i < n.num.size(); ++i)
        {
            n.digits.push_back(i);

            for (size_t j = 0; j < n.num.size(); ++j)
            {
                if (j != i && buf[j] == buf[i])
                    n.digits.push_back(j);
            }

            if (n.digits.size() >= 3)
                break;
            else
                n.digits.clear();
        }

        if (n.digits.size() >= 3)
            nums.push_back(n);
    }

    for (size_t i = 0; i < nums.size(); ++i)
    {
        auto n = nums[i];

        int64_t count = 0;

        for (int64_t j = 0; j <= 9; ++j)
        {
            for (auto d : n.digits)
                n.num[d] = static_cast<char>(j + '0');

            const auto it = std::lower_bound(nums.begin(), nums.end(), n);
            if (it != nums.end() && *it == n)
                count++;
        }

        if (count == 7)
            return ::atoll(nums[i].num.c_str());
    }

    return 0;
}
