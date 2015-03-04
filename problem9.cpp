#include "common.h"

namespace problem9
{
    void Solve()
    {
        StopWatch sw;

        int64_t answer = 0;

        for (int64_t a = 1; a <= 999; ++a)
        {
            for (int64_t b = a + 1; b <= 999; ++b)
            {
                for (int64_t c = b + 1; c <= 998; ++c)
                {
                    if (a + b + c != 1000)
                        continue;

                    if (a * a + b * b != c * c)
                        continue;

                    answer = a * b * c;
                    goto exit_loop;
                }
            }
        }

    exit_loop:
        const auto time = sw.GetElapsedMilliseconds();
        Utils::PrintResult(9, answer, time);
    }
}
