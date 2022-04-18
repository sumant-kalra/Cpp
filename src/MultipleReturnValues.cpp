#include <iostream>
#include <string>

#include "MultipleReturnValues.h"

// -------------------------------------------------------------------------------- //
entity::Entity &returnTypes::testMethod1()
{
    entity::Entity *object = new entity::Entity();
    return *object;
    // Note that here we have returned a reference to a heap object, in other words,
    // after the function returns in it's calling function, a reference with a name
    // will be created and assigned with this heap object. But it will result in a
    // memory leak as now the memory can not be cleared using delete. So, better
    // return the address of the memory so that it can be deleted.
    // .....Like Below.....
}

// -------------------------------------------------------------------------------- //
entity::Entity *returnTypes::testMethod2()
{
    entity::Entity *object = new entity::Entity();
    return object;
}

// -------------------------------------------------------------------------------- //
void returnTypes::assign10_1(int **p)
{
    *p = new int(10);
}

// -------------------------------------------------------------------------------- //
void returnTypes::assign10_2(int *&p)
{
    p = new int(10);
}

// -------------------------------------------------------------------------------- //
void returnTypes::fillStrings1(std::string &s1, std::string &s2)
{
    s1.assign(std::string("Reference_First"));
    s2.assign(std::string("Reference_Second"));
}

// -------------------------------------------------------------------------------- //
void returnTypes::fillStrings2(std::string *s1, std::string *s2)
{
    if (s1)
        s1->assign(std::string("Pointer_First"));
    if (s2)
        s2->assign(std::string("Pointer_Second"));
}

// -------------------------------------------------------------------------------- //
std::string *returnTypes::fillStrings3()
{
#if 0
    return new std::string[2]{"This is First", "This is Second"};
#endif

    std::string *arrayStrings = new std::string[2];
    arrayStrings[0].assign(std::string("DynamicArray_First"));
    arrayStrings[1].assign(std::string("DynamicArray_Second"));
    return arrayStrings;
}

// -------------------------------------------------------------------------------- //
std::array<std::string, 2> returnTypes::fillStrings4()
{
    return std::array<std::string, 2>{"Array_First", "Array_Second"};
}

// -------------------------------------------------------------------------------- //
std::vector<std::string> *returnTypes::fillStrings5()
{
#if 0 
// The stack allocted object should not be returned as reference
    std::vector<std::string> vecStrings{"FT", "ST"};
    return vecStrings;
#endif
    // The below approach  is not recommended though
    std::vector<std::string> *vecStrings = new std::vector<std::string>();
    vecStrings->emplace_back("Vector_First");
    vecStrings->emplace_back("Vector_Second");
    return vecStrings;
}

// -------------------------------------------------------------------------------- //
std::tuple<std::string, std::string> *returnTypes::fillStrings6()
{
    std::tuple<std::string, std::string> *stringsTuple = new std::tuple<std::string, std::string>();
    *stringsTuple = std::make_tuple<std::string, std::string>(std::string("Tuple_First"), std::string("Tuple_Second"));
    return stringsTuple;
}

// -------------------------------------------------------------------------------- //
std::pair<std::string, std::string> *returnTypes::fillStrings7()
{
    std::pair<std::string, std::string> *stringsPair = new std::pair<std::string, std::string>();
    *stringsPair = std::make_pair<std::string, std::string>(std::string("Pair_First"), std::string("Pair_Second"));
    return stringsPair;
}

// -------------------------------------------------------------------------------- //
returnTypes::string2d *returnTypes::fillStrings8()
{
    returnTypes::string2d *str = new returnTypes::string2d();
    str->str1 = "Finally, Struct_First";
    str->str2 = "Finally, Struct_Second";
    return str;
}

// -- MAIN ------------------------------------------------------------------------ //

#define MAIN_1 0

#if MAIN_1
int main(int argc, char *argv[])
{

    int *ptr1 = nullptr;
    returnTypes::assign10_1(&ptr1);
    std::cout << *ptr1 << "\n";
    delete ptr1;

    int *ptr2 = nullptr;
    returnTypes::assign10_2(ptr2);
    std::cout << *ptr2 << "\n";
    delete ptr2;

    std::string str1, str2;
    returnTypes::fillStrings1(str1, str2);
    std::cout << str1 << "\n";
    std::cout << str2 << "\n";

    std::string str3, str4, str5;
    returnTypes::fillStrings2(&str3, &str4);
    std::cout << str3 << "\n";
    std::cout << str4 << "\n";
    returnTypes::fillStrings2(&str5, nullptr);
    std::cout << str5 << "\n";

    std::string *myStringArray = returnTypes::fillStrings3();
    std::cout << myStringArray[0] << "\n";
    std::cout << myStringArray[1] << "\n";

    std::array<std::string, 2> myStdArray = returnTypes::fillStrings4();
    std::cout << myStdArray[0] << "\n";
    std::cout << myStdArray[1] << "\n";

    std::vector<std::string> *myVec = returnTypes::fillStrings5();
    std::cout << *(myVec->begin()) << "\n";
    std::cout << *(myVec->begin() + 1) << "\n";
    delete myVec;

    std::tuple<std::string, std::string> *myTuple = returnTypes::fillStrings6();
    std::cout << std::get<0>(*myTuple) << "\n";
    std::cout << std::get<1>(*myTuple) << "\n";
    delete myTuple;

    std::pair<std::string, std::string> *myPair = returnTypes::fillStrings7();
    std::cout << myPair->first << "\n";
    std::cout << myPair->second << "\n";
    delete myPair;

    returnTypes::string2d *myStr = returnTypes::fillStrings8();
    std::cout << myStr->str1 << "\n";
    std::cout << myStr->str2 << "\n";
    delete myStr;

    return 0;
}
#endif