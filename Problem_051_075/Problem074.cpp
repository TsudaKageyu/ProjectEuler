#include <cstdint>
#include <array>
#include <vector>

using namespace std;

int64_t Problem74()
{
    const array<int32_t, 10> F = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

    int32_t answer = 0;

    vector<size_t> mem(1000001);

    for (int32_t n = 1; n < 1000000; ++n)
    {
        vector<int32_t> c = { n };

        while (true)
        {
            int32_t t = c.back();
            int32_t m = 0;
            while (t != 0)
            {
                m += F[t % 10];
                t /= 10;
            }

            if (m < n)
                mem[n] = c.size() + mem[m];
            else if (find(c.begin(), c.end(), m) != c.end())
                mem[n] = c.size();

            if (mem[n] != 0)
            {
                if (mem[n] == 60)
                    answer++;

                break;
            }

            c.push_back(m);
        }
    }

    return answer;
}
