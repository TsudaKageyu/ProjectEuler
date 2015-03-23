#include "stdafx.h"
#include "utils.h"

int64_t Problem97()
{
    const int64_t M = 10000000000;
    const int64_t Bits = 28;

    int64_t n = 28433;
    int64_t e = 7830457;

    while (e >= Bits)
    {
        n *= (1LL << Bits);
        n %= M;

        e -= Bits;
    }

    n *= (1LL << e);
    n++;
    n %= M;

    return n;
}
