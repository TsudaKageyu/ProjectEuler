#include "stdafx.h"
#include "utils.h"

int64_t Problem40()
{
    const std::array<int, 7> Power    = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
    const std::array<int, 7> Position = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

    int64_t answer = 1;

    for (const int pos : Position)
    {
        int p = pos - 1;
        int i;
        for (i = 1; ; ++i)
        {
            const int t = (Power[i] - Power[i - 1]) * i;
            if (p < t)
                break;

            p -= t;
        }

        const int d = p / i;
        const int r = p % i;
        const int n = ((Power[i - 1] + d) / Power[i - r - 1]) % 10;

        answer *= n;
    }

    return answer;
}
