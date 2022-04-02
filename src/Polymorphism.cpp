#include <iostream>
#include "Polymorphism.h"

/// Entity class
polymorphic::Entity::Entity()
{
    m_posX = 0.0f;
    m_posY = 0.0f;
    std::cout << "### Entity Constructor ###\n";
}

polymorphic::Entity::~Entity()
{
    std::cout << "### Entity Destructor ###\n";
}

void polymorphic::Entity::printEntity() const
{
    std::cout << "X_Pos : " << m_posX << ". Y_Pos : " << m_posY << "\n";
}

float polymorphic::Entity::getXPos() const
{
    return m_posX;
}

float polymorphic::Entity::getYPos() const
{
    return m_posY;
}

void polymorphic::Entity::setXPos(float x)
{
    m_posX = x;
}

void polymorphic::Entity::setYPos(float y)
{
    m_posY = y;
}

/// Enemy class
polymorphic::Enemy::Enemy()
{
    std::cout << "### Enemy Constructor ###\n";
}

polymorphic::Enemy::~Enemy()
{
    std::cout << "### Enemy Destructor ###\n";
}

void polymorphic::Enemy::getName() const
{
    std::cout << m_name << "\n";
}

/// Player class
polymorphic::Player::Player()
{
    std::cout << "### Player Constructor ###\n";
}

polymorphic::Player::~Player()
{
    std::cout << "### Player Destructor ###\n";
}

void polymorphic::Player::getName() const
{
    std::cout << m_name << "\n";
}

void polymorphic::printEntityType(polymorphic::Entity *entityObj)
{
    entityObj->getName();
}
