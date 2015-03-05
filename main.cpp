#include "stdafx.h"
#include "utils.h"
#include "Problem001to010/problems.h"

int main()
{
    std::cout << Utils::GetCPUName() << std::endl;
    std::cout << std::endl;

    std::cout << "Preparing prime numbers <= " << Utils::PrimeMax << ": ";
    const auto &table = Utils::GetPrimeTable();

    std::cout << table.size() << " prime numbers." << std::endl;
    std::cout << std::endl;

    Utils::Solve<int64_t>( 1, [] { return Problem1(); });
    Utils::Solve<int64_t>( 2, [] { return Problem2(); });
    Utils::Solve<int64_t>( 3, [] { return Problem3(); });
    Utils::Solve<int64_t>( 4, [] { return Problem4(); });
    Utils::Solve<int64_t>( 5, [] { return Problem5(); });
    Utils::Solve<int64_t>( 6, [] { return Problem6(); });
    Utils::Solve<int64_t>( 7, [] { return Problem7(); });
    Utils::Solve<int64_t>( 8, [] { return Problem8(); });
    Utils::Solve<int64_t>( 9, [] { return Problem9(); });
    Utils::Solve<int64_t>(10, [] { return Problem10(); });

    return 0;
}
