#include "../common.h"

int64_t Problem9()
{
    for (int64_t a = 1; a <= 999; ++a)
    {
        for (int64_t b = a + 1; b <= 999; ++b)
        {
            for (int64_t c = b + 1; c <= 998; ++c)
            {
                if (a + b + c != 1000)
                    continue;

                if (a * a + b * b != c * c)
                    continue;

                return a * b * c;
            }
        }
    }

    return 0;
}
