#include <cstdint>
#include <array>

using namespace std;

int64_t Problem40()
{
    const array<int32_t, 7> Power    = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
    const array<int32_t, 7> Position = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

    int32_t answer = 1;

    for (const int32_t pos : Position)
    {
        int32_t p = pos - 1;
        int32_t i;
        for (i = 1;; ++i)
        {
            const int32_t t = (Power[i] - Power[i - 1]) * i;
            if (p < t)
                break;

            p -= t;
        }

        const int32_t d = p / i;
        const int32_t r = p % i;
        const int32_t n = ((Power[i - 1] + d) / Power[i - r - 1]) % 10;

        answer *= n;
    }

    return answer;
}
