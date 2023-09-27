#include "jwsGame.h"

jwsGame::jwsGame():
m_window(sf::VideoMode(640, 480), "JWS Resources")
{

}

jwsGame::~jwsGame()
{
    //dtor
}

void jwsGame::ProcessEvents()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;
        }
    }
}

void jwsGame::Update()
{

}

void jwsGame::Render()
{
    m_window.clear();

    m_window.draw(*m_landscape);
    m_window.draw(*m_airplane);

    m_window.display();
}

void jwsGame::Run()
{
    try
	{
		m_textures.Load(Textures::Landscape, "Desert.png");
        m_textures.Load(Textures::Airplane, "Eagle.png");
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return;
	}

	sf::Sprite landscape(m_textures.Get(Textures::Landscape));
	sf::Sprite airplane(m_textures.Get(Textures::Airplane));
	airplane.setPosition(200.f, 200.f);

	m_landscape = &landscape;
	m_airplane = &airplane;

    while(m_window.isOpen())
    {
        ProcessEvents();
        Update();
        Render();
    }
}
