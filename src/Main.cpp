#include <iostream>
int main(int argc, char *argv[])
{
    // Get the number from cmd line args
    int num1 = atoi(argv[1]);

    // Total number of bits used for the number
    const size_t BIT_COUNT = sizeof(num1) * 8;

    int countOfOnes = 0;
    int bitmask = 1; // Binary number with same number of bits as the original number but the LSB as 1

    // Iterating over all the bits in the number and checking every single bit if it is 1.
    // If the bit is not 1 that it is 0, then the resulting number is also 0 otherwise
    // it will be anything but 0.
    for (size_t i = 0; i < BIT_COUNT; ++i)
    {
        if (num1 & bitmask)
            countOfOnes++;
        bitmask <<= 1;
    }
    std::cout << countOfOnes << "\n";
}