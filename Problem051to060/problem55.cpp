#include "stdafx.h"
#include "utils.h"

using boost::multiprecision::cpp_int;
using boost::multiprecision::integer_modulus;

namespace
{
    cpp_int GetReverseNumber(cpp_int n)
    {
        int64_t ret = 0;

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
    std::vector<int> count(10000);
    for (int64_t n = 1; n <= 9999; ++n)
    {
        if (count[n] != 0)
            continue;

        cpp_int n1(n);
        cpp_int n2 = GetReverseNumber(n1);

        int64_t n3 = static_cast<int64_t>(n2);
        if (count[n3] != 0)
        {
            count[n] = count[n3];
            continue;
        }

        int c = 1;
        while (true)
        {
            cpp_int sum = n1 + n2;
            n2 = GetReverseNumber(sum);
            if (sum == n2)
                break;

            n1 = sum;

            c++;
            if (c >= 50)
                break;
        }

        count[n] = c;
    }

    return std::count_if(count.begin(), count.end(), [](int x) { return x >= 50; });
}

