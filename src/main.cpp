#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

//REMOVE THIS WHEN RELEASING THE GAME
#include "Windows.h"
#include <stdio.h>
//END REMOVE

const size_t FPS = 60;
const size_t DELAY_TIME = 1000 / FPS;

int main(int argc, char* argv[])
{
    //REMOVE THIS WHEN RELEASING THE GAME
    AllocConsole();
    freopen("CON", "w", stdout);
    //END REMOVE

    size_t frameStartTime = 0, frameElapsedTime = 0;

    //create the game object
    if (Game::getpGame()->init() )
    {
        Game::getpGame()->setbRunning() = true;

        while (Game::getpGame()->getbRunning() )
            {
                frameStartTime = SDL_GetTicks();

                Game::getpGame()->getInput();
                Game::getpGame()->update();
                Game::getpGame()->render();

                frameElapsedTime = SDL_GetTicks() - frameStartTime;

                if (frameElapsedTime < DELAY_TIME)
                {
                    SDL_Delay(DELAY_TIME - frameElapsedTime);
                }
                else
                {
                    cout << "Loop iteration, " << frameElapsedTime << " ms, exceeded frame time, " << DELAY_TIME << " ms!" << endl;
                }
            }
    }
    else
    {
        cout << "Game start error: " << SDL_GetError() << endl;
    }

    Game::getpGame()->clean();


    return 0;
}
