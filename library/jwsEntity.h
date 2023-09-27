#ifndef JWSENTITY_H
#define JWSENTITY_H

#include <jwsSceneNode.h>

class jwsEntity: public jwsSceneNode
{
    public:
        jwsEntity();
        virtual ~jwsEntity();

        void            SetVelocity(sf::Vector2f velocity);
		void	        SetVelocity(float vx, float vy);
		sf::Vector2f	GetVelocity() const;

    protected:

    private:
        virtual void    UpdateCurrent(sf::Time dt);

    private:
        sf::Vector2f		m_velocity;
};

#endif // JWSENTITY_H
