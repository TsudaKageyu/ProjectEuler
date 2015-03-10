#include "stdafx.h"
#include "utils.h"

namespace
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

    for (int64_t n = 1; n <= 999999; n += 2)
    {
        if (!IsParindromicBinary(static_cast<int>(n)))
            continue;

        if (!Utils::IsPalindromic(n))
            continue;

        answer += n;
    }

    return answer;
}
