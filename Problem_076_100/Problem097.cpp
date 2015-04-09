#include <cstdint>
#include <vector>

using namespace std;

int64_t Problem97()
{
    uint64_t n = 2;

    for (int32_t i = 1; i < 7830457; ++i)
    {
        n *= 2;
        if ((n >> 63) != 0)
            n %= 10000000000;
    }

    n %= 10000000000;

    n *= 28433;
    n ++;
    n %= 10000000000;

    return n;
}
