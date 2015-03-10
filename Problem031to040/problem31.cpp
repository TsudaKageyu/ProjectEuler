#include "stdafx.h"
#include "utils.h"

int64_t Problem31()
{
    const std::array<int64_t, 7> Coins = { 200, 100, 50, 20, 10, 5, 2 };

    int64_t answer = 0;

    const int64_t Amount = 200;
    const int64_t maxA = Amount / Coins[0];

    for (int64_t a = 0; a <= maxA; ++a)
    {
        const int64_t restA = Amount - Coins[0] * a;
        const int64_t maxB  = restA / Coins[1];

        for (int64_t b = 0; b <= maxB; ++b)
        {
            const int64_t restB = restA - Coins[1] * b;
            const int64_t maxC  = restB / Coins[2];

            for (int64_t c = 0; c <= maxC; ++c)
            {
                const int64_t restC = restB - Coins[2] * c;
                const int64_t maxD  = restC / Coins[3];

                for (int64_t d = 0; d <= maxD; ++d)
                {
                    const int64_t restD = restC - Coins[3] * d;
                    const int64_t maxE  = restD / Coins[4];

                    for (int64_t e = 0; e <= maxE; ++e)
                    {
                        const int64_t restE = restD - Coins[4] * e;
                        const int64_t maxF  = restE / Coins[5];

                        for (int64_t f = 0; f <= maxF; ++f)
                        {
                            const int64_t restF = restE - Coins[5] * f;
                            const int64_t maxG  = restF / Coins[6];

                            answer += maxG + 1;
                        }
                    }
                }
            }
        }
    }

    return answer;
}
