#define MAIN 1
#if MAIN

#include <iostream>
class Entity;

static void printEntity(Entity *p) { std::cout << "Pointer\n"; }
static void printEntity(Entity &entity) { std::cout << "Reference\n"; };

class Entity
{
private:
    float m_x;
    float m_y;

public:
    Entity(float x, float y)
    {
        this->m_x = x;
        this->m_y = y;

        Entity *ptr = this;
        std::cout << ptr << "\n";

        Entity *const &ref1 = this;
        std::cout << ref1 << "\n";

        printEntity(this);
        printEntity(*this);
    }
    void print() const
    {
        std::cout << m_x << "\n";
        std::cout << m_y << "\n";

        Entity const *ptr = this;
        std::cout << ptr << "\n";

        Entity const *const &ref1 = this;
        std::cout << ref1 << "\n";
    }
};

int main(int argc, char *argv[])
{
    Entity obj(2.0f, 3.0f);
    obj.print();

    return 0;
}

#endif