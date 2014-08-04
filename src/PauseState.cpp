#include "PauseState.h"

#include "TextureManager.h"
#include "Game.h"
#include "Button.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
const std::string PauseState::pauseID = "PAUSE";

PauseState::PauseState()
{
    cout << " 16 C PauseState" << endl;
}

PauseState::~PauseState()
{
    cout << " 16 D PauseState" << endl;

    //release game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        delete gameObjects[Index];
    }
}

void PauseState::update()
{
    //update game objects destination coordinates and current frame
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->updateObjectParams();
    }
}

void PauseState::render()
{
    //draw game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->drawObject();
    }
}

bool PauseState::onEnter()
{
    //create textures
    if(! TextureManager::getpTextureManager()->createTexture("images/pause_button_resume.png",
                                                             "pause_button_resume",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;//don't start the loop
    }
    if(! TextureManager::getpTextureManager()->createTexture("images/pause_button_menu.png",
                                                             "pause_button_menu",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;
    }


    //create objects and push them into container
    gameObjects.push_back(new Button(new SetObjectParams("pause_button_resume", 240, 158, 160, 45, 0, 0), &PauseState::resumePlay));
    gameObjects.push_back(new Button(new SetObjectParams("pause_button_menu", 240, 231, 160, 45, 0, 0), &PauseState::switchToMenu));

    cout << "entering PauseState" << endl;
    return true;
}

bool PauseState::onExit()
{
    TextureManager::getpTextureManager()->destroyTexture("pause_button_resume");
    TextureManager::getpTextureManager()->destroyTexture("pause_button_menu");

    cout << "exiting PauseState" << endl;
    return true;
}

void PauseState::resumePlay()
{
    cout << "Resume button clicked" << endl;
    Game::getpGame()->getpGameStateMachine()->popState();
}

void PauseState::switchToMenu()
{
    cout << "Menu button clicked" << endl;
    Game::getpGame()->getpGameStateMachine()->changeState(new MenuState());
}
