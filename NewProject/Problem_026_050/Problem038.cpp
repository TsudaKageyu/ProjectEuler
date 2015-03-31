#include <cstdint>

int64_t Problem38()
{
    int64_t answer = 0;

    for (int32_t i = 1; i <= 9876; ++i)
    {
        int64_t n = 0;
        int32_t u = 0;

        for (int32_t j = 1; ; ++j)
        {
            int32_t t = i * j;
            int32_t m = 1;

            while (t != 0)
            {
                u |= 1 << (t % 10);
                t /= 10;
                m *= 10;
            }

            n = n * m + i * j;

            if (n >= 100000000)
                break;
        }

        if (n > 987654321)
            continue;

        if (u != 0x3fe)
            continue;

        if (n > answer)
            answer = n;
    }

    return answer;
}
