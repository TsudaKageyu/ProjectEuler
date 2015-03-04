#include <cassert>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <array>
#include <string>
#include <vector>

#include "stopwatch.h"

namespace Utils
{
    inline void PrintResult(int problem, int64_t answer, const std::string &time)
    {
        ::printf("Answer % 2d: % 10ld (% 14s)\n", problem, answer, time.c_str());
    }
}
