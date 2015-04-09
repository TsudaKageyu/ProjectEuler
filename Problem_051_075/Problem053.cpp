#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int64_t Problem53()
{
    int32_t answer = 0;

    for (cpp_int n = 23; n <= 100; ++n)
    {
        cpp_int num = 1;
        cpp_int den = 1;

        for (cpp_int r = 1; r <= (n + 1) / 2; ++r)
        {
            num *= (n - r + 1);
            den *= r;
            if (num / den > cpp_int(1000000))
            {
                answer += cpp_int(n - r * 2 + 1).convert_to<int32_t>();
                break;
            }
        }
    }

    return answer;
}
