#include <cstdint>

namespace
{
    int32_t GetSumOfMultiples(int32_t max, int32_t mul)
    {
        return (1 + (max / mul)) * (max / mul) / 2 * mul;
    }
}

int64_t Problem1()
{
    int32_t answer = 0;

    answer += GetSumOfMultiples(999,  3);
    answer += GetSumOfMultiples(999,  5);
    answer -= GetSumOfMultiples(999, 15);

    return answer;
}
