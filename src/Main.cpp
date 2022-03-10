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

struct Entity
{
    float num1;
    float num2;
};

int main(int argc, char* argv[])
{
#if 0
    std::cout<<"Sum of integers:\n";
    int sum = 0;
    {
        timer::Timer t;
        for(int i =0;i<=100000;++i)
            sum += i;
    }
    std::cout<<sum<<"\n";
#endif 

    // Array of 1000 shared pointers - using new keyword
    std::array<std::shared_ptr<Entity>,1000> arraySharedPtrsNew;

    std::cout<<"1000 shared pointers allocation using 'new' keyword\n";
    {
        timer::Timer t;
        for(auto& ptr:arraySharedPtrsNew)
            ptr = std::shared_ptr<Entity>(new Entity());
    }


    // Array of 1000 shared pointers - using make_shared
    std::array<std::shared_ptr<Entity>,1000> arraySharedPtrsMakeShared;

    std::cout<<"1000 shared pointers allocation using 'make_shared'\n";
    {
        timer::Timer t;
        for(auto& ptr : arraySharedPtrsMakeShared) 
            ptr = std::make_shared<Entity>();
    }


    // Array of 1000 unique pointers - using new keyword
    std::array<std::unique_ptr<Entity>,1000> arrayUniquePtrsNew;
    
    std::cout<<"1000 unique pointers allocation using 'new' keyword\n";
    {
        timer::Timer t;
        for(auto& ptr : arrayUniquePtrsNew)
            ptr = std::unique_ptr<Entity>(new Entity());
    }

    // Array of 1000 unique pointers - using make_unique keyword
    std::array<std::unique_ptr<Entity>,1000> arrayUniquePtrsMakeUnique;

    std::cout<<"1000 unique pointers allocation using 'make_unique'\n";
    {
        timer::Timer t;
        for(auto& ptr : arrayUniquePtrsMakeUnique)
            ptr = std::make_unique<Entity>();
    }

#if 0
    // The code below will throw an exception if not run in debug mode
    DEBUG_BREAK;
#endif

    return 0;
}
