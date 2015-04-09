#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
#include <set>

using namespace std;
using namespace boost::multiprecision;

int64_t Problem63()
{
    set<cpp_int> nums;

    for (cpp_int b = 1; b <= 9; ++b)
    {
        for (uint32_t n = 1; ; ++n)
        {
            const cpp_int p = pow(b, n);
            const size_t  d = p.str().size();
            if (d == n)
                nums.insert(p);
            else if (d < n)
                break;
        }
    }

    return nums.size();
}
