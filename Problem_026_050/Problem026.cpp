#include <cstdint>
#include <vector>

using namespace std;

int64_t Problem26()
{
    size_t  cycle    = 0;
    size_t  maxCycle = 0;
    int32_t answer   = 0;

    for (int32_t d = 2; d < 1000; ++d)
    {
        int32_t m = 1;

        vector<int32_t> mods;
        while (true)
        {
            while (m < d)
                m *= 10;

            m = m % d;
            if (m == 0)
                break;

            const auto it = find(mods.begin(), mods.end(), m);
            if (it != mods.end())
            {
                cycle = distance(it, mods.end());
                break;
            }

            mods.push_back(m);
        }

        if (m == 0)
            continue;

        if (cycle <= maxCycle)
            continue;

        maxCycle = cycle;
        answer = d;
    }

    return answer;
}
