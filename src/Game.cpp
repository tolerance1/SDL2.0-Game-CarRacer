#include "Game.h"

#include "TextureManager.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "GameObjectFactory.h"
#include "ButtonCreator.h"
#include "EnemyCreator.h"
#include "PlayerCreator.h"
#include "StaticGraphicCreator.h"

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
    cout << " 1 C Game" << endl;
}

Game::~Game()
{
    cout << " 1 D Game" << endl;

    //release SDL-specific objects
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);

    //release game state machine object
    delete pGameStateMachine;
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



    //create InputHandler object
    InputHandler::getpInputHandler();

    //create game object factory and register game object types
    GameObjectFactory::getpGameObjectFactory()->registerType("Button", new ButtonCreator());
    GameObjectFactory::getpGameObjectFactory()->registerType("Enemy", new EnemyCreator());
    GameObjectFactory::getpGameObjectFactory()->registerType("Player", new PlayerCreator());
    GameObjectFactory::getpGameObjectFactory()->registerType("StaticGraphic", new StaticGraphicCreator());

    //create finite state machine
    pGameStateMachine = new GameStateMachine();
    pGameStateMachine->pushState(new MenuState());



    cout << "Starting the game loop!" << endl;
    return true;//start the game loop

}

void Game::getInput()
{
    //poll events
    InputHandler::getpInputHandler()->updateInputStates();

}

void Game::update()
{
    //update the current game state
    pGameStateMachine->updateCurrentState();

}

void Game::render()
{
    //set the colour used for drawing operations
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 255, 255);
    //clear the current rendering target with the drawing colour
    SDL_RenderClear(pRenderer);


    //render the current game state
    pGameStateMachine->renderCurrentState();


    //update the screen with rendering performed
    SDL_RenderPresent(pRenderer);

}

void Game::clean()
{
    //ALWAYS REMEMBER TO CLEAN AND DELETE POINTERS BEFORE EXIT!!!

    delete GameObjectFactory::getpGameObjectFactory();//release the GameObjectFactory object memory
    delete InputHandler::getpInputHandler();//release the InputHandler object memory
    delete TextureManager::getpTextureManager();//release the TextureManager object memory
    delete pGame;//release the Game object memory
    SDL_Delay(60000);
    SDL_Quit();
}
