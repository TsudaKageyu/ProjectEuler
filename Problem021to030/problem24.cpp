#include "stdafx.h"
#include "utils.h"

std::string Problem24()
{
    std::vector<char> digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    int64_t num = 999999;
    std::string answer;
    answer.reserve(digits.size());

    for (int i = 9; i >= 0; --i)
    {
        const int64_t f = Utils::GetFactorial<int64_t>(i);
        const int64_t d = num / f;

        answer.push_back(digits[d]);
        std::swap(digits[d], digits.back());

        num -= (f * d);
    }

    return answer;
}
