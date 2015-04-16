#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

int64_t Problem39()
{
    const size_t Limit = 1000;

    vector<int32_t> perimeters;

    for (int32_t i = 1; i <= 30; ++i)
    {
        for (int32_t j = 1 + (i & 1); j < i; j += 2)
            perimeters.push_back((i * i - j * j) + (2 * i * j) + (i * i + j * j));
    }

    vector<int32_t> counts(Limit + 1);

    for (const auto &p : perimeters)
    {
        for (int32_t i = p; i <= Limit; i += p)
            counts[i]++;
    }

    return (max_element(counts.begin(), counts.end()) - counts.begin());
}
