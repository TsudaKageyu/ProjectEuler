#include "stdafx.h"
#include "utils.h"

using namespace boost::multiprecision;

int64_t Problem16()
{
    return Utils::GetSumOfDigits(pow(int1024_t(2), 1000));
}
