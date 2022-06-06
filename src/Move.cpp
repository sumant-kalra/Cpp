#define MOVE_MAIN 1
#if MOVE_MAIN

#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_name;

public:
    Entity(const std::string &name)
    {
        m_name = name;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}

#endif