#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>

#include "Player.h"

class CollisionManager
{
    public:
        CollisionManager();
        ~CollisionManager();

        void checkPlayerEnemyCollision();

    private:
        enum PlayStateFunctionId {SWITCHTOPAUSE = 1, SWITCHTOGAMEOVER = 2};

        bool checkCollision(const GameObject* const p1,
                            const GameObject* const p2) const;

    public:
        Player* getpPlayer() {return pPlayer; }
        std::vector<GameObject*>* getEnemyList() {return &enemyList; }

        void setpPlayer(Player* player){pPlayer = player; }

    private:
        Player* pPlayer;
        std::vector<GameObject*> enemyList;
};

#endif // COLLISIONMANAGER_H
