#include <cstdint>
#include <unordered_map>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>

using namespace std;
using namespace boost::multiprecision;

namespace
{
    const int64_t Limit = 100000;

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

    vector<int64_t> FindPairs(int64_t s)
    {
        assert(miller_rabin_test(s, 0));

        std::vector<int64_t> tmp;
        tmp.reserve(Limit - s);

        for (int64_t p = s + 2; p < Limit; ++p)
        {
            if (miller_rabin_test(cpp_int(p), 0) && IsPair(s, p))
                tmp.push_back(p);
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
    int64_t answer = Limit * 5;

    std::unordered_map<int64_t, std::vector<int64_t>> pairs;

    for (int64_t i = 3; i < Limit; i += 2)
    {
        if (!miller_rabin_test(cpp_int(i), 0))
            continue;

        auto pi = pairs.find(i);
        if (pi == pairs.end())
            pairs[i] = FindPairs(i);

        const auto &vi = pairs[i];

        for (const auto j : vi)
        {
            auto pj = pairs.find(j);
            if (pj == pairs.end())
                pairs[j] = FindPairs(j);

            const auto &vj = pairs[j];

            for (const auto k : vj)
            {
                if (find(vi.begin(), vi.end(), k) == vi.end())
                    continue;

                auto pk = pairs.find(k);
                if (pk == pairs.end())
                    pairs[k] = FindPairs(k);

                const auto &vk = pairs[k];

                for (const auto l : vk)
                {
                    if (find(vi.begin(), vi.end(), l) == vi.end())
                        continue;

                    if (find(vj.begin(), vj.end(), l) == vj.end())
                        continue;

                    auto pl = pairs.find(l);
                    if (pl == pairs.end())
                        pairs[l] = FindPairs(l);

                    const auto &vl = pairs[l];

                    for (const auto m : vl)
                    {
                        if (find(vi.begin(), vi.end(), m) == vi.end())
                            continue;

                        if (find(vj.begin(), vj.end(), m) == vj.end())
                            continue;

                        if (find(vk.begin(), vk.end(), m) == vk.end())
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
