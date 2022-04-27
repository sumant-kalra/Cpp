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
