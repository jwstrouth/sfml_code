#include "JWS_Game.h"

// 60 frames per second ???
const sf::Time JWS_Game::TIME_PER_FRAME = sf::seconds(1.f/60.f);
const float JWS_Game::PLAYER_SPEED = 100;

JWS_Game::JWS_Game()
: m_window(sf::VideoMode(640, 480), "Chanpter1 Exa1")
{
    //ctor
}

JWS_Game::~JWS_Game()
{
    //dtor
}

int JWS_Game::Run()
{
    if(Init() != 0)
    {
        std::cout << "Failed to initialize" << std::endl;
        return -1;
    }

    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Clock clock;

    while(m_window.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while(timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            ProcessEvents();
            Update(TIME_PER_FRAME);
        }

        UpdateStatistics(elapsedTime);
        Render();
    }

    Term();

    return 0;
}

int JWS_Game::Init()
{
    // load background image
    if(m_dTexture.loadFromFile("Desert.png") == false)
    {
        std::cout << "Failed to load from file" << std::endl;
        return -1;
    }

    m_background.setTexture(m_dTexture);
    m_background.setPosition(0.f, 0.f);

    // load jet image
    //if(m_eTexture.loadFromFile("Eagle.png") == false)
    if(m_eTexture.loadFromFile("Raptor.png") == false)
    {
        std::cout << "Failed to load from file" << std::endl;
        return -1;
    }

    m_playerE.setTexture(m_eTexture);
    m_playerE.setPosition(100.f, 100.f);

    // load font for statistics
    m_font.loadFromFile("Sansation.ttf");
    m_statisticsText.setFont(m_font);
	m_statisticsText.setPosition(5.f, 5.f);
	m_statisticsText.setCharacterSize(10);

	// load music and play it
	if(m_music.openFromFile("getdown9520120.wav") == false)
	{
        std::cout << "Failed to load from file" << std::endl;
        return -1;
	}

	m_music.play();

	m_IsMovingDown = false;
    m_IsMovingUp = false;
    m_IsMovingLeft = false;
    m_IsMovingRight = false;

    return 0;
}

int JWS_Game::ProcessEvents()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::KeyPressed:
            HandlePayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            HandlePayerInput(event.key.code, false);
            break;
        }
    }

    return 0;
}

int JWS_Game::Render()
{
    m_window.clear();
    m_window.draw(m_background);
    m_window.draw(m_playerE);
    m_window.draw(m_statisticsText);
    m_window.display();

    return 0;
}

int JWS_Game::UpdateStatistics(sf::Time elapsedTime)
{
    m_statisticsUpdateTime += elapsedTime;
	m_statisticsNumFrames += 1;

	if (m_statisticsUpdateTime >= sf::seconds(1.0f))
	{
		m_statisticsText.setString(
			"Frames / Second = " + toString(m_statisticsNumFrames) + "\n" +
			"Time / Update = " + toString(m_statisticsUpdateTime.asMicroseconds() / m_statisticsNumFrames) + "us");
		m_statisticsUpdateTime -= sf::seconds(1.0f);
		m_statisticsNumFrames = 0;
	}

    return 0;
}

int JWS_Game::Term()
{
    m_music.stop();

    return 0;
}

int JWS_Game::Update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);

    if(m_IsMovingUp)
    {
        movement.y -= PLAYER_SPEED;
    }

    if(m_IsMovingDown)
    {
        movement.y += PLAYER_SPEED;
    }

    if(m_IsMovingLeft)
    {
        movement.x -= PLAYER_SPEED;
    }

    if(m_IsMovingRight)
    {
        movement.x += PLAYER_SPEED;
    }

    m_playerE.move(movement * deltaTime.asSeconds());

    return 0;
}

int JWS_Game::HandlePayerInput(sf::Keyboard::Key key, bool isPressed)
{
    switch(key)
    {
    case sf::Keyboard::W:
        m_IsMovingUp = isPressed;
        break;
    case sf::Keyboard::S:
        m_IsMovingDown = isPressed;
        break;
    case sf::Keyboard::A:
        m_IsMovingLeft = isPressed;
        break;
    case sf::Keyboard::D:
        m_IsMovingRight = isPressed;
        break;
    }

    return 0;
}
