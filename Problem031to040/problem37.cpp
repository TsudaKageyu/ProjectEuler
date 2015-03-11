#include "stdafx.h"
#include "utils.h"

int64_t Problem37()
{
    const auto &primes = Utils::GetPrimeTable();

    std::vector<int64_t> answer;
    answer.reserve(11);

    const auto itLimit1 = std::lower_bound(primes.begin(), primes.end(), 10);
    const auto itLimit2 = std::lower_bound(itLimit1, primes.end(), 100);
    const auto itLimit3 = std::lower_bound(itLimit2, primes.end(), 1000);
    const auto itLimit4 = std::lower_bound(itLimit3, primes.end(), 10000);
    const auto itLimit5 = std::lower_bound(itLimit4, primes.end(), 100000);
    const auto itLimit6 = std::lower_bound(itLimit5, primes.end(), 1000000);

    for (auto it = itLimit1; it != itLimit6; ++it)
    {
        const std::array<int64_t, 7> d = {
            Utils::GetDigit<uint64_t, 0>(*it),
            Utils::GetDigit<uint64_t, 1>(*it),
            Utils::GetDigit<uint64_t, 2>(*it),
            Utils::GetDigit<uint64_t, 3>(*it),
            Utils::GetDigit<uint64_t, 4>(*it),
            Utils::GetDigit<uint64_t, 5>(*it),
            Utils::GetDigit<uint64_t, 6>(*it)
        };

        size_t s = d.size();
        while (d[s - 1] == 0)
            s--;

        const int64_t n0 = d[s - 1];
        if (n0 != 2 && n0 != 3 && n0 != 5 && n0 != 7)
            continue;

        const int64_t n1 = d[0];
        if (n1 != 3 && n1 != 7)
            continue;

        if (*it >= 100)
        {
            const int64_t n2 = d[s - 1] * 10 + d[s - 2];
            const auto it2 = std::lower_bound(itLimit1, itLimit2, n2);
            if (*it2 != n2)
                continue;

            const int64_t n3 = d[1] * 10 + d[0];
            const auto it3 = std::lower_bound(itLimit1, itLimit2, n3);
            if (*it3 != n3)
                continue;

            if (*it >= 1000)
            {
                const int64_t n4 = d[s - 1] * 100 + d[s - 2] * 10 + d[s - 3];
                const auto it4 = std::lower_bound(itLimit2, itLimit3, n4);
                if (*it4 != n4)
                    continue;

                const int64_t n5 = d[2] * 100 + d[1] * 10 + d[0];
                const auto it5 = std::lower_bound(itLimit2, itLimit3, n5);
                if (*it5 != n5)
                    continue;

                if (*it >= 10000)
                {
                    const int64_t n6 = d[s - 1] * 1000 + d[s - 2] * 100 + d[s - 3] * 10 + d[s - 4];
                    const auto it6 = std::lower_bound(itLimit3, itLimit4, n6);
                    if (*it6 != n6)
                        continue;

                    const int64_t n7 = d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
                    const auto it7 = std::lower_bound(itLimit3, itLimit4, n7);
                    if (*it7 != n7)
                        continue;

                    if (*it >= 100000)
                    {
                        const int64_t n8 = d[s - 1] * 10000 + d[s - 2] * 1000 + d[s - 3] * 100 + d[s - 4] * 10 + d[s - 5];
                        const auto it8 = std::lower_bound(itLimit4, itLimit5, n8);
                        if (*it8 != n8)
                            continue;

                        const int64_t n9 = d[4] * 10000 + d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
                        const auto it9 = std::lower_bound(itLimit4, itLimit5, n9);
                        if (*it9 != n9)
                            continue;
                    }
                }
            }
        }

        answer.push_back(*it);
    }

    return std::accumulate(answer.begin(), answer.end(), 0LL);
}
