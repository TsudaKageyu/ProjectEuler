#include <cstdint>

int64_t Problem68()
{
    // Assume that outer nodes are 6, 10, 9, 8, and 7 to maximize the answer.

    // The sum of each set is ((6+7+8+9+10)+(1+2+3+4+5)*2)/5 = 14. So,
    //  6 + a + b = 14
    // 10 + b + c = 14
    //  9 + c + d = 14
    //  8 + d + e = 14
    //  7 + e + a = 14

    // a + b = 8, so (a, b) = (3, 5) or (5, 3).
    // b + c = 4, so b is less than 4. Then, a = 5, b = 3, c = 1.
    // Then, d = 4, e = 2.

    return 6531031914842725;
}
