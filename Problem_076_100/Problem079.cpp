#include <cstdint>
#include <array>
#include <string>

using namespace std;

namespace
{
    const array<string, 50> Codes = {
        "319",
        "680",
        "180",
        "690",
        "129",
        "620",
        "762",
        "689",
        "762",
        "318",
        "368",
        "710",
        "720",
        "710",
        "629",
        "168",
        "160",
        "689",
        "716",
        "731",
        "736",
        "729",
        "316",
        "729",
        "729",
        "710",
        "769",
        "290",
        "719",
        "680",
        "318",
        "389",
        "162",
        "289",
        "162",
        "718",
        "729",
        "319",
        "790",
        "680",
        "890",
        "362",
        "319",
        "760",
        "316",
        "729",
        "380",
        "319",
        "728",
        "716"
    };
}

int64_t Problem79()
{
    string answer = "0";

    for (char c = '1'; c <= '9'; ++c)
    {
        size_t p = answer.size() + 1;

        for (size_t i = 0; i < answer.size(); ++i)
        {
            if (i >= p)
                break;

            for (const auto &code : Codes)
            {
                const size_t q = code.find(answer[i]);
                if (q == string::npos)
                    continue;

                const size_t r = code.find(c);
                if (r == string::npos)
                    continue;

                if (r < q)
                    p = i;
            }
        }

        if (p <= answer.size())
            answer.insert(p, 1, c);
    }

    return ::atoll(answer.c_str());
}
