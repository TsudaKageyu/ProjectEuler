#include "stdafx.h"
#include "utils.h"

int64_t Problem63()
{
    using namespace boost::multiprecision;

    int64_t answer = 0;

    for (cpp_int n = 1; n <= 9; ++n)
    {
        for (uint32_t i = 1; ; ++i)
        {
            const cpp_int p(pow(n, i));
            if (p.str().size() < i)
                break;

            answer++;
        }
    }

    return answer;
}
