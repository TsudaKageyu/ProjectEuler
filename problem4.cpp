#include <cassert>
#include <iostream>

#include "problem4.h"
#include "stopwatch.h"

namespace
{
    template <int N, int M>
    struct power
    {
        static const int value = N * power<N, M - 1>::value;
    };

    template <int N>
    struct power<N, 0>
    {
        static const int value = 1;
    };

    // Returns D + 1 th digit of n.
    template <int D>
    int digit(int n)
    {
        return (n / power<10, D>::value) % 10;
    }

    // Checks if the number of parindrome like "123321".
    bool is_parindrome(int n)
    {
        assert(100 * 100 <= n && n <= 999 * 999);

        if (n < 100000)
            return (digit<0>(n) == digit<4>(n) && digit<1>(n) == digit<3>(n));
        else
            return (digit<0>(n) == digit<5>(n) && digit<1>(n) == digit<4>(n) && digit<2>(n) == digit<3>(n));
    }
}

namespace problem4
{
    void calc()
    {
        StopWatch sw;

        int answer = 0;
        for (int i = 100; i <= 999; ++i)
        {
            for (int j = i; j <= 999; ++j)
            {
                const int p = i * j;
                if (p > answer && is_parindrome(p))
                    answer = p;
            }
        }

        std::cout << "Answer4: " << answer << " (" << sw.GetElapsedMilliseconds() << " ms)" << std::endl;
    }
}
