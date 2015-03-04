#include "common.h"

namespace problem6
{
    void Solve()
    {
        StopWatch sw;

        const int64_t num = 100;

        int64_t sum = 0;
        for (int64_t i = 1; i <= num; ++i)
            sum += i * i;

        int64_t sqr = Utils::GetSumOfNaturalNumbers(num);
        sqr *= sqr;

        int64_t answer = sqr - sum;

        const auto time = sw.GetElapsedMilliseconds();
        Utils::PrintResult(6, answer, time);
    }
}
