#include "jwsWorld.h"

jwsWorld::jwsWorld(sf::RenderWindow &window):
m_window(window),
m_worldView(window.getDefaultView()),
m_textures()
{
    LoadTextures();
    BuildScene();
}

jwsWorld::~jwsWorld()
{
    //dtor
}

void jwsWorld::Draw()
{
    m_window.setView(m_worldView);
}

void jwsWorld::LoadTextures()
{
    m_textures.Load(Textures::Desert, "Desert.png");
    m_textures.Load(Textures::Airplane, "Eagle.png");

    //sf::Sprite landscape(m_textures.Get(Textures::Landscape));
	//sf::Sprite airplane(m_textures.Get(Textures::Airplane));
	//airplane.setPosition(200.f, 200.f);
}

void jwsWorld::BuildScene()
{
    // Prepare the tiled background
	sf::Texture& texture = m_textures.Get(Textures::Desert);
}


