#include <cstdint>
#include <vector>

using namespace std;

int64_t Problem50()
{
    vector<int32_t> sieve(1000000);
    sieve[2] = 2;

    for (size_t i = 3; i < sieve.size(); i += 2)
        sieve[i] = static_cast<int32_t>(i);

    for (size_t i = 3; i * i <= sieve.size(); i += 2)
    {
        if (sieve[i] == 0)
            continue;

        for (size_t j = i * 2; j < sieve.size(); j += i)
            sieve[j] = 0;
    }

    int32_t answer = 0;
    int32_t maxLen = 0;

    for (size_t i = 3; i < sieve.size() / 2; i += 2)
    {
        if (sieve[i] == 0)
            continue;

        int32_t sum = sieve[i];
        int32_t len = 0;
        for (size_t j = i + 2; ; j += 2)
        {
            if (sieve[j] == 0)
                continue;

            sum += sieve[j];
            if (sum >= sieve.size())
                break;

            len++;

            if (sieve[sum] != 0 && len > maxLen)
            {
                answer = sum;
                maxLen = len;
            }
        }
    }

    return answer;
}
