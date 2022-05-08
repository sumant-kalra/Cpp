// Unions
#ifndef UNION_H
#define UNION_H

// Problem
// Provide an option to consider objects of Vector4d as 2 Vector2d objects.

namespace vector
{
    struct Vector2d
    {
        float x;
        float y;
    };

    struct Vector4d
    {
        union
        {
            // Naming a struct inside an unnamed struct does not work - Compilation Error
            // 'types cannot be declared in an anonymous union'
            struct // Vec4d_4Float
            {
                float aF;
                float bF;
                float cF;
                float dF;
            }; // vec4d_4Float;

            struct // Vec4d_2Vector2d
            {
                Vector2d aVec2;
                Vector2d bVec2;
            }; // vec4d_2Vector2d;
        };
    };

    void printVector2d(const Vector2d &vec);
}

#if 0
// Solution when an unnamed struct is used
#include <iostream>
#include "Unions.h"

int main(int argc, char *argv[])
{
    vector::Vector2d vector1{3.0f, 4.0f};
    vector::Vector4d vector2{{{5.0f, 6.0f, 7.0f, 8.0f}}};

    vector::printVector2d(vector1);
    vector::printVector2d(vector2.aVec2);
    vector::printVector2d(vector2.bVec2);

    return 0;
}
#endif

#if 0
// Solution when a named struct is used
// However that does not work because 'types cannot be declared in an anonymous union'
#include <iostream>
#include "Unions.h"

int main(int argc, char *argv[])
{
    vector::Vector2d vector1{3.0f, 4.0f};
    vector::Vector4d vector2;

    vector2.vec4d_4Float.aF = 5.0f;
    vector2.vec4d_4Float.bF = 6.0f;
    vector2.vec4d_4Float.cF = 7.0f;
    vector2.vec4d_4Float.dF = 8.0f;

    vector::printVector2d(vector1);
    vector::printVector2d(vector2.vec4d_2Vector2d.aVec2);
    vector::printVector2d(vector2.vec4d_2Vector2d.bVec2);

    return 0;
}
#endif

#endif