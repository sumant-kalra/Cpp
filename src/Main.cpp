#define TYPECASTING_MAIN 1
#if TYPECASTING_MAIN

#include <iostream>

#include "TypeCasting.h"

int main(int argc, char *argv[])
{
#if 0
    // [1] Without explicit keyword
    type_conversions::Thing thing1("MyName1");

#if 0
    // Does not work
    type_conversions::Thing thing2 = "MyName2";
#endif

    type_conversions::Thing thing2 = std::string("MyName2");

#if 0
    // Does not work
    type_conversions::print("MyName3");
#endif

    type_conversions::print(std::string("MyName3"));
    type_conversions::print(type_conversions::Thing("MyName4"));

    // [2] With explicit keyword
    type_conversions::Thing thing1(std::string("MyName1"));
    type_conversions::print(thing1);
    type_conversions::print(type_conversions::Thing("MyName4"));

    // [2] [3]
    type_conversions::Thing thing3("Kalra");
    type_conversions::Thing thing4(std::string("Sumant"));
    thing4 = thing3; // thing4.operator=(thing3);
    std::cout << thing3.getName() << "\n";
    std::cout << thing4.getName() << "\n";


    type_conversions::isLittleEndian();
    std::cout << type_conversions::convertEndianess1(strtof(argv[1], nullptr)) << "\n";
    std::cout << type_conversions::convertEndianess2(strtof(argv[1], nullptr)) << "\n";
    std::cout << type_conversions::convertEndianess3(strtof(argv[1], nullptr)) << "\n";



    type_conversions::Player *ptr1 = new type_conversions::Player(2.0f, 3.0f);

    auto ptr2 = static_cast<type_conversions::Entity *>(ptr1);

    auto ptr3 = dynamic_cast<type_conversions::Enemy *>(ptr2);
    if (!ptr3)
    {
        std::cout << "Dynamic cast failed!\n";
        delete ptr1;
        return -1;
    }

    ptr3->enemyId();

    delete ptr1;


    const type_conversions::Player *ptrPlayer = new type_conversions::Player(3.0f, 5.0f);

    auto ptrPlayer2 = const_cast<type_conversions::Player *>(ptrPlayer);

    ptrPlayer2->printName();

    delete ptrPlayer;
#endif

    type_conversions::Vec4f vec4{{{1.0f, 2.0f, 3.0f, 4.0f}}};
    std::cout << vec4.x << "\n";
    std::cout << vec4.y << "\n";
    std::cout << vec4.w << "\n";
    std::cout << vec4.v << "\n";

    type_conversions::printVec2f(vec4.vec2_1);
    type_conversions::printVec2f(vec4.vec2_2);

    return 0;
}

#endif