#pragma once

namespace Utils
{
    const int64_t PrimeMax  = 2000000;

    const size_t TestCount = 3;

    const size_t AnswerWidth   = 12;
    const size_t TimeWidth     = 10;
    const size_t TimePrecision = 4;

    // -------------------------------------------------------------------------
    // Returns a list of prime numbers no more than Utils::PrimeMax.

    const std::vector<int64_t> & GetPrimeTable();

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
    // Returns the greatest common divisor of a and b.

    template <typename T>
    inline T GCD(T a, T b)
    {
        while (true)
        {
            const auto rem = a % b;
            if (rem == 0)
                return b;

            a = b;
            b = rem;
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
    // Returns the factorial of n.

    template <typename T, typename U>
    inline T GetFactorial(U n)
    {
        T f = 1;

        for (U i = 2; i <= n; ++i)
            f *= i;

        return f;
    }

    // -------------------------------------------------------------------------
    // Returns the sum of all digits of n.

    template <typename T = int64_t, typename U>
    inline T GetSumOfDigits(U n)
    {
        const auto s = n.str();

        std::vector<int> digits;
        digits.reserve(s.size());

        std::transform(
            s.begin(),
            s.end(),
            std::back_inserter(digits),
            [](char c) { return static_cast<int>(c) - '0'; });

        return std::accumulate(digits.begin(), digits.end(), static_cast<T>(0));
    }

    // -------------------------------------------------------------------------
    // Helper class for measuring the processing time.

    class StopWatch
    {
    private:
        LARGE_INTEGER start;

    public:
        StopWatch();

        double GetElapsedMilliseconds() const;

    private:
        StopWatch(const StopWatch &);
        StopWatch &operator=(const StopWatch &);
    };

    // -------------------------------------------------------------------------
    // Helper function for printing the results.

    template <typename T>
    void Solve(int number, const std::function<T ()> &solver)
    {
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

    // -------------------------------------------------------------------------
    // Returns the running CPU name.

    std::string GetCPUName();
}
