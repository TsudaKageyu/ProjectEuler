#include "stdafx.h"
#include "utils.h"

using boost::rational;

int64_t Problem33()
{
    std::vector<int64_t> nums;
    std::vector<int64_t> dens;

    for (int64_t d = 11; d <= 99; ++d)
    {
        const int64_t d1 = d % 10;
        const int64_t d2 = d / 10;

        if (d1 == 0)
            continue;

        for (int64_t n = 10; n < d; ++n)
        {
            const int64_t n1 = n % 10;
            const int64_t n2 = n / 10;

            rational<int64_t> r;
            if (n1 == d1)
                r = rational<int64_t>(n2, d2);
            else if (n1 == d2)
                r = rational<int64_t>(n2, d1);
            else if (n2 == d1)
                r = rational<int64_t>(n1, d2);
            else if (n2 == d2)
                r = rational<int64_t>(n1, d1);
            else
                continue;

            if (r != rational<int64_t>(n, d))
                continue;

            nums.push_back(n);
            dens.push_back(d);
        }
    }

    assert(nums.size() == 4);
    assert(dens.size() == 4);

    const int64_t num = std::accumulate(nums.begin(), nums.end(), 1LL, std::multiplies<int64_t>());
    const int64_t den = std::accumulate(dens.begin(), dens.end(), 1LL, std::multiplies<int64_t>());
    const int64_t gcd = Utils::GCD(num, den);

    return den / gcd;
}
