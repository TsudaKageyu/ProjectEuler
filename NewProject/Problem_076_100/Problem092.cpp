#include <cstdint>
#include <vector>

using namespace std;

int64_t Problem92()
{
    int32_t answer = 0;

    vector<bool> flags(568);

    for (int32_t i = 2; i <= 567; ++i)
    {
        int32_t n = i;

        while (true)
        {
            if (n == 89)
            {
                flags[i] = true;
                answer++;
                break;
            }
            else if (n == 1)
            {
                break;
            }

            int32_t t = 0;
            while (n != 0)
            {
                t += (n % 10) * (n % 10);
                n /= 10;
            }

            n = t;
        }
    }

    for (int32_t i = 568; i < 10000000; ++i)
    {
        int32_t n = i;
        int32_t t = 0;
        while (n != 0)
        {
            t += (n % 10) * (n % 10);
            n /= 10;
        }

        if (flags[t])
            answer++;
    }

    return answer;
}
