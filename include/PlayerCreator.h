#ifndef PLAYERCREATOR_H
#define PLAYERCREATOR_H

#include <ObjectCreatorABC.h>

#include "Player.h"

class PlayerCreator : public ObjectCreatorABC
{
    public:
        PlayerCreator();
        ~PlayerCreator();

        GameObjectABC* createGameObject() const
        {
            return new Player();
        }
};

#endif // PLAYERCREATOR_H
