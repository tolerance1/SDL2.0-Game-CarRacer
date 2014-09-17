#include "PauseState.h"

#include "Game.h"
#include "StateParser.h"
#include "MenuState.h"

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
    //parse the state (creates textures and objects)
    StateParser parser;
    parser.parseState("xml/game_states.xml", pauseID, &textureIDs, &gameObjects);

    //populate array with function pointers
    callbackFuncs.push_back(nullptr);//skip index 0
    callbackFuncs.push_back(&PauseState::resumePlay);
    callbackFuncs.push_back(&PauseState::switchToMenu);

    cout << "entering PauseState" << endl;
    return true;
}

bool PauseState::onExit()
{
    cout << "exiting PauseState" << endl;

    return GameStateABC::onExit();
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
