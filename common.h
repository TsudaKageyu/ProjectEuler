#include <cassert>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <vector>

#include "stopwatch.h"

namespace Utils
{
    // -------------------------------------------------------------------------
    // Returns the sum of all the natural numbers no more than n.

    template <typename T>
    inline T GetSumOfNaturalNumbers(T n)
    {
        return (n + 1) * n / 2;
    }

    inline void PrintResult(int problem, int64_t answer, const std::string &time)
    {
        ::printf("Answer %2d: %10ld (%14s)\n", problem, answer, time.c_str());
    }
}
