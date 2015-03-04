#include "common.h"

namespace problem7
{
    void Solve()
    {
        StopWatch sw;

        int answer;

        for (int n = 100000; ; n += 100000)
        {
            const auto primes = Utils::GetPrimeNumbers<int>(n);
            if (primes.size() >= 10001)
            {
                answer = primes[10000];
                break;
            }
        }

        const auto time = sw.GetElapsedMilliseconds();
        Utils::PrintResult(7, answer, time);
    }
}
