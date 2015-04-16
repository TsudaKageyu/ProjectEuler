#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

int64_t Problem39()
{
    const size_t  Limit = 1000;
    const int32_t MaxI  = static_cast<int32_t>(sqrt(Limit / 2.0 - 0.25) - 0.5);

    vector<int32_t> counts(Limit + 1);

    for (int32_t i = 1; i <= MaxI; ++i)
    {
        for (int32_t j = 1 + (i & 1); j < i; j += 2)
        {
            const int32_t p = 2 * (i * i + i * j);
            if (p > Limit)
                break;

            for (int32_t k = p; k <= Limit; k += p)
                counts[k]++;
        }
    }

    return (max_element(counts.begin(), counts.end()) - counts.begin());
}
