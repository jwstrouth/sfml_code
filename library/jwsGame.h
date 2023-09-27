#ifndef JWSGAME_H
#define JWSGAME_H

#include <SFML/Graphics.hpp>

#include <iostream>

#include <jwsWorld.h>

using namespace std;

class jwsGame: private sf::NonCopyable
{
    public:
        jwsGame();
        virtual ~jwsGame();

        void Run();

    protected:

    private:
        void ProcessEvents();
        void Update(sf::Time elapsedTime);
        void Render();
        void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    private:
        static const sf::Time	TimePerFrame;
        sf::RenderWindow        m_window;
        sf::Sprite              m_player;
        jwsWorld                m_world;

};

#endif // JWSGAME_H
