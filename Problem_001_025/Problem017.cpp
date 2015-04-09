#include <cstdint>
#include <array>

namespace
{
    const std::array<int32_t, 20> OneToNineteen = {
        0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8  };

    const std::array<int32_t, 10> TwentyToNinety = {
        0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };

    const int32_t Hundred  = 7;
    const int32_t Thousand = 8;
    const int32_t And      = 3;
}

int64_t Problem17()
{
    int64_t answer = 0;

    for (int32_t h = 0; h <= 9; ++h)
    {
        if (h != 0)
            answer += OneToNineteen[h] + Hundred;

        for (int32_t n = 1; n <= 99; ++n)
        {
            if (h != 0)
                answer += OneToNineteen[h] + Hundred + And;

            if (n <= 19)
                answer += OneToNineteen[n];
            else
                answer += TwentyToNinety[n / 10] + OneToNineteen[n % 10];

        }
    }

    answer += OneToNineteen[1] + Thousand;

    return answer;
}
