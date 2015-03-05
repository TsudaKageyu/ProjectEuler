#include "stdafx.h"
#include "utils.h"

int64_t Problem2()
{
    int64_t answer = 0;
    std::array<int64_t, 2> buf = { 1, 2 };

    do
    {
        if ((buf[1] & 1) == 0)
            answer += buf[1];

        const int64_t next = buf[0] + buf[1];
        buf[0] = buf[1];
        buf[1] = next;
    } while (buf[1] <= 4000000);

    return answer;
}
