#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

namespace
{
    int1024_t GetFactorial(int32_t x)
    {
        int1024_t f = 1;
        for (int32_t i = 2; i <= x; ++i)
            f *= i;

        return f;
    }
}

int64_t Problem20()
{
    const auto str = GetFactorial(100).str();

    int32_t answer = 0;
    for (const auto c : str)
        answer += static_cast<int32_t>(c) - '0';

    return answer;
}
