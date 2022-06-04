#define MAIN_CONSTANTS 0
#if MAIN_CONSTANTS

#include <iostream>

static int num = 0;

static int const &fun2()
{
    return num;
}

static const int *fun()
{
    int *p = new int(0);
    return p;
}

int main(int argc, char *argv[])
{
    // [1]
    const int NUM = 1;
    int *ptr = (int *)&NUM; // Causes undefined behaviour in the program
    *ptr = 2;

    std::cout << *ptr << "\n";

    std::cout << NUM << "\n";
    std::cout << 1 << "\n"; // Because of optimizations: NUM is replaced with 1 as you promised that it will not be changed.
    // But since you broke you promise by using pointers, the overall program causes undefined behavior.

    // [2]
    const int *ptr1 = fun();  // fun() returns a const pointer
    int *ptr2 = (int *)fun(); // const_cast

    //[3]
    int const &n = fun2();

    std::cout << ptr1 << "\n";
    std::cout << ptr2 << "\n";
    std::cout << n << "\n";

    return 0;
}

#endif