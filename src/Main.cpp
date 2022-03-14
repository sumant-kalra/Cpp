#include <iostream>

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    int countOfOnes = 0;

    // Approach 1
    // Iterate over all the bits of the number input
    // Check for each digit to be 1 or 0 by bitmasking with appropriate number
#if 0
    int bitmask = 1;
    const size_t BIT_COUNT = sizeof(num) * 8;
    for (size_t i = 0; i < BIT_COUNT; ++i)
    {
        if (num & bitmask)
            ++countOfOnes;
        bitmask <<= 1;
    }
    std::cout << "The count of 1s is: " << countOfOnes << "\n";
#endif

    // Approach 2
    // Keep on isolating the lowest bit until we can and count it, while updating the original number with the 1 removed
    int num2 = 0;
    while (num) // The input is non-zero which means that it has atleast one bit which is 1
    {
        ++countOfOnes; // The number 'num' has one bit which is non-zero
        // Since one bit which is non-zero is counted, we should remove a non zero bit from the number
        // We will remove the lowest bit that is 1, from the number
        num2 = num & ~(num - 1); // Isolate the lowest bit that is 1
        num ^= num2;             // Remove the isolated bit from the original number
        // Iterate until every 1 is removed
    }
    std::cout << "The count of 1s is: " << countOfOnes << "\n";

    return 0;
}
