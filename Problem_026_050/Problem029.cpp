#include <cstdint>
#include <set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int64_t Problem29()
{
    set<cpp_int> powers;

    for (cpp_int b = 2; b <= 100; ++b)
    {
        for (uint32_t e = 2; e <= 100; ++e)
        {
            powers.insert(pow(b, e));
        }
    }

    return powers.size();
}
