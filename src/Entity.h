#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
namespace entity
{
    struct Entity
    {
    private:
        float num1;
        float num2;

    public:
        Entity();
        Entity(float x, float y);

        Entity operator+(const Entity &entity2);
        Entity operator*(const Entity &entity2);

        // friend declarations in the class
        friend std::ostream &operator<<(std::ostream &out, const Entity &entityObj);
        friend Entity operator-(const Entity &entity1, const Entity &entity2);
    };

    // Declarations of the non-member operators in the header file, since this is the file that will be included
    std::ostream &operator<<(std::ostream &out, const entity::Entity &entityObj);
    Entity operator-(const Entity &entity1, const Entity &entity2);

    // Implementing a unique pointer for Entity class objects
    class UniquePtr_Entity
    {
    private:
        Entity *m_ptrEntity;

    public:
        explicit UniquePtr_Entity(Entity *);
        UniquePtr_Entity(const Entity *&) = delete;
        ~UniquePtr_Entity();
    };
}

#endif