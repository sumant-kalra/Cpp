#ifndef ENTITY_H
#define ENTITY_H

namespace entity
{ 
    struct Entity
    {
        float num1;
        float num2;
    };

    // Implementing a unique pointer for Entity class objects
    class UniquePtr_Entity
    {
    private:
        Entity* m_ptrEntity;
    public:
        explicit UniquePtr_Entity(Entity*);
        UniquePtr_Entity(const Entity* &) = delete;
        ~UniquePtr_Entity();
    };
}
#endif