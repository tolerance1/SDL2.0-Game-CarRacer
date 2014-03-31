#include "Game.h"

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
    Game::getpGame()->setbRunning() = Game::getpGame()->init();

    while (Game::getpGame()->getbRunning() )
    {
        Game::getpGame()->getInput();
        Game::getpGame()->update();
        Game::getpGame()->render();

        SDL_Delay(10);

    }

    Game::getpGame()->clean();


    return 0;
}
