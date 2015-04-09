#include <cstdint>
#include <algorithm>
#include <array>
#include <numeric>
#include <vector>
#include <boost/range/algorithm_ext/erase.hpp>

using namespace std;
using namespace boost::range;

namespace
{
    vector<int32_t> GetPolygonalNumbers(int32_t x)
    {
        vector<int32_t> nums;

        int32_t n = 1;
        for (int32_t i = 1;; ++i)
        {
            if (n > 9999)
                break;
            else if (n >= 1000)
                nums.push_back(n);

            n += i * (x - 2) + 1;
        }

        return nums;
    }

    void RemoveNonCyclic(vector<int32_t> &a, vector<int32_t> &b)
    {
        remove_erase_if(a, [&](const int32_t x) {
            return !any_of(b.begin(), b.end(), [&](int32_t y) {
                return (x / 100 == y % 100); });
        });
    }
}

int64_t Problem61()
{
    const array<vector<int32_t>, 6> n = {
        GetPolygonalNumbers(3),
        GetPolygonalNumbers(4),
        GetPolygonalNumbers(5),
        GetPolygonalNumbers(6),
        GetPolygonalNumbers(7),
        GetPolygonalNumbers(8)
    };

    array<size_t, 6> o = { 0, 1, 2, 3, 4, 5 };

    do
    {
        auto t = n;

        while (true)
        {
            RemoveNonCyclic(t[o[0]], t[o[5]]);
            RemoveNonCyclic(t[o[1]], t[o[0]]);
            RemoveNonCyclic(t[o[2]], t[o[1]]);
            RemoveNonCyclic(t[o[3]], t[o[2]]);
            RemoveNonCyclic(t[o[4]], t[o[3]]);
            RemoveNonCyclic(t[o[5]], t[o[4]]);

            if (any_of(t.begin(), t.end(), [](const vector<int32_t> &v) { return v.empty(); }))
                break;

            if (all_of(t.begin(), t.end(), [](const vector<int32_t> &v) { return (v.size() == 1); }))
            {
                int32_t sum = 0;
                for (const auto &v : t)
                    sum += v.front();

                return sum;
            }
        }

    } while (next_permutation(o.begin(), o.end()));

    return 0;
}
