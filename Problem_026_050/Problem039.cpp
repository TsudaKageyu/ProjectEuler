#include <cstdint>
#include <algorithm>

using namespace std;

int64_t Problem39()
{
    int32_t answer   = 0;
    int32_t maxCount = 0;

    for (int32_t p = 3; p <= 1000; ++p)
    {
        int32_t count = 0;

        for (int32_t a = 1; a < p / 2; ++a)
        {
            const double b = ((2.0 * a * p) - (p * p)) / (2.0 * (a - p));
            if (b != floor(b))
                continue;

            const int32_t c = p - a - static_cast<int32_t>(b);
            if (c < 1)
                continue;

            count++;
        }

        if (count > maxCount)
        {
            answer   = p;
            maxCount = count;
        }
    }

    return answer;
}
