#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

int64_t Problem68()
{
    int64_t answer = 0;

    for (int32_t s = 6; s >= 1; --s)
    {
        vector<int32_t> outer(10 - s + 1);
        for (size_t i = 0; i < outer.size(); ++i)
            outer[i] = static_cast<int32_t>(s + i);

        do
        {
            vector<int32_t> inner;
            inner.reserve(5);
            for (int32_t i = 1; i <= 9; ++i)
            {
                if (find(outer.begin(), outer.begin() + 5, i) == outer.begin() + 5)
                    inner.push_back(i);
            }

            do
            {
                const int32_t sum = outer[0] + inner[0] + inner[1];

                for (size_t i = 1; i < 5; ++i)
                {
                    if (outer[i] + inner[i] + inner[(i + 1) % 5] != sum)
                        goto NEXT;
                }

                int64_t n = 0;
                for (size_t i = 0; i < 5; ++i)
                {
                    if (outer[i] == 10)
                        n = n * 100 + outer[i];
                    else
                        n = n * 10 + outer[i];

                    if (inner[i] == 10)
                        n = n * 100 + inner[i];
                    else
                        n = n * 10 + inner[i];

                    if (inner[(i + 1) % 5] == 10)
                        n = n * 100 + inner[(i + 1) % 5];
                    else
                        n = n * 10 + inner[(i + 1) % 5];
                }

                if (n > answer)
                    answer = n;

            NEXT:
                ;
            } while (next_permutation(inner.begin(), inner.end()));

        } while (next_permutation(outer.begin() + 1, outer.end()));

        if (answer != 0)
            break;
    }

    return answer;
}
