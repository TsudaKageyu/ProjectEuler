#include "stdafx.h"
#include "utils.h"

namespace
{
    // The length of words "one", "two", ... "nineteen"
    const std::array<int, 20> DaysOfMonths = {
        0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };

    // The length of words "twenty", "thirty", ... "ninety"
    const std::array<int, 10> Table2 = {
        0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };
}

int64_t Problem17()
{
    int64_t answer = 0;

    for (int h = 0; h < 10; ++h)
    {
        for (int n = 0; n < 100; ++n)
        {
            if (h >= 1)
            {
                answer += (DaysOfMonths[h] + 7);  // "one"..."nine" + "hundred"

                if (n >= 1)
                    answer += 3;            // "and"
            }

            if (n < 20)
            {
                answer += DaysOfMonths[n];        // "one"..."nineteen"
            }
            else
            {
                answer += Table2[n / 10];   // "twenty"..."ninety"
                answer += DaysOfMonths[n % 10];   // "one"..."nine"
            }
        }
    }

    answer += 11;   // "one thousand"

    return answer;
}
