#include <cassert>
#include <cstdint>
#include <algorithm>
#include <vector>

int64_t Problem10()
{
    using namespace std;

    const int64_t N = 2000000;

    // Roughly estimate the limit of the search.

    int64_t l;
    for (l = N * 2;; l *= 2)
    {
        const double x = static_cast<double>(l);
        if (x / log(x) > N)
            break;
    }

    // Sieve of Eratosthenes.

    vector<int32_t> sieve(l + 1);
    sieve[2] = 2;

    for (int32_t i = 3; i <= l; i += 2)
        sieve[i] = i;

    for (int32_t i = 3; i * i <= l; ++i)
    {
        if (sieve[i] == 0)
            continue;

        for (int32_t j = i * 2; j <= l; j += i)
            sieve[j] = 0;
    }

    assert(*max_element(sieve.begin(), sieve.end()) >= N);

    // Add up the primes.

    int64_t answer = 0;
    for (const auto prime : sieve)
    {
        if (prime >= N)
            break;

        answer += prime;
    }

    return answer;
}
