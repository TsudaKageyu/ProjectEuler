#include <cassert>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <vector>

#include "stopwatch.h"

namespace Utils
{
    // -------------------------------------------------------------------------
    // Returns the sum of all the natural numbers no more than n.

    template <typename T>
    inline T GetSumOfNaturalNumbers(T n)
    {
        return (n + 1) * n / 2;
    }

    // -------------------------------------------------------------------------
    // Returns a list of the prime numbers no more than n.

    template <typename T>
    inline std::vector<T> GetPrimeNumbers(T n)
    {
        std::vector<T> numbers;
        numbers.resize(n);

        // We never use [0] and [1], but they can make the code a bit clearer.

        for (size_t i = 2; i < numbers.size(); ++i)
            numbers[i] = static_cast<int>(i);

        for (size_t i = 2; i < numbers.size() / 2; ++i)
        {
            if (numbers[i] == 0)
                continue;

            for (size_t j = i * 2; j < numbers.size(); j += i)
                numbers[j] = 0;
        }

        std::vector<T> primes;
        primes.reserve(numbers.size());

        std::copy_if(
            numbers.begin() + 2,
            numbers.end(),
            std::back_inserter(primes),
            [](int x) { return x > 0; });

        return primes;
    }

    inline void PrintResult(int problem, int64_t answer, const std::string &time)
    {
        ::printf("Answer %2d: %10ld (%14s)\n", problem, answer, time.c_str());
    }
}
