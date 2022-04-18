#define TIMER 1
#if TIMER

#include <chrono>
#include <iostream>
#include <timer/Timer.h>

static void run(int n);

int main(int argc, char *argv[])
{
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    run(10000);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> timeTaken = t2 - t1;
    std::cout << "The time taken is: " << timeTaken.count() << " s\n";
    std::cout << "The time taken is: " << timeTaken.count() * 1000 << " ms\n";

    // Using ints and duration cast
    // Time in miliseconds
    std::chrono::duration<int, std::ratio<1, 1000>> timeTaken_miliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << "The time taken is: " << timeTaken_miliseconds.count() << " ms\n";
    // By default, the time measured by high_resolution_clock is in nanoseconds
    auto timeTaken_nanoseconds = t2 - t1;
    std::cout << "The time taken is: " << timeTaken_nanoseconds.count() << " ns\n";

    {
        timer::Timer t;
        run(100000);
    }

    return 0;
}

void run(int n)
{
    while (n--)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";
}

#endif