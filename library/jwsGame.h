#ifndef JWSGAME_H
#define JWSGAME_H

#include <SFML/Graphics.hpp>

#include <iostream>
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
        void Update();
        void Render();

    private:
        sf::RenderWindow                                m_window;
        //sf::Texture         m_texture;
        sf::Sprite                                      m_player;

        //sf::Sprite                                      *m_landscape;
        //sf::Sprite                                      *m_airplane;
};

#endif // JWSGAME_H
