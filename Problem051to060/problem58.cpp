#include "stdafx.h"
#include "utils.h"

int64_t Problem58()
{
    using boost::multiprecision::cpp_int;
    using boost::multiprecision::miller_rabin_test;

    int64_t answer = 0;

    cpp_int num        = 1;
    int64_t numCount   = 1;
    int64_t primeCount = 0;

    for (int64_t i = 1; ; ++i)
    {
        for (int64_t j = 0; j < 4; ++j)
        {
            num += i * 2;

            if (miller_rabin_test(num, 10))
                primeCount++;
        }

        numCount += 4;

        if (primeCount * 100 / numCount < 10)
        {
            answer = i * 2 + 1;
            break;
        }
    }

    return answer;
}
