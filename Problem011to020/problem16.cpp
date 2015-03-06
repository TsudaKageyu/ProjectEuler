#include "stdafx.h"
#include "utils.h"

using namespace boost::multiprecision;

int64_t Problem16()
{
    const auto p = pow(int1024_t(2), 1000);
    const auto s = p.str();

    std::vector<int> digits;
    digits.reserve(s.size());

    std::transform(
        s.begin(),
        s.end(),
        std::back_inserter(digits),
        [](char c) { return static_cast<int>(c) - '0'; });

    return std::accumulate(digits.begin(), digits.end(), 0);
}
