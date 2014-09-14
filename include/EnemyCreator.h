#ifndef ENEMYCREATOR_H
#define ENEMYCREATOR_H

#include <ObjectCreatorABC.h>

#include "Enemy.h"

class EnemyCreator : public ObjectCreatorABC
{
    public:
        EnemyCreator();
        ~EnemyCreator();

        GameObjectABC* createGameObject() const
        {
            return new Enemy();
        }
};

#endif // ENEMYCREATOR_H
