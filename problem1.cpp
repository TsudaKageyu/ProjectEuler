#include "common.h"

namespace
{
    // Returns the sum of all the natural number multiples of N no more than L.
    template <int N, int L>
    int GetSumOfNaturalNumberMultiples()
    {
        return N * Utils::GetSumOfNaturalNumbers(L / N);
    }
}

namespace problem1
{
    void Solve()
    {
        const int answer
            = GetSumOfNaturalNumberMultiples<3, 999>()
            + GetSumOfNaturalNumberMultiples<5, 999>()
            - GetSumOfNaturalNumberMultiples<15, 999>();

        Utils::PrintResult(1, answer, "Calculated at compile time");
    }
}
