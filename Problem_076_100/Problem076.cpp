#include <cstdint>
#include <vector>

using namespace std;

int64_t Problem76()
{
    const int32_t Limit = 100;

    vector<int32_t> p(Limit + 1);
    p[0] = 1;

    for (size_t i = 1; i <= Limit - 1; ++i)
    {
        for (size_t j = i; j <= Limit; ++j)
        {
            p[j] += p[j - i];
        }
    }

    return p.back();
}
