#include "stdafx.h"
#include "utils.h"

int64_t Problem49()
{
    const auto &primes = Utils::GetPrimeTable();
    const auto itMin = std::lower_bound(primes.begin(), primes.end(), 1488);
    const auto itMax = std::lower_bound(primes.begin(), primes.end(), 10000);

    for (auto it = itMin; it < itMax; ++it)
    {
        std::array<int64_t, 4> order = { 0, 1, 2, 3 };
        const std::array<int64_t, 4> digits = {
             *it / 1000,
            (*it /  100) % 10,
            (*it /   10) % 10,
             *it         % 10
        };

        int64_t nnn = *it;

        std::vector<int64_t> buf;
        buf.push_back(*it);

        while (std::next_permutation(order.begin(), order.end()))
        {
            const int64_t tmp
                = digits[order[0]] * 1000
                + digits[order[1]] * 100
                + digits[order[2]] * 10
                + digits[order[3]];
            const auto it2 = std::lower_bound(itMin, itMax, tmp);
            if (*it2 != tmp)
                continue;

            if (std::find(buf.begin(), buf.end(), tmp) != buf.end())
                continue;

            buf.push_back(tmp);
        }

        if (buf.size() < 3)
            continue;

        std::sort(buf.begin(), buf.end());

        for (size_t i = 0; i < buf.size() - 1; ++i)
        {
            for (size_t j = i + 1; j < buf.size(); ++j)
            {
                const int64_t next = buf[j] + (buf[j] - buf[i]);
                const auto it2 = std::find(buf.begin() + j, buf.end(), next);
                if (it2 != buf.end())
                {
                    char str[13];
                    ::sprintf_s(str, "%lld%lld%lld", buf[i], buf[j], next);

                    return ::atoll(str);
                }
            }
        }

        int x = 0;
    }

    return 0;
}
