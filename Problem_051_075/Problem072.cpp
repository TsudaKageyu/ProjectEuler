#include <cstdint>
#include <vector>

using namespace std;

int64_t Problem72()
{
    const int32_t Limit = 1000000;

    vector<int32_t> phi(Limit + 1);
    int64_t answer = 0;

    phi[1] = 1;
    for (int32_t n = 2; n <= Limit; ++n)
    {
        if (phi[n] != 0)
            continue;

        phi[n] = n - 1;
        answer += phi[n];

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
            answer += phi[n * j];
        }
    }

    return answer;
}
