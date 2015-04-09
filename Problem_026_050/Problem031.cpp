#include <cstdint>
#include <array>

int64_t Problem31()
{
    const std::array<int32_t, 7> Coins = { 200, 100, 50, 20, 10, 5, 2 };
    const int32_t Amount = 200;

    int32_t answer = 0;

    const int32_t maxA = Amount / Coins[0];

    for (int32_t a = 0; a <= maxA; ++a)
    {
        const int32_t restA = Amount - Coins[0] * a;
        const int32_t maxB  = restA / Coins[1];

        for (int32_t b = 0; b <= maxB; ++b)
        {
            const int32_t restB = restA - Coins[1] * b;
            const int32_t maxC  = restB / Coins[2];

            for (int32_t c = 0; c <= maxC; ++c)
            {
                const int32_t restC = restB - Coins[2] * c;
                const int32_t maxD  = restC / Coins[3];

                for (int32_t d = 0; d <= maxD; ++d)
                {
                    const int32_t restD = restC - Coins[3] * d;
                    const int32_t maxE  = restD / Coins[4];

                    for (int32_t e = 0; e <= maxE; ++e)
                    {
                        const int32_t restE = restD - Coins[4] * e;
                        const int32_t maxF  = restE / Coins[5];

                        for (int32_t f = 0; f <= maxF; ++f)
                        {
                            answer += (restE - Coins[5] * f) / Coins[6] + 1;
                        }
                    }
                }
            }
        }
    }

    return answer;
}
