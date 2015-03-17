#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::cpp_int;

namespace
{
    size_t GetDigitCount(cpp_int n)
    {
        return n.str().size();
    }
}

int64_t Problem57()
{
    int64_t answer = 0;

    cpp_int nom   = 1;
    cpp_int denom = 2;

    for (int64_t i = 2; i <= 1000; ++i)
    {
        nom += denom * 2;
        nom.swap(denom);

        if (GetDigitCount(nom + denom) > GetDigitCount(denom))
            answer++;
    }

    return answer;
}
