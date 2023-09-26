#include <SFML/Graphics.hpp>

#include <jwsGame.h>

using namespace std;

int main()
{
    try
    {
        jwsGame game;
        game.Run();
    }

    catch(exception &e)
    {
        cout << "\nEXCEPTION: " << e.what() << endl;
    }

    return EXIT_SUCCESS;
}
