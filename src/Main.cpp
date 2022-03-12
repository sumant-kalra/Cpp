#include <iostream>
#include <bitset>
#include <cstdlib>

int main(int argc, char *argv[])
{
    int num1 = atoi(argv[1]);
    const size_t bitCount = sizeof(num1) * 8;

    // Counting the number of bits in the number num1
    size_t countOfOnes = 0;
    int bitmask = 1;
    for (size_t i = 0; i < bitCount; ++i)
    {
        if (num1 & bitmask)
            countOfOnes++;
        bitmask <<= 1;
    }
    std::cout << countOfOnes << "\n";

    return 0;
}