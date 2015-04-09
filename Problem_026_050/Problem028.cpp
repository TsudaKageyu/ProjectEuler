#include <cstdint>

int64_t Problem28()
{
    int64_t answer = 1;

    for (int64_t n = 1; n <= 500; ++n)
        answer += (16 * n * n + 4 * n + 4);

    return answer;
}
