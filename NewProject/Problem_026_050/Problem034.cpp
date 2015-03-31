#include <cstdint>
#include <array>

using namespace std;

int64_t Problem34()
{
    const std::array<int32_t, 10> Factorials = {
        1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880
    };

    int32_t answer = 0;

    for (int32_t n = 11; n <= 2540160; ++n)
    {
        int32_t sum = 0;

        int32_t t = n;
        while (t != 0)
        {
            const int32_t d = t % 10;
            t /= 10;

            sum += Factorials[d];
            if (sum > n)
                break;
        }

        if (sum == n)
            answer += n;
    }

    return answer;
}
