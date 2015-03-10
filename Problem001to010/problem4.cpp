#include "stdafx.h"
#include "utils.h"

int64_t Problem4()
{
    assert(Utils::IsPalindromic(123321));

    int64_t answer = 0;

    for (int64_t i = 999; i >= 100; --i)
    {
        if (i <= answer / 999)
            break;

        for (int j = 999; j >= i; --j)
        {
            const int64_t p = i * j;
            if (p <= answer)
                break;

            if (Utils::IsPalindromic(p))
                answer = p;
        }
    }

    return answer;
}
