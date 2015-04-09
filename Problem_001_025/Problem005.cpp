#include <cassert>
#include <cstdint>
#include <utility>

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

    int64_t lcm(int64_t a, int64_t b)
    {
        return a * b / gcd(a, b);
    }
}

int64_t Problem5()
{
    const int64_t Limit = 20;

    int64_t answer = 1;

    for (int64_t i = 2; i <= Limit; ++i)
        answer = lcm(answer, i);

    return answer;
}
