#pragma once

#include <cassert>
#include <climits>
#include <cstdint>
#include <algorithm>
#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define STRICT
#define NOMINMAX
#include <windows.h>

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
    // Returns the sum of all the natural number multiples of N no more than L.

    template <typename T, T N, T L>
    inline T GetSumOfNaturalNumberMultiples()
    {
        return N * Utils::GetSumOfNaturalNumbers<T>(L / N);
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

    // -------------------------------------------------------------------------
    // Returns the greatest common divisor of a and b.

    template <typename T>
    inline T GCD(T a, T b)
    {
        while (true)
        {
            const auto d = std::div(a, b);
            if (d.rem == 0)
                return b;

            a = b;
            b = d.rem;
        }
    }

    // -------------------------------------------------------------------------
    // Returns the least common multiple of a and b.

    template <typename T>
    inline T LCM(T a, T b)
    {
        return a * b / GCD(a, b);
    }

    // -------------------------------------------------------------------------
    // Helper class for measuring the processing time.

    class StopWatch
    {
    private:
        LARGE_INTEGER start;

    public:
        StopWatch()
        {
            ::QueryPerformanceCounter(&start);
        }

        double GetElapsedMilliseconds() const
        {
            LARGE_INTEGER end;
            ::QueryPerformanceCounter(&end);

            LARGE_INTEGER freq;
            ::QueryPerformanceFrequency(&freq);

            return (end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
        }

    private:
        StopWatch(const StopWatch &);
        StopWatch &operator=(const StopWatch &);
    };

    // -------------------------------------------------------------------------
    // Helper function for printing the results.

    template <typename T>
    void Solve(int number, const std::function<T ()> &solver)
    {
        const size_t AnswerWidth   = 12;
        const size_t TimeWidth     = 11;
        const size_t TimePrecision = 5;
        const size_t TestCount     = 3;

        using namespace std;

        cout << "Answer " << setw(2) << number << ": ";

        array<T, TestCount> answers;

        const StopWatch sw;

        for (auto &answer : answers)
            answer = solver();

        const double time = sw.GetElapsedMilliseconds() / TestCount;

        for (size_t i = 0; i < answers.size(); ++i)
        {
            if (answers[i] != answers[0])
            {
                cout << "Inconsistent!" << endl;
                return;
            }
        }

        cout << setw(AnswerWidth) << answers[0];
        cout << " (" << setw(TimeWidth) << fixed << setprecision(TimePrecision) << time << " ms)";
        cout << endl;
    }
}
