#include "common.h"
#include "problem1.h"
#include "problem2.h"
#include "problem3.h"
#include "problem4.h"
#include "problem5.h"
#include "problem6.h"
#include "problem7.h"
#include "problem8.h"
#include "problem9.h"
#include "problem10.h"

int main()
{
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
