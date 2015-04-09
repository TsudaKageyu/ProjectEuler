#include <cstdint>
#include <utility>

using namespace std;

namespace
{
    int32_t gcd(int32_t a, int32_t b)
    {
        while (a % b != 0)
        {
            a = a % b;
            swap(a, b);
        }

        return b;
    }

    struct Fraction
    {
        Fraction() : num(0), den(0) {}
        Fraction(int32_t n, int32_t d) : num(n), den(d) {}

        int32_t num;
        int32_t den;
    };

    bool operator==(const Fraction &lhs, const Fraction &rhs)
    {
        return (lhs.num == rhs.num && lhs.den == rhs.den);
    }

    Fraction Reduction(Fraction f)
    {
        const int g = gcd(f.num, f.den);
        f.num /= g;
        f.den /= g;

        return f;
    }
}

int64_t Problem33()
{
    int32_t num = 1;
    int32_t den = 1;

    for (int32_t d = 12; d <= 99; ++d)
    {
        const int32_t d0 = d % 10;
        const int32_t d1 = d / 10;
        if (d0 == 0)
            continue;

        for (int32_t n = 11; n < d; ++n)
        {
            const int32_t n0 = n % 10;
            const int32_t n1 = n / 10;
            if (n0 == 0)
                continue;

            Fraction f0 = Reduction(Fraction(n, d));
            Fraction f1;
            if (n0 == d0)
                f1 = Reduction(Fraction(n1, d1));
            else if (n1 == d0)
                f1 = Reduction(Fraction(n0, d1));
            else if (n0 == d1)
                f1 = Reduction(Fraction(n1, d0));
            else if (n1 == d1)
                f1 = Reduction(Fraction(n0, d0));

            if (f0 == f1)
            {
                num *= n;
                den *= d;
            }
        }
    }

    den /= gcd(num, den);

    return den;
}
