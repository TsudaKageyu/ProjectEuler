#include <cstdint>
#include <numeric>
#include <set>

using namespace std;

namespace
{
    bool IsPandigital(int32_t a, int32_t b, int32_t c)
    {
        int32_t flags = 0;

        const auto setFlags = [&](int32_t x)
        {
            while (x != 0)
            {
                flags |= 1 << (x % 10);
                x /= 10;
            }
        };

        setFlags(a);
        setFlags(b);
        setFlags(c);

        return (flags == 0x03FE);
    }
}

int64_t Problem32()
{
    set<int32_t> products;

    for (int32_t i = 2; i <= 99; ++i)
    {
        if (i % 10 == 1 || i % 10 == 0)
            continue;

        const int32_t minJ = (999 / i) + 1;
        const int32_t maxJ = 9999 / i;

        for (int32_t j = minJ; j <= maxJ; ++j)
        {
            const int32_t product = i * j;
            if (IsPandigital(i, j, product))
                products.insert(product);
        }
    }

    return accumulate(products.begin(), products.end(), 0);
}
