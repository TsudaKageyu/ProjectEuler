#include <cstdint>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

int64_t Problem39()
{
    const size_t Limit = 1000;

    vector<array<int32_t, 3>> triplets;

    for (int32_t i = 1; i <= 50; ++i)
    {
        for (int32_t j = 1 + (i & 1); j < i; j += 2)
        {
            const array<int32_t, 3> t = { i * i - j * j, 2 * i * j, i * i + j * j };
            triplets.push_back(t);
        }
    }

    vector<int32_t> counts(Limit + 1);

    for (const auto &t : triplets)
    {
        const int32_t p = t[0] + t[1] + t[2];

        for (int32_t i = p; i <= Limit; i += p)
            counts[i]++;
    }

    return (max_element(counts.begin(), counts.end()) - counts.begin());
}
