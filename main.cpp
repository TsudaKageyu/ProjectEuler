#include "stdafx.h"
#include "utils.h"
#include "Problem001to010/problems.h"
#include "Problem011to020/problems.h"
#include "Problem021to030/problems.h"
#include "Problem061to070/problems.h"

int main()
{
    std::cout << Utils::GetCPUName() << std::endl;
    std::cout << std::endl;

    std::cout << "Preparing prime numbers <= " << Utils::PrimeMax << ": ";
    const auto &table = Utils::GetPrimeTable();

    std::cout << table.size() << " prime numbers." << std::endl;
    std::cout << std::endl;

    Utils::Solve<int64_t>(25, [] { return Problem25(); });
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

    Utils::Solve<int64_t>(11, [] { return Problem11(); });
    Utils::Solve<int64_t>(12, [] { return Problem12(); });
    Utils::Solve<std::string>(13, [] { return Problem13(); });
    Utils::Solve<int64_t>(14, [] { return Problem14(); });
    Utils::Solve<int64_t>(15, [] { return Problem15(); });
    Utils::Solve<int64_t>(16, [] { return Problem16(); });
    Utils::Solve<int64_t>(17, [] { return Problem17(); });
    Utils::Solve<int64_t>(18, [] { return Problem18(); });
    Utils::Solve<int64_t>(19, [] { return Problem19(); });
    Utils::Solve<int64_t>(20, [] { return Problem20(); });

    Utils::Solve<int64_t>(21, [] { return Problem21(); });
    Utils::Solve<int64_t>(22, [] { return Problem22(); });
    Utils::Solve<std::string>(24, [] { return Problem24(); });

    Utils::Solve<int64_t>(67, [] { return Problem67(); });

    return 0;
}
