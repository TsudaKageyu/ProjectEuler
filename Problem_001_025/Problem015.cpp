#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

namespace
{
    int256_t GetFactorial(int32_t x)
    {
        int256_t f = 1;
        for (int32_t i = 2; i <= x; ++i)
            f *= i;

        return f;
    }
}

int64_t Problem15()
{
    const auto f40 = GetFactorial(40);
    const auto f20 = GetFactorial(20);
    return (f40 / (f20 * f20)).convert_to<uint64_t>();
}
