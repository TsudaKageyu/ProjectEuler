#include "stdafx.h"
#include "utils.h"

int64_t Problem92()
{
    int64_t answer = 0;

    std::vector<int> flags(568);

    for (int32_t n = 2; n < 10000000; ++n)
    {
        int32_t tmp = n;

        while (true)
        {
            int32_t sum = 0;

            while (tmp != 0)
            {
                sum += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }

            if (sum < n && sum < flags.size())
            {
                if (flags[sum])
                    sum = 89;
                else
                    sum = 1;
            }

            if (sum == 89 || sum == 1)
            {
                if (sum == 89)
                {
                    if (n < flags.size())
                        flags[n] = 1;

                    answer++;
                }

                break;
            }

            tmp = sum;
        }
    }

    return answer;
}
