#include "common.h"
#include "problem3.h"

namespace problem3
{
    void Solve()
    {
        StopWatch sw;

        const int64_t num = 600851475143;

        // List the prime numbers no more than sqrt(num).

        const int64_t max_prime = static_cast<int64_t>(std::sqrt(num));
        assert(max_prime <= INT_MAX);

        std::vector<int> primes;
        primes.reserve(static_cast<int>(max_prime / 2));

        for (int i = 3; i <= max_prime; i += 2)
            primes.push_back(i);

        auto it1 = primes.begin();
        auto it2 = primes.end();

        while (true)
        {
            const auto it3 = std::remove_if(it1 + 1, it2, [&](int x) { return (x % *it1 == 0); });
            if (it3 == it2)
                break;

            it2 = it3;
            it1++;
        }

        // Find the largest prime factor of num.

        int answer = 0;

        for (auto it = it2; it >= it1; --it)
        {
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
