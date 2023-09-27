#ifndef JWSAIRCRAFT_H
#define JWSAIRCRAFT_H

#include <jwsEntity.h>
#include <jwsResourceHolder.h>
#include <jwsResourceIdentifier.h>

#include <SFML/Graphics/Sprite.hpp>

class jwsAircraft: public jwsEntity
{
    public:
        enum Type
		{
			Eagle,
			Raptor,
		};

        jwsAircraft(Type type, const TextureHolder& textures);
        virtual ~jwsAircraft();

        virtual void    DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    protected:

    private:
        Type                m_type;
		sf::Sprite			m_sprite;
};

#endif // JWSAIRCRAFT_H
