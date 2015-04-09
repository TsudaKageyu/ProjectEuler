#include <cstdint>
#include <unordered_map>
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

int64_t Problem62()
{
    const int64_t Limit = 30000;

    unordered_map<int64_t, vector<int64_t>> dic;

    for (int64_t i = 1; i <= Limit; ++i)
    {
        const int64_t key = GetKey(i * i * i);
        if (dic[key].size() == 4)
            return dic[key].front();
        else
            dic[key].push_back(i * i * i);
    }
}
