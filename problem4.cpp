#include "common.h"
#include "problem4.h"

namespace
{
    template <int N, int M>
    struct Power
    {
        static const int value = N * Power<N, M - 1>::value;
    };

    template <int N>
    struct Power<N, 0>
    {
        static const int value = 1;
    };

    // Returns D + 1 th digit of n.
    template <int D>
    int GetDigit(int n)
    {
        return (n / Power<10, D>::value) % 10;
    }

    // Checks if the number is palindromic like "123321".
    bool IsPalindromic(int n)
    {
        assert(100 * 100 <= n && n <= 999 * 999);

        if (n < 100000)
            return (GetDigit<0>(n) == GetDigit<4>(n) && GetDigit<1>(n) == GetDigit<3>(n));
        else
            return (GetDigit<0>(n) == GetDigit<5>(n) && GetDigit<1>(n) == GetDigit<4>(n) && GetDigit<2>(n) == GetDigit<3>(n));
    }
}

namespace problem4
{
    void Solve()
    {
        assert(IsPalindromic(123321));

        StopWatch sw;

        int answer = 0;
        for (int i = 100; i <= 999; ++i)
        {
            for (int j = i; j <= 999; ++j)
            {
                const int p = i * j;
                if (p > answer && IsPalindromic(p))
                    answer = p;
            }
        }

        const auto time = sw.GetElapsedMilliseconds();
        Utils::PrintResult(4, answer, time);
    }
}
