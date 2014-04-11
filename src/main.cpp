#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

//REMOVE THIS WHEN RELEASING THE GAME
#include "Windows.h"
#include <stdio.h>
//END REMOVE

int main(int argc, char* argv[])
{
    //REMOVE THIS WHEN RELEASING THE GAME
    AllocConsole();
    freopen("CON", "w", stdout);
    //END REMOVE


    //create the game object
    if (Game::getpGame()->init() )
    {
        Game::getpGame()->setbRunning() = true;

        while (Game::getpGame()->getbRunning() )
            {
                Game::getpGame()->getInput();
                Game::getpGame()->update();
                Game::getpGame()->render();

                SDL_Delay(10);
            }
    }
    else
    {
        cout << "Game start error: " << SDL_GetError() << endl;
    }

    Game::getpGame()->clean();


    return 0;
}
