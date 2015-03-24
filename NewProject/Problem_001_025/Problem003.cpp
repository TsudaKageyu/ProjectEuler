#include <cstdint>
#include <array>

int64_t Problem3()
{
    const int64_t N  = 600851475143;

    // Skip the factor 2 because N is obviously a odd number.

    int64_t n = N;

    for (int64_t f = 3; ; f += 2)
    {
        while ((n % f) == 0)
            n /= f;

        if (n == 1)
            return f;
    }
}
