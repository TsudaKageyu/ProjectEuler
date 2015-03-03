#include "common.h"
#include "problem5.h"

namespace
{
    int64_t GCD(int64_t a, int64_t b)
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

    int64_t LCM(int64_t a, int64_t b)
    {
        return a * b / GCD(a, b);
    }
}

namespace problem5
{
    void solve()
    {
        StopWatch sw;

        int64_t answer = 1;
        for (int i = 2; i <= 20; ++i)
            answer = LCM(answer, i);

        const auto time = sw.GetElapsedMilliseconds();
        std::cout << "Answer5: " << answer << time << std::endl;
    }
}
