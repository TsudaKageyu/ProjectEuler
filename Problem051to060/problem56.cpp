#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::cpp_int;
using boost::multiprecision::pow;
using boost::multiprecision::integer_modulus;

int64_t Problem56()
{
    int64_t answer = 0;

    for (int64_t a = 99; a >= 2; --a)
    {
        for (uint32_t b = 99; b >= 2; --b)
        {
            cpp_int p = pow(cpp_int(a), b);

            int64_t sum    = 0;
            int64_t digits = 0;
            do
            {
                sum += integer_modulus(p, 10);
                digits++;

                p /= 10;
            }
            while (p != 0);

            if (sum > answer)
                answer = sum;

            if (digits < answer / 10)
                break;
        }
    }

    return answer;
}
