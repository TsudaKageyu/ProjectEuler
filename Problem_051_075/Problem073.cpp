#include <cstdint>
#include <vector>

using namespace std;

namespace
{
    int64_t gcd(int64_t a, int64_t b)
    {
        while (a % b != 0)
        {
            a = a % b;
            swap(a, b);
        }

        return b;
    }
}

int64_t Problem73()
{
    int32_t answer = 0;

    for (int32_t d = 4; d <= 12000; ++d)
    {
        for (int32_t n = d / 3 + 1; n <= (d - 1) / 2; ++n)
        {
            if (gcd(d, n) == 1)
                answer++;
        }
    }

    return answer;
}
