#include "jwsEntity.h"

jwsEntity::jwsEntity()
{
    //ctor
}

jwsEntity::~jwsEntity()
{
    //dtor
}

void jwsEntity::SetVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

void jwsEntity::SetVelocity(float vx, float vy)
{
	m_velocity.x = vx;
	m_velocity.y = vy;
}

sf::Vector2f jwsEntity::GetVelocity() const
{
	return m_velocity;
}

void jwsEntity::UpdateCurrent(sf::Time dt)
{
	move(m_velocity * dt.asSeconds());
}
