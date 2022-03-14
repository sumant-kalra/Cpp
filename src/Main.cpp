#include <iostream>
#include <bitset>

int main(int argc, char *argv[])
{
    unsigned int num = atoi(argv[1]);
    // Test if an integer valued number is a power of 2
    // True, if the count of 1 in the binary representation of the number is 1

    int countOfOnes = 0;
    while (num)
    {
        ++countOfOnes;
        num &= (num - 1);
    }
    if (countOfOnes == 1)
        std::cout << "Yes, the number is a power of 2\n";
    else
        std::cout << "No, the number is not a power of 2\n";

    return 0;
}
