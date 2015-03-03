#include <cassert>
#include <algorithm>
#include <iostream>

#include "problem5.h"
#include "stopwatch.h"

namespace
{
    long long gcd(long long a, long long b)
    {
        while (true)
        {
            const auto d = std::div(a, b);
            if (d.rem == 0)
                return b;

            a = b;
            b = d.rem;
        }
    }

    long long lcm(long long a, long long b)
    {
        return a * b / gcd(a, b);
    }
}

namespace problem5
{
    void calc()
    {
        StopWatch sw;

        long long answer = 1;
        for (int i = 2; i <= 20; ++i)
            answer = lcm(answer, i);

        const auto time = sw.GetElapsedMilliseconds();
        std::cout << "Answer5: " << answer << time << std::endl;
    }
}
