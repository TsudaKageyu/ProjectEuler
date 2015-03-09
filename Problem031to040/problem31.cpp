#include "stdafx.h"
#include "utils.h"

int64_t Problem31()
{
    const int64_t amount = 200;
    int64_t answer = 0;

    const int64_t maxA = amount / 200;

    for (int64_t a = 0; a <= maxA; ++a)
    {
        const int64_t maxB = (amount - 200 * a) / 100;

        for (int64_t b = 0; b <= maxB; ++b)
        {
            const int64_t maxC = (amount - 200 * a - 100 * b) / 50;

            for (int64_t c = 0; c <= maxC; ++c)
            {
                const int64_t maxD = (amount - 200 * a - 100 * b - 50 * c) / 20;

                for (int64_t d = 0; d <= maxD; ++d)
                {
                    const int64_t maxE = (amount - 200 * a - 100 * b - 50 * c - 20 * d) / 10;

                    for (int64_t e = 0; e <= maxE; ++e)
                    {
                        const int64_t maxF = (amount - 200 * a - 100 * b - 50 * c - 20 * d - 10 * e) / 5;

                        for (int64_t f = 0; f <= maxF; ++f)
                            answer += ((amount - 200 * a - 100 * b - 50 * c - 20 * d - 10 * e - 5 * f) / 2) + 1;
                    }
                }
            }
        }
    }

    return answer;
}
