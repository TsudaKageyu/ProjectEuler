#include <windows.h>
#include <string>

class StopWatch
{
private:
    LARGE_INTEGER start;

public:
    StopWatch()
    {
        ::QueryPerformanceCounter(&start);
    }

    std::string GetElapsedMilliseconds() const
    {
        LARGE_INTEGER end;
        ::QueryPerformanceCounter(&end);

        LARGE_INTEGER freq;
        ::QueryPerformanceFrequency(&freq);

        const double elapsed = (end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;

        char buf[32];
        ::sprintf_s(buf, "%.5f ms", elapsed);

        return std::string(buf);
    }

private:
    StopWatch(const StopWatch &);
    StopWatch &operator=(const StopWatch &);
};
