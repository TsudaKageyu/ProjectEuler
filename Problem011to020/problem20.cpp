#include "stdafx.h"
#include "utils.h"

using namespace boost::multiprecision;

int64_t Problem20()
{
    return Utils::GetSumOfDigits(Utils::GetFactorial<int1024_t>(100));
}
