#include "PlayState.h"

#include "Game.h"
#include "StateParser.h"
#include "PauseState.h"
#include "GameOverState.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
const std::string PlayState::playID = "PLAY";

PlayState::PlayState()
{
    cout << " 12 C PlayState" << endl;
}

PlayState::~PlayState()
{
    cout << " 12 D PlayState" << endl;
}

void PlayState::update()
{
    //update game objects destination coordinates and current frame
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->updateObjectParams();
    }

    for(size_t EnemyIndex = 1; EnemyIndex <= 2; ++EnemyIndex)
    {
        if(checkCollision(static_cast<GameObject*>(gameObjects[0]),
                          static_cast<GameObject*>(gameObjects[EnemyIndex])))
        {
            Game::getpGame()->getpGameStateMachine()->setCallbackID(SWITCHTOGAMEOVER);
        }
    }
}

void PlayState::render()
{
    //draw game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->drawObject();
    }
}

bool PlayState::onEnter()
{
    //parse the state (creates textures and objects)
    StateParser parser;
    parser.parseState("xml/game_states.xml", playID, &textureIDs, &gameObjects);

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
    Game::getpGame()->getpGameStateMachine()->pushState(new PauseState());
}

void PlayState::switchToGameOver()
{
    Game::getpGame()->getpGameStateMachine()->pushState(new GameOverState());
}

bool PlayState::checkCollision(GameObject* p1, GameObject* p2) const
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = p1->getPosition().getX();
    rightA = p1->getPosition().getX() + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = p1->getPosition().getY() + p1->getHeight();

    leftB = p2->getPosition().getX();
    rightB = p2->getPosition().getX() + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = p2->getPosition().getY() + p2->getHeight();

    if( bottomA <= topB ){return false; }
    if( topA >= bottomB ){return false; }
    if( rightA <= leftB ){return false; }
    if( leftA >= rightB ){return false; }

    return true;
}
