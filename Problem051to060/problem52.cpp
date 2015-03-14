#include "stdafx.h"
#include "utils.h"

int64_t Problem52()
{
    for (int64_t n = 100000; n <= 166666; ++n)
    {
        const std::array<int64_t, 6> d =
        {
            Utils::GetDigit<int64_t, 0>(n),
            Utils::GetDigit<int64_t, 1>(n),
            Utils::GetDigit<int64_t, 2>(n),
            Utils::GetDigit<int64_t, 3>(n),
            Utils::GetDigit<int64_t, 4>(n),
            Utils::GetDigit<int64_t, 5>(n)
        };

        for (int64_t m = 2; m < 6; ++m)
        {
            const int64_t n2 = n * m;

            std::array<int64_t, 6> d2 =
            {
                Utils::GetDigit<int64_t, 0>(n2),
                Utils::GetDigit<int64_t, 1>(n2),
                Utils::GetDigit<int64_t, 2>(n2),
                Utils::GetDigit<int64_t, 3>(n2),
                Utils::GetDigit<int64_t, 4>(n2),
                Utils::GetDigit<int64_t, 5>(n2)
            };

            for (int64_t i : d)
            {
                const auto it = std::find(d2.begin(), d2.end(), i);
                if (it == d2.end())
                    goto NEXT;

                *it = -1;
            }
        }

        return n;

    NEXT:
        ;
    }

    return 0;
}
