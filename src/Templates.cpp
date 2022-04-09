#define MAIN1 0
#define MAIN2 1

// Problem1
// Write a function that can take std::array object of any size as parameter
#if MAIN1

#include <array>
#include <iostream>

// Without using the templates, we need to hardcode the Size of the array in the function declaration and the definition itself
// Only the arrays with size = 10 can be passed to this function
int sumOfElements1(const std::array<int, 10> &array)
{
    return 1;
}

// Templating the Size of the array in the function
// Compiler generates the code for functions taking different array sizes
template <int SIZE>
int sumOfElements2(const std::array<int, SIZE> &array)
{
    return 2;
}

int main(int argc, char *argv[])
{
    std::array<int, 10> array1;
    std::array<int, 20> array2;

    // sumOfElements1 can take only an array of size 10 as argument
    std::cout << sumOfElements1(array1) << "\n";
    // The below code does not work
    // sumOfElements1(array2);

    // sumOfElements2 can take arrays of different sizes as argument with the array size as a template parameter
    std::cout << sumOfElements2<10>(array1) << "\n";
    std::cout << sumOfElements2<20>(array2) << "\n";

    return 0;
}
#endif

// Problem2
// Implement std::array class
#if MAIN2

#include <iostream>

#include "Templates.h"

int main(int argc, char *argv[])
{
    templates::Array<int, 0> myArray;

    return 0;
}

#endif
