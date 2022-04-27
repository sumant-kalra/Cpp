#define CALLBACK 1
#if CALLBACK

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#include "Callback.h"

// [1]
static void print(int n);

int main(int argc, char *argv[])
{
    unsigned int seed = std::chrono::high_resolution_clock::time_point().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(-100, 100);

    unsigned int countElementsVector = 10;
    std::vector<int> myVector;
    myVector.reserve(countElementsVector);
    for (int i = 0; i < countElementsVector; ++i)
    {
        myVector.emplace_back(distribution(generator));
    }

    // [1]
    // ForEach callback function for a vector + 'Function pointer' as callable that prints the number
    callback::ForEach_1(myVector, print);
    std::cout << "\n";

    // [2]
    // ForEach callback function for a vector + 'Function pointer' as callable that prints the number
    auto printAn_1 = [](int a)
    {
        std::cout << a << " ";
    };

    callback::ForEach_1(myVector, printAn_1);
    std::cout << "\n";

    int testvar = 1;
    auto printAn_2 = [testvar](int a) mutable
    {
        testvar = 2;
        std::cout << a << " ";
    };

    callback::ForEach_2(myVector, printAn_2);
    std::cout << "\n";

    return 0;
}

// [1]
// ------------------------------------------------------------------------------------------ //
static void print(int n)
{
    std::cout << n << " ";
}

#endif