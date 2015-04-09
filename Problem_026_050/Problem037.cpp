#include <cstdint>
#include <numeric>
#include <vector>

using namespace std;

int64_t Problem37()
{
    vector<int32_t> sieve(1000001);
    sieve[2] = 2;

    for (size_t i = 3; i < sieve.size(); i += 2)
        sieve[i] = static_cast<int32_t>(i);

    for (size_t i = 3; i * i <= sieve.size(); ++i)
    {
        if (sieve[i] == 0)
            continue;

        for (size_t j = i * 2; j < sieve.size(); j += i)
            sieve[j] = 0;
    }

    int32_t answer = 0;

    for (size_t i = 11; i < sieve.size(); i += 2)
    {
        int32_t p = sieve[i];
        if (p == 0)
            continue;

        while (true)
        {
            p /= 10;
            if (p == 0)
                break;

            if (sieve[p] == 0)
                goto NEXT;
        }

        int32_t m = 10;
        while (true)
        {
            p = sieve[i] % m;
            if (p == sieve[i])
                break;

            if (sieve[p] == 0)
                goto NEXT;

            m *= 10;
        }

        answer += sieve[i];

    NEXT:
        ;
    }

    return answer;
}
