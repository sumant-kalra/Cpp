#ifndef CALLBACK_H
#define CALLBACK_H
#include <vector>
#include <functional>

namespace callback
{
    // [1] ForEach callback function for a vector + 'Function pointer' as callable that prints the number
    void ForEach_1(const std::vector<int> &myVector, void (*print)(int number));
    // [2] ForEach callback function for a vector + 'Lambda' as callable that prints the number
    void ForEach_2(const std::vector<int> &myVector, const std::function<void(int)> &funObj);
    // [3] Sort a vector using std::sort in ascending order + 'Function pointer' as callable
    // [4] Sort a vector using std::sort in ascending order + 'Lambda' as callable
    // [5] Sort a vector using std::sort in ascending order + 'Functor' as callable
    // [6] Sort a vector using std::sort in ascending order + 'std::function' object as callable
    // [7] Sort a vector using std::sort in descending order + 'Function pointer' as callable
    // [8] Sort a vector using std::sort in descending order + 'Lambda' as callable
    // [9] Sort a vector using std::sort in descending order + 'Functor' as callable
    // [10] Sort a vector using std::sort in descending order + 'std::function' object as callable
    // [11] Sort a vector except using std::sort except one element by keeping it at the first or the last location

}

#endif