#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int64_t Problem16()
{
    const auto power = cpp_int(pow(cpp_int(2), 1000)).str();

    int32_t sum = 0;
    for (const auto c : power)
        sum += static_cast<int32_t>(c) - '0';

    return sum;
}
