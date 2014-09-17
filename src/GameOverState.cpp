#include "GameOverState.h"

#include "Game.h"
#include "StateParser.h"
#include "PlayState.h"
#include "MenuState.h"

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
    //parse the state (creates textures and objects)
    StateParser parser;
    parser.parseState("xml/game_states.xml", gameOverID, &textureIDs, &gameObjects);

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
    Game::getpGame()->getpGameStateMachine()->changeState(new PlayState());
}

void GameOverState::switchToMenu()
{
    cout << "Menu button clicked" << endl;
    Game::getpGame()->getpGameStateMachine()->changeState(new MenuState());
}
