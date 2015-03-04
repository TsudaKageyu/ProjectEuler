#include "common.h"
#include "problem3.h"

namespace problem3
{
    void Solve()
    {
        StopWatch sw;

        const int64_t num = 600851475143;

        // List the prime numbers no more than sqrt(num).

        std::vector<int> primes;
        {
            const int max_prime = static_cast<int>(std::sqrt(num) + 1);
            assert(max_prime <= INT_MAX);

            std::vector<int> numbers;
            numbers.resize(static_cast<size_t>(max_prime + 1));

            for (size_t i = 0; i < numbers.size(); ++i)
                numbers[i] = static_cast<int>(i);

            for (size_t i = 2; i < numbers.size() / 2; ++i)
            {
                if (numbers[i] == 0)
                    continue;

                for (size_t j = i * 2; j < numbers.size(); j += i)
                    numbers[j] = 0;
            }

            primes.reserve(numbers.size());

            std::copy_if(
                numbers.begin() + 2,
                numbers.end(),
                std::back_inserter(primes),
                [](int x) { return x > 0; });
        }

        // Find the largest prime factor of num.

        int answer = 0;

        for (auto it = primes.rbegin(); it != primes.rend(); ++it)
        {
            if (*it < 0)
                continue;

            const auto d = std::div(num, static_cast<int64_t>(*it));
            if (d.rem == 0) {
                answer = *it;
                break;
            }
        }

        const auto time = sw.GetElapsedMilliseconds();
        Utils::PrintResult(3, answer, time);
    }
}
