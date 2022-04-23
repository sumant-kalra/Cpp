#include "Entity.h"
#include <iostream>

entity::Entity::Entity()
{
    num1 = 0;
    num2 = 0;
}

entity::Entity::Entity(float x, float y)
{
    num1 = x;
    num2 = y;
}

entity::Entity entity::Entity::operator+(const entity::Entity &entity2)
{
    entity::Entity entityObj;
    entityObj.num1 = this->num1 + entity2.num1;
    entityObj.num2 = this->num2 + entity2.num2;
    return entityObj;
}
entity::Entity entity::Entity::operator*(const entity::Entity &entity2)
{
    entity::Entity entityObj;
    entityObj.num1 = this->num1 * entity2.num1;
    entityObj.num2 = this->num2 * entity2.num2;
    return entityObj;
}
// Definitions of the non member operators
namespace entity
{
    std::ostream &operator<<(std::ostream &out, const entity::Entity &entityObj)
    {
        out << entityObj.num1 << " " << entityObj.num2;
        return out;
    }

    Entity operator-(const Entity &entity1, const Entity &entity2)
    {
        Entity entityObj;
        entityObj.num1 = entity1.num1 - entity2.num1;
        entityObj.num2 = entity1.num2 - entity2.num2;
        return entityObj;
    }
}

entity::UniquePtr_Entity::UniquePtr_Entity(Entity *ptrEntity) : m_ptrEntity(ptrEntity)
{
    std::cout << "Entity Object created on heap is assigned to a smart pointer\n";
}

entity::UniquePtr_Entity::~UniquePtr_Entity()
{
    delete m_ptrEntity;
    std::cout << "Entity object is deleted as the smart pointer is dead\n";
}

#define ENTITY_MAIN 0
#if ENTITY_MAIN
int main(int argc, char *argv[])
{
    entity::Entity entity1(2.0, 3.0);
    entity::Entity entity2(4.0, 5.0);
    std::cout << entity1 << "\n"
              << entity2 << "\n";
    std::cout << entity1 * entity2 << "\n";
    std::cout << entity1 + entity2 << "\n";
    std::cout << entity2 - entity1 << "\n";
    std::cout << entity::operator-(entity2, entity1) << "\n";
    entity::operator<<(std::cout, entity1);
    std::cout << "\n";

    return 0;
}
#endif
