#include "../common.h"

int64_t Problem6()
{
    const int64_t num = 100;

    int64_t sum = 0;
    for (int64_t i = 1; i <= num; ++i)
        sum += i * i;

    int64_t sqr = Utils::GetSumOfNaturalNumbers(num);
    sqr *= sqr;

    return sqr - sum;
}
