#include "stdafx.h"
#include "utils.h"

int64_t Problem43()
{
    int64_t answer = 0;

    for (int64_t m17 = 102; m17 <= 999; m17 += 17)
    {
        std::array<bool, 10> used = {};

        const uint64_t d10 = m17 % 10;
        const uint64_t d9  = (m17 / 10) % 10;
        const uint64_t d8  = m17 / 100;

        used[d10] = true;

        if (used[d9])
            continue;

        used[d9] = true;

        if (used[d8])
            continue;

        used[d8] = true;

        for (int64_t d7 = 0; d7 <= 9; ++d7)
        {
            if (used[d7])
                continue;

            if ((d7 * 100 + m17 / 10) % 13 != 0)
                continue;

            used[d7] = true;

            for (int64_t d6 = 0; d6 <= 9; d6 += 5)
            {
                if (used[d6])
                    continue;

                if ((d6 * 100 + d7 * 10 + d8) % 11 != 0)
                    continue;

                used[d6] = true;

                for (int64_t d5 = 0; d5 <= 9; ++d5)
                {
                    if (used[d5])
                        continue;

                    if ((d5 * 100 + d6 * 10 + d7) % 7 != 0)
                        continue;

                    used[d5] = true;

                    for (int64_t d4 = 0; d4 <= 9; d4 += 2)
                    {
                        if (used[d4])
                            continue;

                        used[d4] = true;

                        for (int64_t d3 = 0; d3 <= 9; ++d3)
                        {
                            if (used[d3])
                                continue;

                            if ((d3 * 100 + d4 * 10 + d5) % 3 != 0)
                                continue;

                            used[d3] = true;

                            for (int64_t d2 = 0; d2 <= 9; ++d2)
                            {
                                if (used[d2])
                                    continue;

                                used[d2] = true;

                                for (int64_t d1 = 0; d1 <= 9; ++d1)
                                {
                                    if (used[d1])
                                        continue;

                                    answer += d1 * 1000000000LL
                                            + d2 * 100000000LL
                                            + d3 * 10000000LL
                                            + d4 * 1000000LL
                                            + d5 * 100000LL
                                            + d6 * 10000LL
                                            + d7 * 1000LL
                                            + d8 * 100LL
                                            + d9 * 10LL
                                            + d10;
                                }

                                used[d2] = false;
                            }
                            used[d3] = false;
                        }
                        used[d4] = false;
                    }
                    used[d5] = false;
                }
                used[d6] = false;
            }
            used[d7] = false;
        }
    }

    return answer;
}
