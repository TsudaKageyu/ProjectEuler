#include <cstdint>
#include <array>

int64_t Problem2()
{
    using namespace std;

    const int32_t Limit = 4000000;

    array<int32_t, 2> nums = { 1, 1 };
    int64_t answer = 0;

    while(true)
    {
        if (nums[1] >= Limit)
            break;

        if (nums[1] & 1)
            answer += nums[1];

        nums[0] += nums[1];
        swap(nums[0], nums[1]);
    }

    return answer;
}
