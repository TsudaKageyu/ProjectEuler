#include "stdafx.h"
#include "utils.h"

#define DIG(d, n) Utils::GetDigit<int64_t, d>(n)

namespace
{
    // Checks if the number is palindromic like "123321".
    bool IsPalindromic(int64_t n)
    {
        assert(100 * 100 <= n && n <= 999 * 999);

        if (n < 100000)
            return (DIG(0, n) == DIG(4, n) && DIG(1, n) == DIG(3, n));
        else
            return (DIG(0, n) == DIG(5, n) && DIG(1, n) == DIG(4, n) && DIG(2, n) == DIG(3, n));
    }
}

int64_t Problem4()
{
    assert(IsPalindromic(123321));

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

            if (IsPalindromic(p))
                answer = p;
        }
    }

    return answer;
}
