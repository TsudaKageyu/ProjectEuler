#include <cstdint>
#include <vector>

using namespace std;

namespace
{
    int32_t GetFactorial(int32_t x)
    {
        int32_t f = 1;
        for (int32_t i = 2; i <= x; ++i)
            f *= i;

        return f;
    }
}

std::string Problem24()
{
    vector<char> nums = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int32_t n = 1000000;

    string answer;

    for (int32_t i = 9; i >= 0; --i)
    {
        const int32_t f = GetFactorial(i);
        const int32_t d = (n - 1) / f;
        n -= d * f;

        answer += nums[d];
        nums.erase(nums.begin() + d);
    }

    return answer;
}
