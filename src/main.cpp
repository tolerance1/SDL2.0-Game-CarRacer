#include "SDL.h"
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
    Game::getpGame()->init();

    while (Game::getpGame()->getbRunning() )
    {
        Game::getpGame()->getInput();
        Game::getpGame()->update();
        Game::getpGame()->render();


        SDL_Init(SDL_INIT_EVERYTHING);

        SDL_Window* pWindow = SDL_CreateWindow("CarRacing", 100, 100, 640, 480, 0);
        SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 255, 255);
        // clear the window to the blue
        SDL_RenderClear(pRenderer);
        // show the window
        SDL_RenderPresent(pRenderer);
        SDL_Delay(10000);
        SDL_Quit();

    }

    Game::getpGame()->clean();


    return 0;
}
