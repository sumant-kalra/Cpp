#include <iostream>
#include <bitset>

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    // Right propagate the rightmost set bit in an integer valued number
    int num2 = num | (num - 1);
    std::cout << "# The input number is: " << num << " (" << std::bitset<sizeof(num) * 8>(num) << ");\n";
    std::cout << "# The result of right propagation of the rightmost set bit is: " << num2 << " (" << std::bitset<sizeof(num) * 8>(num2) << ")\n";
    return 0;
}
