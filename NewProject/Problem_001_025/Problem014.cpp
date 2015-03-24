#include <cstdint>
#include <vector>

int64_t Problem14()
{
    const int64_t Limit = 1000000;

    std::vector<int64_t> mem;
    mem.resize(Limit);

    int64_t maxLength = 0;
    int64_t answer = 0;

    for (int64_t n = 2; n < Limit; ++n)
    {
        int64_t length = 0;
        int64_t term = n;

        while (term != 1)
        {
            if (term & 1)
                term = term * 3 + 1;
            else
                term = term / 2;

            if (term < n)
            {
                length += mem[term] + 1;
                break;
            }

            length++;
        }

        if (length > maxLength)
        {
            maxLength = length;
            answer = n;
        }

        mem[n] = length;
    }

    return answer;
}
