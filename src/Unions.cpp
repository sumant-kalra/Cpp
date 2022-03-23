#include <iostream>
#include "Unions.h"

void vector::printVector2d(const Vector2d &vec)
{
    std::cout << "First: " << vec.x << ", Second: " << vec.y << "\n";
}

#if 0
// Program when unnamed struct is used
#include <iostream>
#include "Unions.h"

int main(int argc, char *argv[])
{
    vector::Vector2d vector1{3.0f, 4.0f};
    vector::Vector4d vector2;
    vector2.aF = 5.0f;
    vector2.bF = 6.0f;
    vector2.cF = 7.0f;
    vector2.dF = 8.0f;

    vector::printVector2d(vector1);
    vector::printVector2d(vector2.aVec2);
    vector::printVector2d(vector2.bVec2);

    return 0;
}

#endif