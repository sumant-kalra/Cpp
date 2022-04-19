#define TIMER 0
#define PROBLEM_1 0
#define PROBLEM_2 1

#if PROBLEM_2

#include <array>
#include <memory>
#include <timer/Timer.h>
#include <iostream>
#include "Entity.h"

int main(int argc, char *argv[])
{
    // Measure the time taken to create a static array of 100 heap allocated objects using -
    //    - shared_ptr with new, shared_ptr with make_shared , unique_ptr with new and unique_ptr with make_unique

    std::array<std::shared_ptr<entity::Entity>, 100> sharedPtrs_new;
    std::array<std::unique_ptr<entity::Entity>, 100> uniquePtrs_new;

    // [1] Static array of 100 heap allocated objects using shared_ptr with new
    std::cout << "# 100 Shared Ptrs with new\n";
    {
        timer::Timer t;
        for (auto &ptr : sharedPtrs_new)
        {
            ptr.reset(new entity::Entity());
        }
    }

    // [2] Static array of 100 heap allocated objects using shared_ptr with make_shared
    std::cout << "# 100 Shared Ptrs with make_shared\n";
    {
        timer::Timer t;
        for (auto &ptr : sharedPtrs_new)
        {
            ptr = std::make_shared<entity::Entity>();
        }
    }

    // [3] Static array of 100 heap allocated objects using unique_ptr with new
    std::cout << "# 100 Unique Ptrs with new\n";
    {
        timer::Timer t;
        for (auto &ptr : uniquePtrs_new)
        {
            ptr.reset(new entity::Entity());
        }
    }

    // [4] Static array of 100 heap allocated objects using shared_ptr with make_shared
    std::cout << "# 100 Unique Ptrs with make_unique\n";
    {
        timer::Timer t;
        for (auto &ptr : uniquePtrs_new)
        {
            ptr = std::make_unique<entity::Entity>();
        }
    }

    return 0;
}

#endif

#if PROBLEM_1
#include "timer/Timer.h"

int main(int argc, char *argv[])
{
    unsigned long long int sum = 0;
    {
        timer::Timer t;
        for (int i = 0; i < 100000; ++i)
            sum += sum;
    }

    return 0;
}

#endif

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