#pragma once
#include <boost/noncopyable.hpp>

class StopWatch : boost::noncopyable
{
private:
    uint64_t startPC;
    uint64_t startTS;

    double   millisecond;
    uint64_t cpuCycle;

public:
    StopWatch();

    void Stop();

    double   GetMillisecond() const;
    uint64_t GetCpuCycle() const;
};
