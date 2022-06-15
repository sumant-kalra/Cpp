#define GENERAL_MAIN 0
#if GENERAL_MAIN

#include <iostream>

class ArrayWrap
{
private:
    const static size_t m_size = 0;
    int m_arr[m_size];

public:
    ArrayWrap()
    {
        std::cout << "Array of size: " << m_size << "\n";
        std::cout << "Address of the array: " << m_arr << "\n";
    }
    ~ArrayWrap() = default;
};

int main(int argc, char const *argv[])
{
    ArrayWrap arr;

    return 0;
}
#endif
