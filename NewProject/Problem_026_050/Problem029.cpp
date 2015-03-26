#include <cstdint>
#include <algorithm>

using namespace std;

int64_t Problem29()
{
    int32_t answer = 1;

    for (int32_t n = 1; n <= 500; ++n)
        answer += (16 * n * n + 4 * n + 4);

    return answer;
}
