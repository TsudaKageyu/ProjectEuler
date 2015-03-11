#include "stdafx.h"
#include "utils.h"

int64_t Problem38()
{
    // We have a magic number 918273645 :P

    char buf1[10] = "918273645";
    char buf2[10] = "000000000";

    char *p1 = buf1;
    char *p2 = buf2;

    for (int n = 9183; n <= 9999; ++n)
    {
        if (n % 10 == 0 || n % 10 == 5)
            continue;

        ::sprintf_s(p2 + 0, 5, "%d", n);
        ::sprintf_s(p2 + 4, 6, "%d", n * 2);

        for (size_t i = 0; i < 9; ++i)
        {
            if (p2[i] == '0')
                goto SKIP;

            for (size_t j = i + 1; j < 9; ++j)
            {
                if (p2[i] == p2[j])
                    goto SKIP;
            }
        }

        if (::strcmp(p2, p1) > 0)
            std::swap(p1, p2);
    SKIP:
        ;
    }

    return ::atoll(p1);
}
