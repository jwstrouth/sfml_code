#include <sstream>

using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <JWS_Game.h>

#if 0
template <typename T>
std::string toString(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}
#endif

class Game
{
    public:

    Game();
    ~Game();
    void run();

    private:

    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePayerInput(sf::Keyboard::Key key, bool isPressed);
    void updateStatistics(sf::Time elapsedTime);

    sf::RenderWindow    mWindow;
    sf::Sprite          mPlayerE;
    sf::Sprite          mPlayerRap;
    sf::Sprite          mBackground;
    sf::Texture         mETexture;
    sf::Texture         mRapTexture;
    sf::Texture         mDTexture;
    sf::Font            mFont;
    sf::Time            mStatisticsUpdateTime;
    sf::Text            mStatisticsText;
    sf::Music           mMusic;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
    std::size_t         mStatisticsNumFrames;
    float               mEAng;

    static const sf::Time   TimePerFrame;
    static const float      PlayerSpeed;
};

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
const float Game::PlayerSpeed = 100;

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML Application")
, mPlayerE()
{
    //mPlayer.setRadius(40.f);
    //mPlayer.setPosition(100.f, 100.f);
    //mPlayer.setFillColor(sf::Color::Cyan);
    if(mETexture.loadFromFile("Eagle.png"))
    {
        mPlayerE.setTexture(mETexture);
        mPlayerE.setPosition(100.f, 100.f);
    }

    if(mRapTexture.loadFromFile("Raptor.png"))
    {
        mPlayerRap.setTexture(mRapTexture);
        mPlayerRap.setPosition(150.f, 125.f);
    }

    if(mDTexture.loadFromFile("Desert.png"))
    {
        mBackground.setTexture(mDTexture);
        mBackground.setPosition(0.f, 0.f);
    }

    mIsMovingDown = false;
    mIsMovingUp = false;
    mIsMovingLeft = false;
    mIsMovingRight = false;

    mEAng = 0;

    mFont.loadFromFile("Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);

	if(mMusic.openFromFile("getdown9520120.wav"))
	{
        mMusic.play();
	}
}

Game::~Game()
{
    mMusic.stop();
}

void Game::run()
{
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Clock clock;
    while(mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while(timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        updateStatistics(elapsedTime);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::KeyPressed:
            handlePayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if(mIsMovingUp)
        movement.y -= PlayerSpeed;
    if(mIsMovingDown)
        movement.y += PlayerSpeed;
    if(mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if(mIsMovingRight)
        movement.x += PlayerSpeed;

    mPlayerE.move(movement * deltaTime.asSeconds());
    mPlayerRap.move(movement * deltaTime.asSeconds());
    //mPlayerE.rotate(mEAng++);
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mBackground);
    mWindow.draw(mPlayerRap);
    mWindow.draw(mPlayerE);
    mWindow.draw(mStatisticsText);
    mWindow.display();
}

void Game::handlePayerInput(sf::Keyboard::Key key, bool isPressed)
{
    switch(key)
    {
    case sf::Keyboard::W: mIsMovingUp = isPressed; break;
    case sf::Keyboard::S: mIsMovingDown = isPressed; break;
    case sf::Keyboard::A: mIsMovingLeft = isPressed; break;
    case sf::Keyboard::D: mIsMovingRight = isPressed; break;
    }
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

int main()
{
    //Game game;
    //game.run();

    JWS_Game g;

    return g.Run();
    //return 0;
}
