#include "Entity.h"
#include <iostream>

entity::UniquePtr_Entity::UniquePtr_Entity(Entity* ptrEntity):
m_ptrEntity(ptrEntity)
{
    std::cout<<"Entity Object created on heap is assigned to a smart pointer\n";
}

entity::UniquePtr_Entity::~UniquePtr_Entity()
{
    delete m_ptrEntity;
    std::cout<<"Entity object is deleted as the smart pointer is dead\n";
}