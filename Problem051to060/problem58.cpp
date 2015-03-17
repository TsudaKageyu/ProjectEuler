#include "stdafx.h"
#include "utils.h"

namespace
{
    bool IsPrime(int64_t n)
    {
        for (int64_t i = 3; i < std::sqrt(n) + 1; ++i)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }
}

int64_t Problem58()
{
    int64_t answer = 0;

    int64_t num        = 1;
    int64_t numCount   = 1;
    int64_t primeCount = 0;

    for (int64_t i = 1; ; ++i)
    {
        for (int64_t j = 0; j < 4; ++j)
        {
            num += i * 2;

            if (IsPrime(num))
                primeCount++;
        }

        numCount += 4;

        if (primeCount * 100 / numCount < 10)
        {
            answer = i * 2 + 1;
            break;
        }
    }

    return answer;
}
