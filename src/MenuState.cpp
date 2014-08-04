#include "MenuState.h"

#include "TextureManager.h"
#include "Game.h"
#include "Button.h"
#include "StaticGraphic.h"
#include "PlayState.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
const std::string MenuState::menuID = "MENU";

MenuState::MenuState()
{
    cout << " 11 C MenuState" << endl;
}

MenuState::~MenuState()
{
    cout << " 11 D MenuState" << endl;

    //release game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        delete gameObjects[Index];
    }
}

void MenuState::update()
{
    //update game objects destination coordinates and current frame
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->updateObjectParams();
    }
}

void MenuState::render()
{
    //draw game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->drawObject();
    }
}

bool MenuState::onEnter()
{
    //create textures
    if(! TextureManager::getpTextureManager()->createTexture("images/menu_background.jpg",
                                                             "menu_background",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;//don't start the loop
    }
    if(! TextureManager::getpTextureManager()->createTexture("images/menu_button_play.png",
                                                             "menu_button_play",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;
    }
    if(! TextureManager::getpTextureManager()->createTexture("images/menu_button_exit.png",
                                                             "menu_button_exit",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;
    }

    //create objects and push them into container
    gameObjects.push_back(new StaticGraphic(new SetObjectParams("menu_background", 0, 0, 640, 480, 0, 0), &MenuState::switchToPlay));
    gameObjects.push_back(new Button(new SetObjectParams("menu_button_play", 449, 31, 160, 45, 0, 0), &MenuState::switchToPlay));
    gameObjects.push_back(new Button(new SetObjectParams("menu_button_exit", 449, 104, 160, 45, 0, 0), &MenuState::exitFromGame));

    cout << "entering MenuState" << endl;
    return true;
}

bool MenuState::onExit()
{
    TextureManager::getpTextureManager()->destroyTexture("menu_background");
    TextureManager::getpTextureManager()->destroyTexture("menu_button_play");
    TextureManager::getpTextureManager()->destroyTexture("menu_button_exit");

    cout << "exiting MenuState" << endl;
    return true;
}

void MenuState::switchToPlay()
{
    cout << "Play button clicked" << endl;
    Game::getpGame()->getpGameStateMachine()->changeState(new PlayState());
}

void MenuState::exitFromGame()
{
    cout << "Exit button clicked" << endl;
    Game::getpGame()->setbRunning() = false;
}
