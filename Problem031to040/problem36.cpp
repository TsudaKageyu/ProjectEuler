#include "stdafx.h"
#include "utils.h"

namespace Utils
{
    bool IsParindromicBinary(int n)
    {
        const uint32_t x = static_cast<uint32_t>(n);

        uint32_t y = x;
        y = ::_byteswap_ulong(x);
        y = ((y << 4) & 0xf0f0f0f0u) | ((y >> 4) & 0x0f0f0f0fu);
        y = ((y << 2) & 0xccccccccu) | ((y >> 2) & 0x33333333u);
        y = ((y << 1) & 0xaaaaaaaau) | ((y >> 1) & 0x55555555u);

        unsigned long index;
        ::_BitScanForward(&index, y);
        y >>= index;

        return (x == y);
    }
}

int64_t Problem36()
{
    int64_t answer = 0;

    for (int i = 1; i <= 9; i += 2)
    {
        if (!Utils::IsParindromicBinary(i))
            continue;

        if (!Utils::IsPalindromic(i))
            continue;

        answer += i;
    }

    int d = 10;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 1; j <= 9; j += 2)
        {
            for (int k = j * d + 1; k <= j * d + d - 1; k += 2)
            {
                if (!Utils::IsParindromicBinary(k))
                    continue;

                if (!Utils::IsPalindromic(k))
                    continue;

                answer += k;
            }
        }

        d *= 10;
    }

    return answer;
}
