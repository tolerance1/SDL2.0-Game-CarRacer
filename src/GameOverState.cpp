#include "GameOverState.h"

#include "Game.h"
#include "LevelParser.h"

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
}

void GameOverState::update()
{
    //update state
    pLevel->update();
}

void GameOverState::render()
{
    //draw state
    pLevel->render();
}

bool GameOverState::onEnter()
{
    //parse level (creates map, textures and objects)
    LevelParser levelParser(&textureIDs);
    pLevel = levelParser.parseLevel("xml/gameover_state.tmx");

    //populate array with function pointers
    callbackFuncs.push_back(nullptr);//skip index 0
    callbackFuncs.push_back(&GameOverState::restartPlay);
    callbackFuncs.push_back(&GameOverState::switchToMenu);

    cout << "entering GameOverState" << endl;
    return true;
}

bool GameOverState::onExit()
{
    cout << "exiting GameOverState" << endl;

    return GameStateABC::onExit();
}

void GameOverState::restartPlay()
{
    cout << "Restart button clicked" << endl;
    Game::getpGame()->getpGameStateMachine()->requestStackChange(States::Play);
}

void GameOverState::switchToMenu()
{
    cout << "Menu button clicked" << endl;
    Game::getpGame()->getpGameStateMachine()->requestStackChange(States::Menu);
}
