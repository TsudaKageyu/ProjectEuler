#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::cpp_int;
using boost::multiprecision::cpp_dec_float_50;
using boost::multiprecision::log10;

int64_t Problem25()
{
    int64_t answer = 3;

    std::array<cpp_int, 2> buf = { 1, 1 };

    while (true)
    {
        const cpp_int next = buf[0] + buf[1];
        if (log10(cpp_dec_float_50(next)) >= cpp_dec_float_50(999.0))
            return answer;

        buf[0] = buf[1];
        buf[1] = next;

        answer++;
    }
}
