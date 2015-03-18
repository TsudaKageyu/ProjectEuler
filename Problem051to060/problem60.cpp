#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::cpp_int;
using boost::multiprecision::miller_rabin_test;

namespace
{
    cpp_int Concat(int64_t x, int64_t y)
    {
        assert(y > 0);

        if (y < 10)
            return x * 10 + y;
        else if (y < 100)
            return x * 100 + y;
        else if (y < 1000)
            return x * 1000 + y;
        else if (y < 10000)
            return x * 10000 + y;
        else if (y < 100000)
            return x * 100000 + y;

        assert(false);
        return 0;
    }

    bool IsPair(int64_t a, int64_t b)
    {
        if (!miller_rabin_test(Concat(a, b), 0))
            return false;

        if (!miller_rabin_test(Concat(b, a), 0))
            return false;

        return true;
    }

    std::vector<int64_t> FindPairs(int64_t s, int64_t e)
    {
        static const auto &primes = Utils::GetPrimeTable();

        const auto itMin = std::lower_bound(primes.begin(), primes.end(), s);
        const auto itMax = std::lower_bound(primes.begin(), primes.end(), e);

        std::vector<int64_t> tmp;
        tmp.reserve(itMax - itMin - 1);

        for (auto it = itMin + 1; it < itMax; ++it)
        {
            if (IsPair(*it, s))
                tmp.push_back(*it);
        }

        return tmp;
    }

    bool Contains(const std::vector<int64_t> &v, int64_t x)
    {
        const auto it = std::lower_bound(v.begin(), v.end(), x);
        return (it != v.end() && *it == x);
    }
}

int64_t Problem60()
{
    using namespace boost::multiprecision;

    const int64_t Limit = 50000;

    const auto &primes = Utils::GetPrimeTable();
    const auto itMax = std::lower_bound(primes.begin(), primes.end(), Limit);

    int64_t answer = std::numeric_limits<int64_t>::max();

    std::unordered_map<int64_t, std::vector<int64_t>> pairs;

    for (const auto i : primes)
    {
        if (i == 2 || i == 5)
            continue;

        if (i > Limit)
            break;

        auto pi = pairs.find(i);
        if (pi == pairs.end())
            pairs[i] = FindPairs(i, *itMax);

        const auto &vi = pairs[i];

        for (const auto j : vi)
        {
            auto pj = pairs.find(j);
            if (pj == pairs.end())
                pairs[j] = FindPairs(j, *itMax);

            const auto &vj = pairs[j];

            for (const auto k : vj)
            {
                if (!Contains(vi, k))
                    continue;

                auto pk = pairs.find(k);
                if (pk == pairs.end())
                    pairs[k] = FindPairs(k, *itMax);

                const auto &vk = pairs[k];

                for (const auto l : vk)
                {
                    if (!Contains(vi, l))
                        continue;

                    if (!Contains(vj, l))
                        continue;

                    auto pl = pairs.find(l);
                    if (pl == pairs.end())
                        pairs[l] = FindPairs(l, *itMax);

                    const auto &vl = pairs[l];

                    for (const auto m : vl)
                    {
                        if (!Contains(vi, m))
                            continue;

                        if (!Contains(vj, m))
                            continue;

                        if (!Contains(vk, m))
                            continue;

                        if (!miller_rabin_test(cpp_int(i), 25))
                            continue;

                        if (!miller_rabin_test(cpp_int(j), 25))
                            continue;

                        if (!miller_rabin_test(cpp_int(k), 25))
                            continue;

                        if (!miller_rabin_test(cpp_int(l), 25))
                            continue;

                        if (!miller_rabin_test(cpp_int(m), 25))
                            continue;

                        int64_t tmp = i + j + k + l + m;
                        if (tmp < answer)
                            answer = tmp;
                    }
                }
            }
        }
    }

    return answer;
}
