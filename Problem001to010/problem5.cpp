#include "stdafx.h"
#include "utils.h"

int64_t Problem5()
{
    int64_t answer = 1;
    for (int64_t i = 2; i <= 20; ++i)
        answer = Utils::LCM(answer, i);

    return answer;
}
