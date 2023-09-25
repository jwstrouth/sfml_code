#include "jwsGame.h"

const float PLAYER_SPEED = 5.0;

jwsGame::jwsGame():
m_window(sf::VideoMode(1000,800), "JWS Intro"),
m_player()
{
    if (!m_texture.loadFromFile("ship.png"))
    {
        cout << "Failed to load ship.png\n";
    }
    else
    {
        m_player.setTexture(m_texture);
    }
    //m_player.setRadius(40.f);
    m_player.setPosition(100.f, 100.f);
    //m_player.setFillColor(sf::Color::Red);
    m_timePerFrame = sf::seconds(1.f/60.f);
}

jwsGame::~jwsGame()
{
    //dtor
}

void jwsGame::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    switch(key)
    {
        case sf::Keyboard::Up:
            m_movingUp = isPressed;
            //cout << "UP\n";
            break;
        case sf::Keyboard::Down:
            m_movingDown = isPressed;
            //cout << "DOWN\n";
            break;
        case sf::Keyboard::Left:
            m_movingLeft = isPressed;
            //cout << "LEFT\n";
            break;
        case sf::Keyboard::Right:
            m_movingRight = isPressed;
            //cout << "RIGHT\n";
            break;
    }
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
                //cout << "KeyPressed\n";
                break;
            case sf::Event::KeyReleased:
                HandlePlayerInput(event.key.code, false);
                //cout << "KeyReleased\n";
                break;
            case sf::Event::Closed:
                m_window.close();
                break;
        }
    }
}

void jwsGame::Update()
{
    sf::Vector2f movement(0.f, 0.f);
    if(m_movingUp == true)
    {
        movement.y -= PLAYER_SPEED;
    }

    if(m_movingDown == true)
    {
        movement.y += PLAYER_SPEED;
    }

    if(m_movingLeft == true)
    {
        movement.x -= PLAYER_SPEED;
    }

    if(m_movingRight == true)
    {
        movement.x += PLAYER_SPEED;
    }

    m_player.move(movement);
}

void jwsGame::Render()
{
    m_window.clear();
    m_window.draw(m_player);
    m_window.display();
}

void jwsGame::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(m_window.isOpen())
    {
        ProcessEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > m_timePerFrame)
        {
            timeSinceLastUpdate -= m_timePerFrame;
            ProcessEvents();
            Update();
        }
        Render();
    }
}
