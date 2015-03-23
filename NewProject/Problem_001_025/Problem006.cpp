#include <cassert>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <vector>

int64_t Problem6()
{
    using namespace std;

    const int64_t Limit = 100;

    int64_t sqrOfSum = (1 + Limit) * Limit / 2;
    sqrOfSum *= sqrOfSum;

    int64_t sumOfSqr = (2 * Limit + 1) * (Limit + 1) * Limit / 6;

    return sqrOfSum - sumOfSqr;
}
