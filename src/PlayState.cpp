#include "PlayState.h"

#include "Game.h"
#include "LevelParser.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
const std::string PlayState::playID = "PLAY";

PlayState::PlayState()
{
    cout << " 12 C PlayState" << endl;

    pCollisionManager = new CollisionManager();
}

PlayState::~PlayState()
{
    cout << " 12 D PlayState" << endl;

    delete pCollisionManager;
}

void PlayState::update()
{
    //update state
    pLevel->update();

    pCollisionManager->checkPlayerEnemyCollision();
}

void PlayState::render()
{
    //draw state
    pLevel->render();
}

bool PlayState::onEnter()
{
    //parse level (creates map, textures and objects)
    LevelParser levelParser(&textureIDs, pCollisionManager);
    pLevel = levelParser.parseLevel("xml/play_state.tmx");

    //populate array with function pointers
    callbackFuncs.push_back(nullptr);//skip index 0
    callbackFuncs.push_back(&PlayState::switchToPause);
    callbackFuncs.push_back(&PlayState::switchToGameOver);

    cout << "entering PlayState" << endl;
    return true;
}

bool PlayState::onExit()
{
    cout << "exiting PlayState" << endl;

    return GameStateABC::onExit();
}

void PlayState::switchToPause()
{
    Game::getpGame()->getpGameStateMachine()->requestStackPush(States::Pause);
}

void PlayState::switchToGameOver()
{
    Game::getpGame()->getpGameStateMachine()->requestStackPush(States::Gameover);
}
