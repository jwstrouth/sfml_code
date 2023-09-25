#ifndef JWSGAME_H
#define JWSGAME_H

#include <SFML/Graphics.hpp>

#include <jwsResourceHolder.h>

#include <iostream>
using namespace std;

// Resource ID for sf::Texture
namespace Textures
{
	enum ID
	{
		Landscape,
		Airplane,
	};
}

class jwsGame
{
    public:
        jwsGame();
        virtual ~jwsGame();

        void Run();

    protected:

    private:
        void ProcessEvents();
        void Update();
        void Render();

    private:
        sf::RenderWindow                                m_window;
        //sf::Texture         m_texture;
        sf::Sprite                                      m_player;
        jwsResourceHolder<sf::Texture, Textures::ID>    m_textures;
        sf::Sprite                                      *m_landscape;
        sf::Sprite                                      *m_airplane;
};

#endif // JWSGAME_H
