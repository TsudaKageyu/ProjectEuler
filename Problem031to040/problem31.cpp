#include "stdafx.h"
#include "utils.h"

int64_t Problem31()
{
    int64_t answer = 0;

    for (int64_t a = 0; a <= 200 / 200; ++a)
    {
        const int64_t maxB = 2 - 2 * a;

        for (int64_t b = 0; b <= maxB; ++b)
        {
            const int64_t maxC = 4 - 4 * a - 2 * b;

            for (int64_t c = 0; c <= maxC; ++c)
            {
                const int64_t maxD = (20 - 20 * a - 10 * b - 5 * c) / 2;

                for (int64_t d = 0; d <= maxD; ++d)
                {
                    const int64_t maxE = 20 - 20 * a - 10 * b - 5 * c - 2 * d;

                    for (int64_t e = 0; e <= maxE; ++e)
                    {
                        const int64_t maxF = 40 - 40 * a - 20 * b - 10 * c - 4 * d - 2 * e;

                        for (int64_t f = 0; f <= maxF; ++f)
                            answer += ((200 - 200 * a - 100 * b - 50 * c - 20 * d - 10 * e - 5 * f) / 2) + 1;
                    }
                }
            }
        }
    }

    return answer;
}
