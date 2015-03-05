#include "stdafx.h"
#include "utils.h"

int64_t Problem9()
{
    for (int64_t a = 1; a <= 995; ++a)
    {
        for (int64_t b = a + 1; b <= 998 - a; ++b)
        {
            const int64_t c = 1000 - a - b;

            if (a * a + b * b != c * c)
                continue;

            return a * b * c;
        }
    }

    return 0;
}
