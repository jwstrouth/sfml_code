#include "jwsGame.h"

const sf::Time jwsGame::TimePerFrame = sf::seconds(1.f/60.f);

jwsGame::jwsGame():
m_window(sf::VideoMode(640, 480), "JWS Resources"),
m_world(m_window)
{
    std::cout << "Window: x: " << m_window.getDefaultView().getSize().x << ", y: " << m_window.getDefaultView().getSize().y << std::endl;
}

jwsGame::~jwsGame()
{
    //dtor
}

void jwsGame::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{

}

void jwsGame::ProcessEvents()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:
				HandlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				HandlePlayerInput(event.key.code, false);
				break;

            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;
        }
    }
}

void jwsGame::Update(sf::Time elapsedTime)
{
    m_world.Update(elapsedTime);
}

void jwsGame::Render()
{
    m_window.clear();
    m_world.Draw();

    m_window.setView(m_window.getDefaultView());

    m_window.display();
}

void jwsGame::Run()
{
    sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(m_window.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
		{
            timeSinceLastUpdate -= TimePerFrame;

            ProcessEvents();
            Update(TimePerFrame);
		}

        Render();
    }
}
