#ifndef TIMER_H
#define TIMER_H

#include <chrono>

namespace timer
{
    class Timer
    {
    private:
        std::chrono::high_resolution_clock::time_point m_startTime;

    public:
        Timer();
        ~Timer();
    };
}

#endif
