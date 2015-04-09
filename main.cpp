#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <boost/preprocessor.hpp>
#include "utils.h"

#define PROBLEM_NO 97
#define RET_TYPE   int64_t

#define PROBLEM_FUNC BOOST_PP_CAT(Problem, PROBLEM_NO)
RET_TYPE PROBLEM_FUNC();

const int32_t TestCount = 10;

int main()
{
    StopWatch sw;

    std::vector<RET_TYPE> answers;
    answers.reserve(TestCount);

    for (int32_t i = 0; i < TestCount; ++i)
        answers.push_back(PROBLEM_FUNC());

    sw.Stop();

    char buf[32] = {};
    ::sprintf_s(buf, "%f", sw.GetMillisecond() / TestCount);

    std::cout << "Answer " << PROBLEM_NO << ": " << answers[0] << std::endl;
    std::cout << std::endl;
    std::cout << buf << " ms" << std::endl;
    std::cout << sw.GetCpuCycle() / TestCount << " cycles" << std::endl;

    return 0;
}
