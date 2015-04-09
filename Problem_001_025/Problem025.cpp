#include <cstdint>
#include <array>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int64_t Problem25()
{
    array<cpp_int, 2> seq = { 1, 1 };
    int32_t term = 3;

    while (true)
    {
        seq[0] += seq[1];
        if (seq[0].str().size() >= 1000)
            return term;

        term++;
        swap(seq[0], seq[1]);
    }

    return 0;
}
