#include <iostream>
#include <cmath>

#include "Timer.h"

timer::Timer::Timer()
{
    m_startTime = std::chrono::high_resolution_clock::now();
}

timer::Timer::~Timer()
{
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timeTaken = endTime - m_startTime;
    std::cout<<"The time taken: "<< timeTaken.count() * (std::pow(10.0,6.0)) <<" us\n";
}
