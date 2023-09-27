#include "jwsAircraft.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Textures::ID toTextureID(jwsAircraft::Type type)
{
	switch (type)
	{
		case jwsAircraft::Eagle:
			return Textures::Eagle;

		case jwsAircraft::Raptor:
			return Textures::Raptor;
	}

	return Textures::Eagle;
}

jwsAircraft::jwsAircraft(Type type, const TextureHolder& textures):
m_type(type),
m_sprite(textures.Get(toTextureID(type)))
{
	sf::FloatRect bounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

jwsAircraft::~jwsAircraft()
{
    //dtor
}

void jwsAircraft::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}
