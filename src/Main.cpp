#include <iostream>
#include <bitset>

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    // The number after replacing the lowest bit that is 1 with 0
    int num2 = num & (num - 1);
    std::cout << "# The input number is: " << num << " (" << std::bitset<sizeof(num) * 8>(num) << ");\n";
    std::cout << "# The new number after replacing the lowest bit that is 1: " << num2 << " (" << std::bitset<sizeof(num) * 8>(num2) << ")\n";

    // Note that the above code can also be used to count the number of 1s present in the number
    int countOfOnes = 0;
    while (num)
    {
        ++countOfOnes;
        num &= (num - 1); // num = num & (num - 1) --> Equivalent to num = num ^ (num & ~(num-1))
    }
    std::cout << "# The number of 1s present in the original number: " << countOfOnes << "\n";

    return 0;
}
