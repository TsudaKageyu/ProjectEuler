#include "../common.h"

namespace
{
    template <int64_t N, int64_t M>
    struct Power
    {
        static const int64_t value = N * Power<N, M - 1>::value;
    };

    template <int64_t N>
    struct Power<N, 0>
    {
        static const int64_t value = 1;
    };

    // Returns D + 1 th digit of n.
    template <int64_t D>
    int64_t GetDigit(int64_t n)
    {
        return (n / Power<10, D>::value) % 10;
    }

    // Checks if the number is palindromic like "123321".
    bool IsPalindromic(int64_t n)
    {
        assert(100 * 100 <= n && n <= 999 * 999);

        if (n < 100000)
            return (GetDigit<0>(n) == GetDigit<4>(n) && GetDigit<1>(n) == GetDigit<3>(n));
        else
            return (GetDigit<0>(n) == GetDigit<5>(n) && GetDigit<1>(n) == GetDigit<4>(n) && GetDigit<2>(n) == GetDigit<3>(n));
    }
}

int64_t Problem4()
{
    assert(IsPalindromic(123321));

    int64_t answer = 0;

    for (int64_t i = 999; i >= 100; --i)
    {
        if (i <= answer / 999)
            break;

        for (int j = 999; j >= i; --j)
        {
            const int64_t p = i * j;
            if (p <= answer)
                break;

            if (IsPalindromic(p))
                answer = p;
        }
    }

    return answer;
}
