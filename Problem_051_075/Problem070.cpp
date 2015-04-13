#include <cstdint>
#include <vector>

using namespace std;

namespace
{
    int64_t GetKey(int64_t x)
    {
        int64_t key = 0;

        while (x != 0)
        {
            key += 1LL << ((x % 10) * 4);
            key += 1LL << 40;
            x /= 10;
        }

        return key;
    }
}

int64_t Problem70()
{
    const int32_t Limit = 10000000;

    vector<int32_t> phi(Limit + 1);
    int64_t answer = 0;
    double maxR = DBL_MAX;

    phi[1] = 1;
    for (int32_t n = 2; n <= Limit; ++n)
    {
        if (phi[n] != 0)
            continue;

        phi[n] = n - 1;

        for (int32_t j = 2; n * j <= Limit; ++j)
        {
            if (phi[j] == 0)
                continue;

            int32_t q = j;
            int32_t f = n - 1;
            while (q % n == 0)
            {
                f *= n;
                q /= n;
            }

            phi[n * j] = f * phi[q];

            const double r = n * j * 1.0 / phi[n * j];
            if (r < maxR && GetKey(n * j) == GetKey(phi[n * j]))
            {
                maxR   = r;
                answer = n * j;
            }
        }
    }

    return answer;
}
