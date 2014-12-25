#include "CollisionManager.h"

#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

CollisionManager::CollisionManager()
{
    cout << " 30 C CollisionManager" << endl;
}

CollisionManager::~CollisionManager()
{
    cout << " 30 D CollisionManager" << endl;
}

void CollisionManager::checkPlayerEnemyCollision()
{
    for(size_t Index = 0; Index != enemyList.size(); ++Index)
    {
        if(checkCollision(pPlayer, enemyList[Index]))
        {
            Game::getpGame()->getpGameStateMachine()->getGameStates().top()->callFunction(SWITCHTOGAMEOVER);
        }
    }
}

bool CollisionManager::checkCollision(const GameObject* const p1,
                                      const GameObject* const p2) const
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
