#include <cstdint>
#include <vector>

using namespace std;

namespace
{
    int64_t GetHash(size_t x)
    {
        int64_t h = 0;

        while (x != 0)
        {
            h += 1LL << ((x % 10) * 4);
            x /= 10LL;
        }

        return h;
    }
}

int64_t Problem49()
{
    vector<int32_t> sieve(10000);
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

    for (size_t i = 1489; i < sieve.size() - 2; i += 2)
    {
        if (sieve[i] == 0)
            continue;

        for (size_t j = i + 2; j + (j - i) < sieve.size(); j += 2)
        {
            if (sieve[j] == 0)
                continue;

            const size_t k = j + (j - i);
            if (sieve[k] == 0)
                continue;

            if (GetHash(i) == GetHash(j) && GetHash(j) == GetHash(k))
                return i * 10000000LL + j * 10000LL + k;
        }
    }

    return 0;
}
