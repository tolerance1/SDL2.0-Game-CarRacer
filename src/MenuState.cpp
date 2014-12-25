#include "MenuState.h"

#include "Game.h"
#include "LevelParser.h"

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
    //update state
    pLevel->update();
}

void MenuState::render()
{
    //draw state
    pLevel->render();
}

bool MenuState::onEnter()
{
    //parse level (creates map, textures and objects)
    LevelParser levelParser(&textureIDs);
    pLevel = levelParser.parseLevel("xml/menu_state.tmx");

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
    Game::getpGame()->getpGameStateMachine()->requestStackChange(States::Play);
}

void MenuState::exitFromGame()
{
    cout << "Exit button clicked" << endl;
    Game::getpGame()->setbRunning() = false;
}
