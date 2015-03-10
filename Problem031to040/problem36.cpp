#include "stdafx.h"
#include "utils.h"

namespace
{
    bool IsParindromicBase2(int n)
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

    for (int n = 1; n <= 999; n += 2)
    {
        const int d0 = n % 10;
        const int d1 = (n / 10) % 10;
        const int d2 = n / 100;

        const int n1 = d0 * 100001 + d1 * 10010 + d2 * 1100;
        if (IsParindromicBase2(n1))
            answer += n1;

        const int n2 = d0 * 10001 + d1 * 1010 + d2 * 100;
        if (IsParindromicBase2(n2))
            answer += n2;

        if (d2 == 0)
        {
            const int n3 = d0 * 1001 + d1 * 110;
            if (IsParindromicBase2(n3))
                answer += n3;

            const int n4 = d0 * 101 + d1 * 10;
            if (IsParindromicBase2(n4))
                answer += n4;

            if (d1 == 0)
            {
                const int n5 = d0 * 11;
                if (IsParindromicBase2(n5))
                    answer += n5;

                if (IsParindromicBase2(d0))
                    answer += d0;
           }
        }
    }

    return answer;
}
