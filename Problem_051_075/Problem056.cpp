#include <cstdint>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int64_t Problem56()
{
    int32_t answer = 0;

    for (cpp_int a = 1; a < 100; ++a)
    {
        for (int32_t b = 1; b < 100; ++b)
        {
            int32_t sum = 0;

            const auto s = cpp_int(pow(a, b)).str();
            for (const char c : s)
                sum += (static_cast<int32_t>(c) - '0');

            if (sum > answer)
                answer = sum;
        }
    }

    return answer;
}
