#include <cstdint>
#include <array>

int64_t Problem30()
{
    int64_t answer = 0;

    for (int32_t n = 10; n <= 354294; ++n)
    {
        int32_t t = n;
        int32_t m = 0;

        while (t != 0)
        {
            const int32_t d = (t % 10);
            t /= 10;

            m += d * d * d * d * d;
            if (m > n)
                goto NEXT;
        }

        if (m == n)
            answer += n;

    NEXT:
        ;
    }

    return answer;
}
