#include "GameOverState.h"

#include "TextureManager.h"
#include "Game.h"
#include "Button.h"
#include "StaticGraphic.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
const std::string GameOverState::gameOverID = "GAMEOVER";

GameOverState::GameOverState()
{
    cout << " 16 C GameOverState" << endl;
}

GameOverState::~GameOverState()
{
    cout << " 16 D GameOverState" << endl;

    //release game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        delete gameObjects[Index];
    }
}

void GameOverState::update()
{
    //update game objects destination coordinates and current frame
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->updateObjectParams();
    }
}

void GameOverState::render()
{
    //draw game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->drawObject();
    }
}

bool GameOverState::onEnter()
{
    //create textures
    if(! TextureManager::getpTextureManager()->createTexture("images/gameover_graphic.png",
                                                             "gameover_graphic",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;//don't start the loop
    }
    if(! TextureManager::getpTextureManager()->createTexture("images/gameover_button_restart.png",
                                                             "gameover_button_restart",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;
    }
    if(! TextureManager::getpTextureManager()->createTexture("images/gameover_button_menu.png",
                                                             "gameover_button_menu",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;
    }


    //create objects and push them into container
    gameObjects.push_back(new StaticGraphic(new SetObjectParams("gameover_graphic", 200, 88, 250, 35, 0, 0)));
    gameObjects.push_back(new Button(new SetObjectParams("gameover_button_restart", 240, 158, 160, 45, 0, 0), &GameOverState::restartPlay));
    gameObjects.push_back(new Button(new SetObjectParams("gameover_button_menu", 240, 231, 160, 45, 0, 0), &GameOverState::switchToMenu));

    cout << "entering GameOverState" << endl;
    return true;
}

bool GameOverState::onExit()
{
    TextureManager::getpTextureManager()->destroyTexture("gameover_graphic");
    TextureManager::getpTextureManager()->destroyTexture("gameover_button_restart");
    TextureManager::getpTextureManager()->destroyTexture("gameover_button_menu");

    cout << "exiting GameOverState" << endl;
    return true;
}

void GameOverState::restartPlay()
{
    cout << "Restart button clicked" << endl;
    Game::getpGame()->getpGameStateMachine()->changeState(new PlayState());
}

void GameOverState::switchToMenu()
{
    cout << "Menu button clicked" << endl;
    Game::getpGame()->getpGameStateMachine()->changeState(new MenuState());
}
