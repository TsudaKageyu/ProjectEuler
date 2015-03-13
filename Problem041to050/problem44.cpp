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

int64_t Problem44()
{
    std::vector<int64_t> ps;
    ps.reserve(3000);

    int64_t p = 1;
    for (int64_t i = 0; i < 3000; ++i)
    {
        ps.push_back(p);
        p += (i + 1) * 3 + 1;
    }

    for (size_t i = 0; i < ps.size(); ++i)
    {
        for (size_t j = i + 1; j < ps.size(); ++j)
        {
            const int64_t sum = ps[j] + ps[i];
            if (!IsPentagonal(sum))
                continue;

            const int64_t diff = ps[j] - ps[i];
            if (!IsPentagonal(diff))
                continue;

            return diff;
        }
    }

    return 0;
}
