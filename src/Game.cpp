#include "Game.h"

//#include <iostream>
//using std::cout;
//using std::endl;

//STATIC VAR INIT
Game* Game::pGame = NULL;

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
    return true;
}

void Game::getInput()
{

}

void Game::update()
{

}

void Game::render()
{

}

void Game::clean()
{

}
