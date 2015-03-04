#include "common.h"
#include "problem3.h"

namespace problem3
{
    void Solve()
    {
        StopWatch sw;

        const int64_t num = 600851475143;

        // List the prime numbers no more than sqrt(num).

        const int64_t max_prime = static_cast<int64_t>(std::sqrt(num) + 1);
        assert(max_prime <= INT_MAX);

        std::vector<int> primes;
        primes.reserve(static_cast<int>(max_prime / 2));

        primes.push_back(2);

        for (int i = 3; i <= max_prime; i += 2)
            primes.push_back(i);

        std::vector<int> tmp;
        tmp.reserve(primes.size());

        for (size_t i = 1; i < primes.size() - 2; ++i)
        {
            if (primes[i] > primes.back() / 2)
                break;

            tmp.resize(i + 1);
            ::memcpy(tmp.data(), primes.data(), (i + 1) * sizeof(primes.front()));

            for (size_t j = i + 1; j < primes.size() - 1; ++j)
            {
                if (primes[j] % primes[i] != 0)
                    tmp.push_back(primes[j]);
            }

            std::swap(tmp, primes);
            tmp.clear();
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
        std::cout << "Answer3: " << answer << time << std::endl;
    }
}
