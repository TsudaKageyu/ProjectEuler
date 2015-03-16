#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::cpp_int;

int64_t Problem53()
{
    cpp_int answer = 0;

    for (cpp_int n = 23; n <= 100; ++n)
    {
        cpp_int num = 1;
        cpp_int den = 1;

        for (cpp_int r = 1; r <= (n + 1) / 2; ++r)
        {
            num *= (n - r + 1);
            den *= r;
            if (num / den > cpp_int(1000000))
            {
                answer += (n - r * 2 + 1);
                break;
            }
        }
    }

    return static_cast<int64_t>(answer);
}