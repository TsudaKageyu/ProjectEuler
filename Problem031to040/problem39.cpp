#include "stdafx.h"
#include "utils.h"

int64_t Problem39()
{
    int64_t answer = 0;
    int64_t max = 0;

    for (int64_t p = 4; p <= 1000; p += 2)
    {
        // This counts the same solution twice like {20,48,52} and {48,20,52}.

        int64_t count = 0;

        for (int64_t a = 1; a < p / 2; ++a)
        {
            for (int64_t b = p / 2 - a; b < p / 2; ++b)
            {
                const int64_t c = p - a - b;
                if (a * a + b * b == c * c)
                    count++;
            }
        }

        if (count > max)
        {
            max = count;
            answer = p;
        }
    }

    return answer;
}
