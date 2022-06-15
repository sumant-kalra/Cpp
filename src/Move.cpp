#define MOVE_MAIN 1
#if MOVE_MAIN

// Problem: Implementation of a String class as per Rule of 5 and using its object as a member in Entity class.

#include <iostream>
#include <vector>

class String
{
private:
    char *m_string;
    int32_t m_size;

public:
    String(const char *string)
    {
        m_size = strlen(string) + 1;
        m_string = new char[m_size];
        strcpy(m_string, string);
        printf("String: Parameterized Constructor!\n");
    }

    String(const String &string)
    {
        m_size = string.m_size;
        m_string = new char[m_size];
        strcpy(m_string, string.m_string);
        printf("String: Copy Constructor!\n");
    }

    String &operator=(const String &string)
    {
        m_size = string.m_size;
        strcpy(m_string, string.m_string);
        printf("String: Copy Assignment\n");
        return *this;
    }

    // Move-Constructor-noexcept
    String(String &&other) noexcept
    {
        m_size = other.m_size;
        m_string = other.m_string;

        other.m_size = 0;
        other.m_string = nullptr;
        printf("String: Move Constructor!\n");
    }

    // Move-AssignmentOperator-noexcept
    String &operator=(String &&other) noexcept
    {
        if (this != &other)
        {
            delete[] m_string;

            m_string = other.m_string;
            m_size = other.m_size;

            other.m_string = nullptr;
            other.m_size = 0;

            printf("String: Move Assignment!\n");
        }

        return *this;
    }

    ~String()
    {
        if (m_string)
            delete[] m_string;
        else
            delete m_string;
        printf("String: Deleted!\n");
    }

    void printString()
    {
        printf("%s \n", m_string);
    }
};

class Entity
{
private:
    String m_name;

public:
    Entity(const String &name)
        : m_name(name) // m_name is copy constructed; Need to optimize this to avoid copy
    // because two objects are being created [1] Temporary String("Sumant") in main [2] m_name by copy constructor
    // out of which one is redudant. Ideal case would be to move the resources of name to m_name as name is a temporary object
    {
        printf("Entity: Paramerized Constructor!\n");
    }

    Entity(String &&name)
        : m_name(std::move(name))
    {
        printf("Entity: Parameterized Constructor with R-values as parameters!\n");
    }

    void printEntity()
    {
        m_name.printString();
    }

    ~Entity()
    {
        printf("Entity: Deleted!\n");
    }
};

int main(int argc, char const *argv[])
{
    /// String object is moved as we have defined move constructor for the String class
    std::vector<String> vecS;
    vecS.reserve(1);
    vecS.push_back(String("SKK"));

#if 0
/// Entity Object in the below code is copied because we have not defined any move constructor
    std::vector<Entity> vec;
    vec.reserve(1);
    vec.push_back(Entity("Sk"));
#endif

#if 0
    /// Move Assignment
    String str1("Kalra");
    String str2("feyn");
    str2 = std::move(str1);
#endif

#if 0
/// [2]
/// Similar to Return Type Optimization
    String str = String("Sum");
#endif

#if 0
/// [1]
/// Move Constructor
    Entity entityObj(String("Sumant"));
    entityObj.printEntity();
#endif

    return 0;
}

#endif