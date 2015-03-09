#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::cpp_int;
using boost::multiprecision::pow;

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
}

int64_t Problem30()
{
    std::vector<int64_t> nums;

    for (int64_t n = 2; n <= 354294; ++n)
    {
        const uint64_t a = GetDigit<5>(n);
        const uint64_t b = GetDigit<4>(n);
        const uint64_t c = GetDigit<3>(n);
        const uint64_t d = GetDigit<2>(n);
        const uint64_t e = GetDigit<1>(n);
        const uint64_t f = GetDigit<0>(n);

        const uint64_t m = a * a * a * a * a
                         + b * b * b * b * b
                         + c * c * c * c * c
                         + d * d * d * d * d
                         + e * e * e * e * e
                         + f * f * f * f * f;

        if (n == m)
            nums.push_back(n);
    }

    return std::accumulate(nums.begin(), nums.end(), 0LL);
}
