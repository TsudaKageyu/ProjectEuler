#include <cstdint>
#include <intrin.h>

namespace
{
    bool IsParindromicBase2(int32_t n)
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

    for (int32_t i = 0; i <= 9; ++i)
    {
        for (int32_t j = 0; j <= 9; ++j)
        {
            for (int32_t k = 1; k <= 9; k += 2)
            {
                const int32_t n1 = i * 1100 + j * 10010 + k * 100001;
                if (IsParindromicBase2(n1))
                    answer += n1;

                const int32_t n2 = i * 100 + j * 1010 + k * 10001;
                if (IsParindromicBase2(n2))
                    answer += n2;

                if (i == 0)
                {
                    const int32_t n3 = j * 110 + k * 1001;
                    if (IsParindromicBase2(n3))
                        answer += n3;

                    const int32_t n4 = j * 10 + k * 101;
                    if (IsParindromicBase2(n4))
                        answer += n4;

                    if (j == 0)
                    {
                        const int32_t n5 = k * 11;
                        if (IsParindromicBase2(n5))
                            answer += n5;

                        if (IsParindromicBase2(k))
                            answer += k;
                    }
                }
            }
        }
    }

    return answer;
}
