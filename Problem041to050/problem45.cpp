#include "stdafx.h"
#include "utils.h"

namespace
{
    bool IsIntegral(double x)
    {
        return (x == std::floor(x));
    }

    bool IsPentagonal(int64_t x)
    {
        const double tmp = std::sqrt(6.0 * x + 0.25) + 0.5;
        if (!IsIntegral(tmp))
            return false;

        return IsIntegral(tmp / 3.0);
    }
}

int64_t Problem45()
{
    int64_t t = 40755; // 143th hexagonal number.

    for (int64_t n = 144; ; ++n)
    {
        t += n * 4 - 3;

        if (IsPentagonal(t))
            return t;
    }
}
