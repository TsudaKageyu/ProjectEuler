#include <cstdint>
#include <algorithm>

namespace
{
    bool IsTriangle(int64_t x)
    {
        const double n = sqrt(2.0 * x + 0.25) - 0.5;
        return (n == floor(n));
    }

    bool IsPentagonal(int64_t x)
    {
        const double n = (sqrt(24.0 * x + 1.0) + 1.0) / 6.0;
        return (n == floor(n));
    }
}

int64_t Problem45()
{
    int64_t h = 40755;

    for (int64_t i = 573;; i += 4)
    {
        h += i;

        if (!IsTriangle(h))
            continue;

        if (!IsPentagonal(h))
            continue;

        return h;
    }
}
