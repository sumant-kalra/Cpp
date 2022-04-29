#include "Callback.h"

// [1]
// ------------------------------------------------------------------------------------------ //
void callback::ForEach_1(const std::vector<int> &myVector, void (*print)(int number))
{
    for (const auto &n : myVector)
        print(n);
}

// [2]
// ------------------------------------------------------------------------------------------ //
void callback::ForEach_2(const std::vector<int> &myVector, const std::function<void(int)> &funObj)
{
    for (const auto &n : myVector)
        funObj(n);
}
// ------------------------------------------------------------------------------------------ //
// ---------------------------------          MAIN          --------------------------------- //
// ------------------------------------------------------------------------------------------ //
#define CALLBACK_MAIN 0
#if CALLBACK_MAIN

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <functional>

#include "Callback.h"

// [1]
static void printVector(const std::vector<int> &myVector);

static void print(int n);
static bool ascending(int a, int b);
struct Ascending
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
} ascendingObj;
static bool descending(int a, int b);
struct Descending
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
} descendingObj;

int main(int argc, char *argv[])
{
    // [0]
    // A vector with 10 random values in the range [-100, 100]
    unsigned int seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(-100, 100);

    std::vector<int> myVector;

    unsigned int countElementsVector = 10;
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

    // [3]
    // Sort a vector using std::sort in ascending order + 'Function pointer' as callable
    std::sort(myVector.begin(), myVector.end(), ascending);

    // [4]
    // Sort a vector using std::sort in ascending order + 'Lambda' as callable
    std::sort(myVector.begin(), myVector.end(), [](int a, int b)
              { return a < b; });

    // [5]
    // Sort a vector using std::sort in ascending order + 'Functor' as callable
    std::sort(myVector.begin(), myVector.end(), ascendingObj);
    printVector(myVector);

    // [6]
    // Sort a vector using std::sort in ascending order + 'std::function' object as callable
    std::sort(myVector.begin(), myVector.end(), std::less<int>());
    printVector(myVector);

    // [7]
    // Sort a vector using std::sort in descending order + 'Function pointer' as callable
    std::sort(myVector.begin(), myVector.end(), descending);
    printVector(myVector);

    // [8]
    // Sort a vector using std::sort in descending order + 'Lambda' as callable
    std::sort(myVector.begin(), myVector.end(), [](int a, int b)
              { return a > b; });
    printVector(myVector);

    // [9]
    // Sort a vector using std::sort in descending order + 'Functor' as callable
    std::sort(myVector.begin(), myVector.end(), descendingObj);
    printVector(myVector);

    // [10]
    // Sort a vector using std::sort in descending order + 'std::function' object as callable
    std::sort(myVector.begin(), myVector.end(), std::greater<int>());
    printVector(myVector);

    // [11] Sort a vector except using std::sort except one element by keeping it at the first or the last location
    std::vector<int> vectorSpecific{83, 723, -123, 34, 23, 98, 90, 44, 33};
    /// Move 34 to the front
    std::sort(vectorSpecific.begin(), vectorSpecific.end(), [](int a, int b)
              { 
                //// Providing conditions when a = 34 or b =34
                if(a==34)
                    return true;
                if(b==34)
                    return false;
                //// For the rest of the elements
                return a < b; });

    printVector(vectorSpecific);

    /// Move 34 to the back
    std::sort(vectorSpecific.begin(), vectorSpecific.end(), [](int a, int b)
              {
                if(a==34)
                    return false;
                if(b==34)
                    return true;
                return a<b; });

    printVector(vectorSpecific);

    return 0;
}

// ------------------------------------------------------------------------------------------ //

static void printVector(const std::vector<int> &myVector)
{
    for (const auto &e : myVector)
        std::cout << e << " ";
    std::cout << "\n";
}

// [1]
// ------------------------------------------------------------------------------------------ //
static void print(int n)
{
    std::cout << n << " ";
}

// [3]
// ------------------------------------------------------------------------------------------ //
static bool ascending(int a, int b)
{
    return a < b;
}

static bool descending(int a, int b)
{
    return a > b;
}

#endif
