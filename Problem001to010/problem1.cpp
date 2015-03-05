#include "stdafx.h"
#include "utils.h"

int64_t Problem1()
{
    return Utils::GetSumOfNaturalNumberMultiples<int64_t,  3, 999>()
         + Utils::GetSumOfNaturalNumberMultiples<int64_t,  5, 999>()
         - Utils::GetSumOfNaturalNumberMultiples<int64_t, 15, 999>();
}
