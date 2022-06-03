#define ARROW_H 0
#if ARROW_H

#include <iostream>

namespace
{
    struct Entity
    {
        int x;
        float y;
        int z;
    };

}

int main(int argc, char const *argv[])
{
    Entity *ptr = nullptr;
    int *offset = &(ptr->z);

    std::cout << (size_t)offset << "\n";

    return 0;
}

#endif