#include <cstdint>
#include <array>

int64_t Problem9()
{
    const int32_t N = 1000;

    for (int32_t a = 1; a < N / 2; ++a)
    {
        const int32_t x = N * N - 2 * N * a;
        const int32_t y = 2 * N - 2 * a;
        if (x % y == 0)
        {
            const int32_t b = x / y;
            const int32_t c = N - a - b;

            return a * b * c;
        }
    }

    return 0;
}
