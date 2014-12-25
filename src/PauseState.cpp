#include "PauseState.h"

#include "Game.h"
#include "LevelParser.h"

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
    //update state
    pLevel->update();
}

void PauseState::render()
{
    //draw state
    pLevel->render();
}

bool PauseState::onEnter()
{
    //parse level (creates map, textures and objects)
    LevelParser levelParser(&textureIDs);
    pLevel = levelParser.parseLevel("xml/pause_state.tmx");

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
    Game::getpGame()->getpGameStateMachine()->requestStackPop();
}

void PauseState::switchToMenu()
{
    cout << "Menu button clicked" << endl;
    Game::getpGame()->getpGameStateMachine()->requestStackChange(States::Menu);
}
