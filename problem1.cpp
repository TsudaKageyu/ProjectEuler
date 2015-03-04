#include "common.h"
#include "problem1.h"

namespace
{
    // Returns the sum of all the natural numbers no more than N.
    template <int N>
    int GetSumOfNaturalNumbers()
    {
        return (N + 1) * N / 2;
    }

    // Returns the sum of all the natural number multiples of N no more than L.
    template <int N, int L>
    int GetSumOfNaturalNumberMultiples()
    {
        return N * GetSumOfNaturalNumbers<L / N>();
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
