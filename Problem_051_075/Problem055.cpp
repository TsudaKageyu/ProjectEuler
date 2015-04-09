#include <cstdint>
#include <array>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

namespace
{
    cpp_int GetReverseNumber(cpp_int n)
    {
        cpp_int ret = 0;

        while (true)
        {
            ret = ret + integer_modulus(n, 10);

            n /= 10;
            if (n == 0)
                break;

            ret *= 10;
        }

        return ret;
    }
}

int64_t Problem55()
{
    int32_t answer = 0;

    for (int64_t n = 1; n <= 9999; ++n)
    {
        cpp_int t = n;

        int32_t c = 0;
        while (true)
        {
            const auto r = GetReverseNumber(t);
            if (t == r)
                break;

            c++;
            if (c >= 50)
            {
                answer++;
                break;
            }

            t += r;
        }
    }

    return answer;
}
