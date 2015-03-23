#include <cassert>
#include <cstdint>
#include <array>

namespace
{
    bool IsParindrome(int32_t n)
    {
        const std::array<int32_t, 6> d =
        {
             n           % 10,
            (n /     10) % 10,
            (n /    100) % 10,
            (n /   1000) % 10,
            (n /  10000) % 10,
             n / 100000
        };

        if (d[5] == 0)
            return (d[0] == d[4] && d[1] == d[3]);
        else
            return (d[0] == d[5] && d[1] == d[4] && d[2] == d[3]);
    }
}

int64_t Problem4()
{
    using namespace std;

    assert(IsParindrome(54345));

    int32_t answer = 0;

    for (int32_t i = 999; i >= 100; --i)
    {
        if (i < answer / 999)
            break;

        for (int32_t j = i; j >= 100; --j)
        {
            const int32_t p = i * j;
            if (IsParindrome(p) && p > answer)
            {
                answer = p;
                break;
            }
        }
    }

    return answer;
}
