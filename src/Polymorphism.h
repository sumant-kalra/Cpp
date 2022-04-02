#ifndef POLYMORPHISM_H
#define POLYMORPHISM_H

namespace polymorphic
{
    class Entity
    {
    protected:
        float m_posX;
        float m_posY;

    public:
        Entity();

        float getXPos() const;
        float getYPos() const;
        void printEntity() const;

        void setXPos(float x);
        void setYPos(float y);

        virtual void getName() const = 0;

        virtual ~Entity();
    };

    class Enemy : public Entity
    {
    private:
        const char *m_name = "Enemy";

    public:
        Enemy();

        ~Enemy();

        void getName() const override;
    };

    class Player : public Entity
    {
    private:
        const char *m_name = "Player";

    public:
        Player();

        ~Player();

        void getName() const override;
    };

    void printEntityType(Entity *entityObj);
}

#endif
