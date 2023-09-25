
#include <SFML/Graphics.hpp>

#include "jwsGame.h"

#include <iostream>
using namespace std;

int main()
{
    try
    {
        jwsGame game;

        // check video card memory
        cout << "Video Card Maximum size is " << sf::Texture::getMaximumSize() << endl;
        // test move() using string
        string str = "Hello";
        cout << "str: (Address: " << &str << ") " << str << endl;
        string str1(move(str));
        cout << "str: Address: " << &str << str << " (str is empty and moved to str1) , str1: (Address: " << &str1 << ") " << str1 << endl;

        game.Run();
    }

    catch(...)
    {
        cout << "Exception\n";
    }

    return EXIT_SUCCESS;
}
