#include "stdafx.h"
#include "utils.h"

int64_t Problem48()
{
    const int64_t modulo = 10000000000;

    int64_t sum = 0;

    for (int64_t i = 1; i <= 1000; ++i)
    {
        int64_t num = i;
        for (int64_t j = 1; j < i; ++j)
        {
            num *= i;
            num %= modulo;
        }

        sum += num;
        sum %= modulo;
    }

    return sum;
}
