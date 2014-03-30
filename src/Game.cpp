#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
Game* Game::pGame = NULL;

Game::Game()
{
    cout << "_Game constructor" << endl;
}

Game::~Game()
{
    cout << "_Game destructor" << endl;
}

Game* Game::getpGame()
{
    if(pGame == NULL)
    {
        pGame = new Game();
        return pGame;
    }

    return pGame;
}

bool Game::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL_init success!" << endl;

        pWindow =
        SDL_CreateWindow("CarRacing", SDL_WINDOWPOS_CENTERED, 100, 640, 480, 0);

        if(pWindow != NULL)
        {
            cout << "SDL_CreateWindow success!" << endl;

            pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

            if(pRenderer != NULL)
            {
                cout << "SDL_CreateRenderer success!" << endl;
            }
        }
    }
    else
    {
        cout << "SDL_Init fail!" << endl;
        return false;
    }

    cout << "Starting the game loop!" << endl;
    return true;//start the game loop

}

void Game::getInput()
{

}

void Game::update()
{

}

void Game::render()
{
    //set the colour used for drawing operations
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 255, 255);
    //clear the current rendering target with the drawing colour
    SDL_RenderClear(pRenderer);
    //update the screen with rendering performed
    SDL_RenderPresent(pRenderer);

}

void Game::clean()
{
    delete pGame;//release the Game object memory
    SDL_Quit();
}
