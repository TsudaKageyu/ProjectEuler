#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

int64_t Problem39()
{
    const size_t Limit = 1000;
    const double MaxI  = sqrt(Limit / 2.0 - 0.25) - 0.5;

    vector<int32_t> perimeters;

    for (int32_t i = 1; i < MaxI; ++i)
    {
        for (int32_t j = 1 + (i & 1); j < i; j += 2)
            perimeters.push_back(2 * (i * i + i * j));
    }

    vector<int32_t> counts(Limit + 1);

    for (const auto &p : perimeters)
    {
        for (int32_t i = p; i <= Limit; i += p)
            counts[i]++;
    }

    return (max_element(counts.begin(), counts.end()) - counts.begin());
}
