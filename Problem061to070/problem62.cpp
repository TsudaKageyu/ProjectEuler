#include "stdafx.h"
#include "utils.h"

namespace
{
    struct Data
    {
        int32_t count  = 0;
        int64_t number = 0;

        void Add(int64_t n)
        {
            if (count == 0)
                number = n;

            count++;
        }
    };

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

    std::unordered_map<int64_t, Data> dic;
    dic.reserve(Limit);

    for (int64_t i = 1; i <= Limit; ++i)
        dic[GetKey(i * i * i)].Add(i * i * i);

    int64_t answer = std::numeric_limits<int64_t>::max();

    for (const auto p : dic)
    {
        if (p.second.count != 5)
            continue;

        if (p.second.number < answer)
            answer = p.second.number;
    }

    return answer;
}
