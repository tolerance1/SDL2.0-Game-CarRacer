#include "Game.h"

#include "SDL_image.h"
SDL_Texture* pTexture;
SDL_Rect sourceRectangle;
SDL_Rect destRectangle;

SDL_Texture* pTexture2;
SDL_Rect sourceRectangle2;
SDL_Rect destRectangle2;

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
Game* Game::pGame = nullptr;

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
    if(pGame == nullptr)
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



    //create surface first
    SDL_Surface* pTempSurface = IMG_Load("images/Renault-Top_1.png");
    //create a texture next and store it!!!
    pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    //free temp surface
    SDL_FreeSurface(pTempSurface);

    //set dimensions
    sourceRectangle.w = destRectangle.w = 45;
    sourceRectangle.h = destRectangle.h = 80;

    //set coordinates
    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    destRectangle.x = 100;
    destRectangle.y = 100;

    //texture2
    //create surface first
    pTempSurface = IMG_Load("images/Renault-Top_3.png");
    //create a texture next and store it!!!
    pTexture2 = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    //free temp surface
    SDL_FreeSurface(pTempSurface);

    //set dimensions
    sourceRectangle2.w = destRectangle2.w = 45;
    sourceRectangle2.h = destRectangle2.h = 80;

    //set coordinates
    sourceRectangle2.x = 0;
    sourceRectangle2.y = 0;
    destRectangle2.x = 200;
    destRectangle2.y = 100;



    cout << "Starting the game loop!" << endl;
    return true;//start the game loop

}

void Game::getInput()
{
    SDL_Event event;//events are placed into this union of structs
    if(SDL_PollEvent(&event))//returns 1 if an event has been placed into the union
    {
        switch(event.type)//check the event type
        {
            case SDL_QUIT:
                bRunning = false;
                break;

            default:
                break;
        }
    }
}

void Game::update()
{
    sourceRectangle2.x = 45 * int(((SDL_GetTicks() / 100) % 2));
}

void Game::render()
{
    //set the colour used for drawing operations
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 255, 255);
    //clear the current rendering target with the drawing colour
    SDL_RenderClear(pRenderer);


    //copy the texture to the renderer
    SDL_RenderCopyEx(pRenderer, pTexture, &sourceRectangle, &destRectangle,
                     0, 0, SDL_FLIP_NONE);

    //copy the texture2 to the renderer
    SDL_RenderCopyEx(pRenderer, pTexture2, &sourceRectangle2, &destRectangle2,
                     0, 0, SDL_FLIP_NONE);


    //update the screen with rendering performed
    SDL_RenderPresent(pRenderer);

}

void Game::clean()
{
    //always remember to clean and delete pointers before exit!!!
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    delete pGame;//release the Game object memory
    SDL_Quit();
}
