#include <iostream>

#include "TypeCasting.h"

// ----------------------------------------------------------------------------------------------------------------------- //
type_conversions::Thing::Thing(const std::string &name) : m_name(name)
{
}

// ----------------------------------------------------------------------------------------------------------------------- //
std::string type_conversions::Thing::getName() const
{
    return m_name;
}

// ----------------------------------------------------------------------------------------------------------------------- //
void type_conversions::print(const type_conversions::Thing &obj)
{
    std::cout << obj.getName() << "\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //
void type_conversions::Thing::operator=(const type_conversions::Thing &object)
{
    m_name = object.getName();
}

// ----------------------------------------------------------------------------------------------------------------------- //
bool type_conversions::isLittleEndian()
{
    int number = 1;
    char byteVar = *(char *)&number;
    if (byteVar == 1)
    {
        std::cout << "This is a Little Endian System\n";
        return true;
    }
    std::cout << "This is a Big Endian System\n";
    return false;
}

// ----------------------------------------------------------------------------------------------------------------------- //
float type_conversions::convertEndianess1(const float number)
{
    // Byte Ordering

    /// Array of bytes for the input number
    char *p1 = (char *)&number;

    /// The number with converted endianess
    float number2 = 0.0f;
    /// The array of bytes for the new number
    char *p2 = (char *)&number2;

    /// Number of bytes in both the numbers
    size_t sizeFloat = sizeof(float);

    /// Reverse the array of bytes p1 and save it p2
    for (size_t i = 0; i < sizeFloat; ++i)
    {
        p2[i] = p1[sizeFloat - i - 1];
    }
    return number2;
}

// ----------------------------------------------------------------------------------------------------------------------- //
float type_conversions::convertEndianess2(const float number)
{
    /// Number of bytes in both the numbers
    size_t sizeFloat = sizeof(float);

    /// float as an array of bytes
    union
    {
        float numberFloat;
        char numberChar[sizeof(float)];
    } original, number2;

    original.numberFloat = number;

    for (size_t i = 0; i < sizeFloat; i++)
    {
        number2.numberChar[i] = original.numberChar[sizeFloat - i - 1];
    }

    return number2.numberFloat;
}

// ----------------------------------------------------------------------------------------------------------------------- //
float type_conversions::convertEndianess3(const float number)
{
    /// Everything is same as convertEndianess1 except here reinterpret_cast is used instead of C style casting syntax

    float original = number;
    float number2 = 0.0f;

    size_t floatSize = sizeof(float);

    char *p1 = reinterpret_cast<char *>(&original);
    char *p2 = reinterpret_cast<char *>(&number2);

    for (size_t i = 0; i < floatSize; ++i)
    {
        p2[i] = p1[floatSize - i - 1];
    }

    return number2;
}

// ----------------------------------------------------------------------------------------------------------------------- //
type_conversions::Entity::Entity(float x, float y, const std::string &name) : m_x(x), m_y(y), m_name(name)
{
    std::cout << "Constructor of Entity\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //
type_conversions::Entity::~Entity()
{
    std::cout << "Destructor of Entity\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //
float type_conversions::Entity::getX() const
{
    return m_x;
}

// ----------------------------------------------------------------------------------------------------------------------- //
float type_conversions::Entity::getY() const
{
    return m_y;
}

// ----------------------------------------------------------------------------------------------------------------------- //
void type_conversions::Entity::setX(float x)
{
    m_x = x;
}

// ----------------------------------------------------------------------------------------------------------------------- //
void type_conversions::Entity::setY(float y)
{
    m_y = y;
}

// ----------------------------------------------------------------------------------------------------------------------- //
type_conversions::Player::Player(float x, float y) : type_conversions::Entity(x, y, "Player")
{
    std::cout << "Constructor of Player\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //
type_conversions::Player::~Player()
{
    std::cout << "Destructor of Player\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //
void type_conversions::Player::printName() const
{
    std::cout << m_name << "\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //
int type_conversions::Player::playerId() const
{
    std::cout << "This Player belongs to Punjab Police: " << m_PlayerID << "\n";
    return m_PlayerID;
}

// ----------------------------------------------------------------------------------------------------------------------- //
type_conversions::Enemy::Enemy(float x, float y) : type_conversions::Entity(x, y, "Enemy")
{
    std::cout << "Constructor of Enemy\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //
type_conversions::Enemy::~Enemy()
{
    std::cout << "Destructor of Enemy\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //
void type_conversions::Enemy::printName() const
{
    std::cout << m_name << "\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //
int type_conversions::Enemy::enemyId() const
{
    std::cout << "This Enemy belongs to BJP: " << m_EnemyID << "\n";
    return m_EnemyID;
}