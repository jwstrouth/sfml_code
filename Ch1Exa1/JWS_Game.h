#ifndef JWS_GAME_H
#define JWS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>

#if 1
template <typename T>
std::string toString(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}
#endif

class JWS_Game
{
    public:
        JWS_Game();
        virtual ~JWS_Game();

        int Init();
        int Run();
        int ProcessEvents();
        int Render();
        int UpdateStatistics(sf::Time elapsedTime);
        int Term();
        int Update(sf::Time deltaTime);
        int HandlePayerInput(sf::Keyboard::Key key, bool isPressed);

    protected:

    private:

        sf::RenderWindow        m_window;
        sf::Sprite              m_background;
        sf::Texture             m_dTexture;
        sf::Font                m_font;
        sf::Text                m_statisticsText;
        sf::Time                m_statisticsUpdateTime;
        std::size_t             m_statisticsNumFrames;
        sf::Music               m_music;
        sf::Sprite              m_playerE;
        sf::Texture             m_eTexture;
        bool                    m_IsMovingUp;
        bool                    m_IsMovingDown;
        bool                    m_IsMovingLeft;
        bool                    m_IsMovingRight;

        static const sf::Time   TIME_PER_FRAME;
        static const float      PLAYER_SPEED;
};

#endif // JWS_GAME_H
