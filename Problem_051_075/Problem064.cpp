#include <cstdint>
#include <algorithm>

int64_t Problem64()
{
    int32_t answer = 0;

    for (int32_t s = 2; s < 10000; ++s)
    {
        const int32_t a0 = static_cast<int32_t>(sqrt(s));
        if (a0 * a0 == s)
            continue;

        int32_t p = 0;
        int32_t m = 0;
        int32_t d = 1;
        int32_t a = a0;

        while (true)
        {
            p++;

            m = d * a - m;
            d = (s - m * m) / d;
            a = (a0 + m) / d;
            if (a == a0 * 2)
                break;
        }

        if (p & 1)
            answer++;
    }

    return answer;
}
