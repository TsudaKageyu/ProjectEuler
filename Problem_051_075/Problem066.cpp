#include <cstdint>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int64_t Problem66()
{
    int64_t answer = 0;
    cpp_int maxX = 0;

    for (int64_t s = 2; s <= 1000; ++s)
    {
        const int64_t a0 = static_cast<int64_t>(sqrt(s));
        if (a0 * a0 == s)
            continue;

        cpp_int m = 0;
        cpp_int d = 1;
        cpp_int a = a0;

        cpp_int x = 0;
        cpp_int y = 1;

        while (true)
        {
            m = d * a - m;
            d = (s - m * m) / d;
            a = (a0 + m) / d;

            x += a * y;
            swap(x, y);

            const cpp_int xx = x + a0 * y;
            if (xx * xx - s * y * y == 1)
            {
                if (xx > maxX)
                {
                    maxX = xx;
                    answer = s;
                }
                break;
            }
        }
    }

    return answer;
}
