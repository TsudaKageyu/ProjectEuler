#include <iostream>
#include <array>
#include "problem2.h"
#include "stopwatch.h"

namespace
{
}

namespace problem2
{
    void calc()
    {
        StopWatch sw;

        int answer = 0;
        std::array<int, 2> buf = { 1, 2 };

        do
        {
            if ((buf[1] & 1) == 0)
                answer += buf[1];

            const int next = buf[0] + buf[1];
            buf[0] = buf[1];
            buf[1] = next;
        } while (buf[1] <= 4000000);

        const double epalsed = sw.GetElapsedMilliseconds();
        std::cout << "Answer2: " << answer << " (" << epalsed << " ms)" << std::endl;
    }
}
