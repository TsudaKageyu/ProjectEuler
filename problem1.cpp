#include "common.h"
#include "problem1.h"

namespace
{
    // Returns the sum of all the natural number multiples of N no more than L.
    template <int64_t N, int64_t L>
    int64_t GetSumOfNaturalNumberMultiples()
    {
        return N * Utils::GetSumOfNaturalNumbers(L / N);
    }
}

int64_t Problem1()
{
    return GetSumOfNaturalNumberMultiples< 3, 999>()
         + GetSumOfNaturalNumberMultiples< 5, 999>()
         - GetSumOfNaturalNumberMultiples<15, 999>();
}
