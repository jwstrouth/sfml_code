#ifndef JWSWORLD_H
#define JWSWORLD_H

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <array>

#include <jwsResourceHolder.h>
#include <jwsSceneNode.h>
#include <jwsSpriteNode.h>
#include <jwsResourceIdentifier.h>
#include <jwsAircraft.h>

class jwsWorld: private sf::NonCopyable
{
    public:
        jwsWorld(sf::RenderWindow &window);
        virtual ~jwsWorld();

        void    Draw();
        void    Update(sf::Time dt);

    protected:

    private:
        void    LoadTextures();
        void	BuildScene();

    private:
        enum Layer
		{
			Background,
			Air,
			LayerCount
		};

    private:
        sf::RenderWindow&                       m_window;
        sf::View			                    m_worldView;
        TextureHolder                           m_textures;
        jwsSceneNode                            m_sceneGraph;
        std::array<jwsSceneNode*, LayerCount>	m_sceneLayers;
        sf::FloatRect						    m_worldBounds;
        float                                   m_scrollSpeed;
        sf::Vector2f                            m_spawnPosition;
        jwsAircraft                             *m_aircraft;
};

#endif // JWSWORLD_H
