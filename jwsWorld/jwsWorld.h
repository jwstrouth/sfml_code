#ifndef JWSWORLD_H
#define JWSWORLD_H

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics.hpp>

#include <jwsResourceHolder.h>

// Resource ID for sf::Texture
namespace Textures
{
	enum ID
	{
		Desert,
		Airplane,
	};
}

typedef jwsResourceHolder<sf::Texture, Textures::ID> TextureHolder;

class jwsWorld: private sf::NonCopyable
{
    public:
        jwsWorld(sf::RenderWindow &window);
        virtual ~jwsWorld();

        void Draw();

    protected:

    private:
        void    LoadTextures();
        void	BuildScene();

    private:
        sf::RenderWindow&   m_window;
        sf::View			m_worldView;
        TextureHolder       m_textures;
};

#endif // JWSWORLD_H
