#include "stdafx.h"
#include "utils.h"

namespace
{
    // Number of days in each month
    const std::array<int, 13> DaysOfMonths = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
}

int64_t Problem19()
{
    int64_t answer = 0;

    int64_t day = 2;    // 1 Jun 1901 is Tuesday. 0...6 as Sunday...Saturday.

    for (int64_t y = 1901; y <= 2000; ++y)
    {
        for (int64_t m = 1; m <= 12; ++m)
        {
            if (day % 7 == 0)
                answer++;

            day += DaysOfMonths[m];
            if (m == 2 && y % 4 == 0)   // This check works at least in the 20th century :P
                day++;
        }
    }

    return answer;
}
