#include <iostream>
// MACROS - Logging system based on the configuration

#if PR_RELEASE == 1
#define LOG(x)
#else
#define LOG(x) std::cout << x << "\n";
#endif

#if 0
#define MAIN    \
    int main()  \
    {           \
        LOG(4); \
    }

MAIN
#endif

int main(int argc, char *argv[])
{
    LOG(4);

    return 0;
}
