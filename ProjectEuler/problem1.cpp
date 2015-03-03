#include <iostream>
#include "problem1.h"

namespace
{
    // Returns the sum of all the natural number no more than N.
    template <int N>
    int f1()
    {
        return (N + 1) * N / 2;
    }

    // Returns the sum of all the natural number multiples of N no more than L.
    template <int N, int L>
    int f2()
    {
        return N * f1<L / N>();
    }
}

namespace problem1
{
    void calc()
    {
        std::cout << "Answer1: " << f2<3, 999>() + f2<5, 999>() - f2<15, 999>() << std::endl;
    }
}
