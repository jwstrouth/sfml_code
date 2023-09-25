#ifndef JWSGAME_H
#define JWSGAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

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
        void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    private:
        sf::Texture         m_texture;
        sf::Sprite          m_player;
        sf::RenderWindow    m_window;
        //sf::CircleShape     m_player;
        bool                 m_movingUp;
        bool                 m_movingDown;
        bool                 m_movingLeft;
        bool                 m_movingRight;
        sf::Time             m_timePerFrame;
};

#endif // JWSGAME_H
