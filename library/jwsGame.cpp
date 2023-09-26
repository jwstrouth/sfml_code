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
        }
    }
}

void jwsGame::Update()
{

}

void jwsGame::Render()
{
    m_window.clear();

    //m_window.draw(*m_landscape);
    //m_window.draw(*m_airplane);

    m_window.display();
}

void jwsGame::Run()
{
	//m_landscape = &landscape;
	//m_airplane = &airplane;

    while(m_window.isOpen())
    {
        ProcessEvents();
        Update();
        Render();
    }
}
