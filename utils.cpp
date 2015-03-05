#include "stdafx.h"
#include "utils.h"

namespace
{
    std::vector<int64_t> InitializePrimeTable(int64_t n)
    {
        std::vector<int64_t> numbers;
        numbers.resize(n);

        // We never use [0] and [1], but they can make the code a bit clearer.

        numbers[2] = 2;

        for (size_t i = 3; i < numbers.size(); i += 2)
            numbers[i] = static_cast<int>(i);

        const size_t loopMax = static_cast<size_t>(std::sqrt(numbers.size()));
        for (size_t i = 3; i <= loopMax; ++i)
        {
            if (numbers[i] == 0)
                continue;

            for (size_t j = i * 2; j < numbers.size(); j += i)
                numbers[j] = 0;
        }

        std::vector<int64_t> primes;
        primes.reserve(numbers.size());

        std::copy_if(
            numbers.begin() + 2,
            numbers.end(),
            std::back_inserter(primes),
            [](int x) { return x > 0; });

        primes.shrink_to_fit();

        return primes;
    }
}

namespace Utils
{
    const std::vector<int64_t> & GetPrimeTable()
    {
        static std::vector<int64_t> table = InitializePrimeTable(PrimeMax);

        return table;
    }

    std::string GetCPUName()
    {
        std::array<int, 4> info;
        __cpuid(info.data(), 0x80000000);

        if (static_cast<uint32_t>(info[0]) < 0x80000004U)
            return "Unknown CPU";

        std::string name;
        name.resize(48);

        __cpuid(info.data(), 0x80000002);
        ::memcpy(&name[0], &info, sizeof(info));

        __cpuid(info.data(), 0x80000003);
        ::memcpy(&name[16], &info, sizeof(info));

        __cpuid(info.data(), 0x80000004);
        ::memcpy(&name[32], &info, sizeof(info));

        const size_t pos = name.find_first_not_of(" ");
        if (pos != std::string::npos)
            name = name.substr(pos);

        return name;
    }
}
