#pragma once

namespace Utils
{
    const int64_t PrimeMax  = 2000000;

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
    // Returns N ^ M.

    template <typename T, T N, T M>
    T Power()
    {
        T ret = 1;

        for (T i = 0; i < M; ++i)
            ret *= N;

        return ret;
    }

    // -------------------------------------------------------------------------
    // Returns D + 1 th digit of n.

    template <typename T, T D>
    T GetDigit(T n)
    {
        return (n / Power<T, static_cast<T>(10), D>()) % static_cast<T>(10);
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
    // Returns the sum of all proper divisors of n.

    template <typename T>
    T GetSumOfProperDivisors(T n)
    {
        T sum = 1;

        for (T i = 2; i < static_cast<T>(std::sqrt(n) + 1); ++i)
        {
            if (n % i == 0)
            {
                sum += i;

                if (n / i != i)
                    sum += n / i;
            }
        }

        return sum;
    }

    // -------------------------------------------------------------------------
    // Returns wheter or not n is palindromic like "123321".

    template <typename T>
    inline bool IsPalindromic(T n)
    {
        assert(n <= 999999);

        if (n == 0)
            return true;

        const std::array<T, 6> digits = {
            Utils::GetDigit<T, 0>(n),
            Utils::GetDigit<T, 1>(n),
            Utils::GetDigit<T, 2>(n),
            Utils::GetDigit<T, 3>(n),
            Utils::GetDigit<T, 4>(n),
            Utils::GetDigit<T, 5>(n)
        };

        size_t size = digits.size();
        while (digits[size - 1] == 0)
            size--;

        for (size_t i = 0; i < size / 2; ++i)
        {
            if (digits[i] != digits[size - i - 1])
                return false;
        }

        return true;
    }

    // -------------------------------------------------------------------------
    // Helper function for printing the results.

    void Solve(int number, const std::function<int64_t ()> &solver);

    // -------------------------------------------------------------------------
    // Returns the running CPU name.

    std::string GetCPUName();
}
