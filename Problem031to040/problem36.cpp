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

    for (int n = 1; n <= 999; n += 2)
    {
        std::vector<int> digits = { n % 10, (n / 10) % 10, (n / 100) };

        while (digits.back() == 0)
            digits.pop_back();

        if (digits.size() == 1)
        {
            const int n1 = digits[0] * 11;
            if (IsParindromicBinary(n1))
                answer += n1;

            const int n2 = digits[0] * 1001;
            if (IsParindromicBinary(n2))
                answer += n2;

            const int n3 = digits[0] * 100001;
            if (IsParindromicBinary(n3))
                answer += n3;

            if (IsParindromicBinary(digits[0]))
                answer += digits[0];
        }
        else if (digits.size() == 2)
        {
            const int n1 = digits[0] * 1001 + digits[1] * 110;
            if (IsParindromicBinary(n1))
                answer += n1;

            const int n2 = digits[0] * 101 + digits[1] * 10;
            if (IsParindromicBinary(n2))
                answer += n2;

            const int n3 = digits[0] * 100001 + digits[1] * 10010;
            if (IsParindromicBinary(n3))
                answer += n3;

            const int n4 = digits[0] * 10001 + digits[1] * 1010;
            if (IsParindromicBinary(n4))
                answer += n4;
        }
        else // if (digits.size() == 3)
        {
            const int n1 = digits[0] * 100001 + digits[1] * 10010 + digits[2] * 1100;
            if (IsParindromicBinary(n1))
                answer += n1;

            const int n2 = digits[0] * 10001 + digits[1] * 1010 + digits[2] * 100;
            if (IsParindromicBinary(n2))
                answer += n2;
        }
    }

    return answer;
}
