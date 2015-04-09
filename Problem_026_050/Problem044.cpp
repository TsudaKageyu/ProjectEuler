#include <cstdint>
#include <algorithm>

using namespace std;

namespace
{
    bool IsPentagonal(int32_t x)
    {
        const double n = (sqrt(24.0 * x + 1.0) + 1.0) / 6.0;
        return (n == floor(n));
    }
}

int64_t Problem44()
{
    int32_t m = 1;
    for (int32_t i = 4; ; i += 3)
    {
        m += i;

        int32_t n = 0;
        for (int32_t j = 1; ; j += 3)
        {
            n += j;
            if (n >= m)
                break;

            if (!IsPentagonal(m + n))
                continue;

            const int32_t diff = m - n;
            if (!IsPentagonal(diff))
                continue;

            return diff;
        }
    }

    return 0;
}
