#include "MenuState.h"

#include "Game.h"
#include "StateParser.h"
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
    //parse the state (creates textures and objects)
    StateParser parser;
    parser.parseState("xml/game_states.xml", menuID, &textureIDs, &gameObjects);

    //populate array with function pointers
    callbackFuncs.push_back(nullptr);//skip index 0
    callbackFuncs.push_back(&MenuState::switchToPlay);
    callbackFuncs.push_back(&MenuState::exitFromGame);

    cout << "entering MenuState" << endl;
    return true;
}

bool MenuState::onExit()
{
    cout << "exiting MenuState" << endl;

    return GameStateABC::onExit();
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
