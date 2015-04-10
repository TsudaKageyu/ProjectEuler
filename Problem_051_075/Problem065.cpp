#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int64_t Problem65()
{
    const int64_t N = 100;

    cpp_int n = 1;
    cpp_int d = (N % 3 == 0) ? (N / 3 * 2) : 1;

    for (int64_t i = N - 1; i >= 2; --i)
    {
        if (i % 3 == 0)
            n += (cpp_int(i) / 3 * 2) * d;
        else
            n += d;

        swap(n, d);
    }

    n += 2 * d;

    int32_t answer = 0;

    for (char c : n.str())
        answer += static_cast<int32_t>(c) - '0';

    return answer;
}
