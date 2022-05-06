#ifndef TYPE_CASTING_H
#define TYPE_CASTING_H

// [1]
// Implement a class with a parameterized constructor taking std::string as argument;
// A print method that takes an object of the class as parameter.
// Prove that only one implicit type casting is allowed for an object at a particular time, in C++;

// [2]
// Experiment with explicit keyword

// [3]
// Implicit type casting with assignment operator - Does not make any sense as there is no difference
// between the implicit and explict call made to the overloaded operator

// [4]
// Find the endianess of the system (return true for Little Endian and false for big endian)
// and the convert the data's endianess by using (a)Type punning (b)Union (c)reinterpret_cast

// [5]
// static_cast, dynamic_cast, reinterpret_cast, const_cast applied on a polymorphic class - EntityBase with two children Player and Enemy

// [6]
// Union : Represent the Vec4 as two Vec2 using union

#include <string>
namespace type_conversions
{
    // [1] [2] [3]
    class Thing
    {
    private:
        std::string m_name;

    public:
        explicit Thing(const std::string &name);
        void operator=(const Thing &object);

        std::string getName() const;
    };

    void print(const type_conversions::Thing &obj);

    // [4]
    bool isLittleEndian();
    float convertEndianess1(const float number);
    float convertEndianess2(const float number);
    float convertEndianess3(const float number);
}

#endif