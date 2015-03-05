#include "stdafx.h"
#include "utils.h"

int64_t Problem9()
{
    for (int64_t a = 1; a < 1000 / 2; ++a)
    {
        const int64_t tmp1 = 1000000LL - 2000 * a;
        const int64_t tmp2 = 2000LL - 2 * a;
        if (tmp1 % tmp2 != 0)
            continue;

        const int64_t b = tmp1 / tmp2;
        const int64_t c = 1000LL - a - b;

        return a * b * c;
    }

    return 0;
}
