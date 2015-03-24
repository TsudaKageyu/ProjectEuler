#include <iostream>
#include <cstdint>
#include <string>
#include <boost/preprocessor.hpp>
#include "utils.h"

#define PROBLEM_NO 15
#define RET_TYPE   int64_t

#define PROBLEM_FUNC BOOST_PP_CAT(Problem, PROBLEM_NO)
RET_TYPE PROBLEM_FUNC();

int main()
{
    StopWatch sw;

    const auto answer = PROBLEM_FUNC();

    sw.Stop();

    std::cout << "Answer " << PROBLEM_NO << ": " << answer << std::endl;
    std::cout << std::endl;
    std::cout << sw.GetMillisecond() << " ms" << std::endl;
    std::cout << sw.GetCpuCycle() << " cycles" << std::endl;

    return 0;
}


