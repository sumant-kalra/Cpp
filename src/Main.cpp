#include <iostream>
#include <bitset>

int main(int argc, char *argv[])
{
    unsigned int num = atoi(argv[1]);
    unsigned int power = atoi(argv[2]);

    // Compute an integer valued number modulo a power of 2
    std::cout << num << "%2^(" << power << ") is: " << num % (1 << power) << "\n";

    return 0;
}
