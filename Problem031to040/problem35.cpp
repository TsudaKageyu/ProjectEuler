#include "stdafx.h"
#include "utils.h"

int64_t Problem35()
{
    const auto &primes = Utils::GetPrimeTable();
    const auto itEnd = std::upper_bound(primes.begin(), primes.end(), 1000000);

    int64_t answer = 0;

    auto p = primes.begin();
    while (*p <= 9)
    {
        answer++;
        p++;
    }

    for (; p != itEnd; ++p)
    {
        std::array<int64_t, 6> digits = {
            Utils::GetDigit<int64_t, 0>(*p),
            Utils::GetDigit<int64_t, 1>(*p),
            Utils::GetDigit<int64_t, 2>(*p),
            Utils::GetDigit<int64_t, 3>(*p),
            Utils::GetDigit<int64_t, 4>(*p),
            Utils::GetDigit<int64_t, 5>(*p)
        };

        size_t size = digits.size();
        while (digits[size - 1] == 0)
            size--;

        const auto pred = [](int64_t x) { return (x % 2 == 0 || x == 5); };
        if (std::any_of(digits.begin(), digits.begin() + size, pred))
            continue;

        size_t rc;
        for (rc = 1; rc < size; ++rc)
        {
            std::rotate(digits.begin(), digits.begin() + 1, digits.begin() + size);

            int64_t rot = 0;
            int64_t k = 1;
            for (size_t i = 0; i < size; ++i)
            {
                rot += digits[i] * k;
                k *= 10;
            }

            const auto it = std::lower_bound(primes.begin(), itEnd, rot);
            if (*it != rot)
                break;
        }

        if (rc == size)
            answer++;
    }

    return answer;
}
