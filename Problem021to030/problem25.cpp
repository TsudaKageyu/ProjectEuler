#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::cpp_int;
using boost::multiprecision::pow;

int64_t Problem25()
{
    const cpp_int Threshold = pow(cpp_int(10), 999);

    int64_t answer = 3;

    std::array<cpp_int, 2> buf = { 1, 1 };

    while (true)
    {
        const cpp_int next = buf[0] + buf[1];
        if (next >= Threshold)
            return answer;

        buf[0].swap(buf[1]);
        buf[1] = next;

        answer++;
    }
}
