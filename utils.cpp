#include <cstdint>
#include <windows.h>
#include <intrin.h>

#include "utils.h"

StopWatch::StopWatch() :
    millisecond(0.0),
    cpuCycle(0)
{
    LARGE_INTEGER tmp;
    ::QueryPerformanceCounter(&tmp);

    startPC = tmp.QuadPart;

    UINT aux;
    startTS = ::__rdtscp(&aux);
}

void StopWatch::Stop()
{
    UINT aux;
    uint64_t endTS = ::__rdtscp(&aux);

    cpuCycle = endTS - startTS;

    LARGE_INTEGER endPC;
    QueryPerformanceCounter(&endPC);

    LARGE_INTEGER freqPC;
    QueryPerformanceFrequency(&freqPC);

    millisecond = (endPC.QuadPart - startPC) * 1000.0 / freqPC.QuadPart;
}

double StopWatch::GetMillisecond() const
{
    return millisecond;
}

uint64_t StopWatch::GetCpuCycle() const
{
    return cpuCycle;
}
