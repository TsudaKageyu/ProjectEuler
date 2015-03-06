#include "stdafx.h"
#include "utils.h"

uint64_t Problem14()
{
    const int64_t MaxNum = 1000000;

    int64_t answer  = 0;
    int64_t longest = 0;

    std::vector<int64_t> len(MaxNum);
    len[1] = 1; // The length of the sequence starts with 1 is obviously 1.

    for (int64_t i = 2; i < MaxNum; ++i)
    {
        int64_t n = i;
        int64_t l = 1;

        do
        {
            if (n & 1)
            {
                n = 3 * n + 1;
            }
            else
            {
                n /= 2;
                if (n < i)
                {
                    l += len[n]; // Reuse the length already checked.
                    break;
                }
            }

            l++;

        } while (n != 1);

        if (l > longest)
        {
            answer  = i;
            longest = l;
        }

        len[i] = l;
    }

    return answer;
}
