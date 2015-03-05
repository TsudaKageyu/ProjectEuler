#pragma once

namespace Utils
{
    const int64_t PrimeMax = 2000000;

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

    // -------------------------------------------------------------------------
    // Returns the running CPU name.

    std::string GetCPUName();
}