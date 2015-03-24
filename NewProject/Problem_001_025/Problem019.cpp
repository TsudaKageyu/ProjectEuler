#include <cstdint>
#include <array>

namespace
{
    const std::array<int32_t, 13> DayOfMonths = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
}

int64_t Problem19()
{
    int32_t days   = 1; // 0 = Sunday, 1 = Monday, and so forth.
    int32_t answer = 0;

    for (int32_t y = 1901; y <= 2000; ++y)
    {
        for (int32_t m = 1; m <= 12; ++m)
        {
            if (days % 7 == 0)
                answer++;

            days += DayOfMonths[m];
            if (y % 4 == 0 && m == 2)
                days++;
        }
    }

    if (days % 7 == 0)
        answer--;

    return answer;
}
