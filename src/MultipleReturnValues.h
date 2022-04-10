#ifndef MULTIPLE_RETURN_VALUES_H
#define MULTIPLE_RETURN_VALUES_H

#include <array>
#include <vector>
#include <tuple>
#include <utility>

// Note that Tuples and Pairs are stored all in stack, they are just like structs but with additional functionalities
// But always prefer structs over Tuples and Pairs

#include "Entity.h"

namespace returnTypes
{
    struct string2d
    {
        std::string str1;
        std::string str2;
    };

    // Problem 1: Return a reference or a pointer from a method
    // 1.1
    entity::Entity &testMethod1();
    // 1.2
    entity::Entity *testMethod2();

    // Problem 2: Pass by value, Pass by reference and Pass by address
    // 2.1
    void assign10_1(int **p);
    // 2.2
    void assign10_2(int *&p);

    // Problem 3: Return multiple values from function
    // 3.1
    void fillStrings1(std::string &s1, std::string &s2);
    // 3.2
    void fillStrings2(std::string *s1, std::string *s2);
    // 3.4
    std::string *fillStrings3();
    // 3.5
    std::array<std::string, 2> fillStrings4();
    // 3.6
    std::vector<std::string> *fillStrings5();
    // 3.7
    std::tuple<std::string, std::string> *fillStrings6();
    // 3.8
    std::pair<std::string, std::string> *fillStrings7();
    // 3.9
    string2d *fillStrings8();

}

#endif