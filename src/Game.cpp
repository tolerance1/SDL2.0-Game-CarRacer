#include "Game.h"

#include "TextureManager.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
Game* Game::pGame = nullptr;

Game* Game::getpGame()
{
    if(pGame == nullptr)
    {
        pGame = new Game();
        return pGame;
    }

    return pGame;
}

Game::Game()
{
    cout << "_Game constructor" << endl;
}

Game::~Game()
{
    cout << "_Game destructor" << endl;
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



    //create textures
    if(! TextureManager::getpTextureManager()->createTexture("images/Renault-Top_1.png",
                                                             "player_car_yellow",
                                                             pRenderer) )
    {
        return false;//don't start the loop
    }
    if(! TextureManager::getpTextureManager()->createTexture("images/Renault-Top_2.png",
                                                             "traffic_car_blue",
                                                             pRenderer) )
    {
        return false;
    }
    if(! TextureManager::getpTextureManager()->createTexture("images/Renault-Top_3.png",
                                                             "traffic_car_orange",
                                                             pRenderer) )
    {
        return false;
    }

    //set game objects parameters
    object1.setObjectParams("player_car_yellow", 560, 0, 45, 80, 0, 0, 270);
    object2.setObjectParams("traffic_car_blue", 0, 200, 45, 80, 0, 0, 90);
    object3.setObjectParams("traffic_car_orange", 0, 300, 45, 80, 0, 0, 90);



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
    //update game objects destination coordinates and current frame
    object1.updateObjectParams();
    object2.updateObjectParams();
    object3.updateObjectParams();

}

void Game::render()
{
    //set the colour used for drawing operations
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 255, 255);
    //clear the current rendering target with the drawing colour
    SDL_RenderClear(pRenderer);


    //draw game objects
    object1.drawObject(pRenderer);
    object2.drawObject(pRenderer);
    object3.drawObject(pRenderer);


    //update the screen with rendering performed
    SDL_RenderPresent(pRenderer);

}

void Game::clean()
{
    //ALWAYS REMEMBER TO CLEAN AND DELETE POINTERS BEFORE EXIT!!!

    TextureManager::getpTextureManager()->DestroyTextures();//release the textures the TextureManager u_map holds
    delete TextureManager::getpTextureManager();//release the TextureManager object memory

    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    delete pGame;//release the Game object memory
    SDL_Delay(5000);
    SDL_Quit();
}
