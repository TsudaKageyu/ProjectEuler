#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <boost/preprocessor.hpp>
#include "utils.h"

using namespace std;

#define PROBLEM_NO 76
#define RET_TYPE   int64_t

#define PROBLEM_FUNC BOOST_PP_CAT(Problem, PROBLEM_NO)
RET_TYPE PROBLEM_FUNC();

const int32_t TestCount = 10;

int main()
{
    StopWatch sw;

    vector<RET_TYPE> answers;
    answers.reserve(TestCount);

    for (int32_t i = 0; i < TestCount; ++i)
        answers.push_back(PROBLEM_FUNC());

    sw.Stop();

    char buf[32] = {};
    ::sprintf_s(buf, "%f", sw.GetMillisecond() / TestCount);

    cout << "Answer " << PROBLEM_NO << ": " << answers[0] << endl;
    cout << endl;
    cout << buf << " ms" << endl;
    cout << sw.GetCpuCycle() / TestCount << " cycles" << endl;

    return 0;
}
