#ifndef OBJECTCREATORABC_H
#define OBJECTCREATORABC_H

#include "GameObjectABC.h"

class ObjectCreatorABC
{
    public:
        ObjectCreatorABC();
        virtual ~ObjectCreatorABC();

        virtual GameObjectABC* createGameObject() const = 0;
};

#endif // OBJECTCREATORABC_H
