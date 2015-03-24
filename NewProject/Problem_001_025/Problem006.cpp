#include <cassert>
#include <cstdint>

int64_t Problem6()
{
    const int64_t Limit = 100;

    int64_t sqrOfSum = (1 + Limit) * Limit / 2;
    sqrOfSum *= sqrOfSum;

    int64_t sumOfSqr = (2 * Limit + 1) * (Limit + 1) * Limit / 6;

    return sqrOfSum - sumOfSqr;
}
