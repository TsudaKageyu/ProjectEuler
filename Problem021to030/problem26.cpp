#include "stdafx.h"
#include "utils.h"

int64_t Problem26()
{
    int64_t answer  = 0;
    int64_t longest = 0;

    for (int64_t n = 2; n <= 999; ++n)
    {
        // Calculate 1/n by a method like long divison.

        std::vector<int64_t> mods = { 10 };

        while (true)
        {
            const auto m = (mods.back() % n) * 10;
            if (m == 0)
                break;

            const auto it = std::find(mods.begin(), mods.end(), m);
            if (it == mods.end())
            {
                mods.push_back(m);
                continue;
            }

            const auto len = (mods.end() - it);
            if (len > longest)
            {
                answer  = n;
                longest = len;
            }

            break;
        }
    }

    return answer;
}
