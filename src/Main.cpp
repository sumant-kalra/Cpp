// Benchmarking

#ifdef _MSC_VER_
#define DEBUG_BREAK __debugbreak()
#elif defined __APPLE__ || defined __unix__
#define DEBUG_BREAK raise(SIGTRAP)
#endif

#include <signal.h>
#include <iostream>
#include <array>
#include <memory>

#include "Timer.h"

int main(int argc, char* argv[])
{
    std::cout<<"Sum of integers:\n";
    int sum = 0;
    {
        timer::Timer t;
        for(int i =0;i<=100000;++i)
            sum += i;
    }
    std::cout<<sum<<"\n";

#if 0
    // The code below will throw an exception if not run in debug mode
    DEBUG_BREAK;
#endif

    return 0;
}
