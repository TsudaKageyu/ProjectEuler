#include <cstdint>

namespace
{
    int64_t GetHash(int32_t x)
    {
        int64_t h = 0;

        while (x != 0)
        {
            h += 1LL << ((x % 10) * 4);
            h += 1LL << 40;

            x /= 10;
        }

        return h;
    }
}

int64_t Problem52()
{
    for (int32_t n = 1;; ++n)
    {
        const auto h = GetHash(n);

        for (int32_t k = 2; k <= 6; ++k)
        {
            if (GetHash(n * k) != h)
                goto NEXT;
        }

        return n;

    NEXT:
        ;
    }

    return 0;
}
