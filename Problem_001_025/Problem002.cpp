#include <cstdint>
#include <array>

int64_t Problem2()
{
    using namespace std;

    const int32_t Limit = 4000000;

    array<int32_t, 2> seq = { 1, 1 }; // Last 2 terms of the sequence.
    int64_t answer = 0;

    while(true)
    {
        if (seq[1] >= Limit)
            break;

        if (seq[1] & 1)
            answer += seq[1];

        seq[0] += seq[1];
        swap(seq[0], seq[1]);
    }

    return answer;
}
