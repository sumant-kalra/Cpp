#define VECTOR_OPTIMIZATION 0
#if VECTOR_OPTIMIZATION

#include <iostream>
#include <string>
#include <vector>

namespace
{
    class Init
    {
        int m_num;

    public:
        Init()
        {
            std::cout << "Default constructor of Init class\n";
        }
        Init(int num) : m_num(num)
        {
            std::cout << "Parameterized Constructor of Init class\n";
        }
        // Destructor is defined only to avoid a compiler error about unused variable m_num
        ~Init()
        {
            std::cout << m_num << "\n";
        }
    };

    class Entity
    {
    private:
        std::string m_name;
        Init m_initObj;

    public:
        Entity() : m_initObj(Init(5))
        {
// An Extra Object of Init class is created
#if 0
            m_initObj = Init(5);
#endif
            m_name = "SK";
        }

        explicit Entity(const std::string &name)
        {
            m_name = name; // Same as if it were member initialized because, no new object is created for initialization.
            // However, the member initialization is always preferred.
            std::cout << "Parameterized constructor\n";
        }
        Entity(const Entity &obj)
        {
            m_name = obj.m_name;
            std::cout << "Copy Constructor\n";
        }
    };

}

int main()
{
    // Vector Optimizations
#if 0
    std::vector<Entity> vecObjs;
    vecObjs.reserve(3);

    /// Read the documentation of the emplace_back();
    ///s Parameters to the emplace_back() are the arguments of the contructor
    vecObjs.emplace_back("1");
    vecObjs.emplace_back("2");
    vecObjs.emplace_back("3");
#endif

    // Member Initialization list

    Entity obj;

    return 0;
}
#endif