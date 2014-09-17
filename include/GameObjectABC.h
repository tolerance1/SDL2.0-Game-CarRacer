#ifndef GAMEOBJECTABC_H
#define GAMEOBJECTABC_H

#include "SetObjectParams.h"

class GameObjectABC
{
    public:
        GameObjectABC();
        virtual ~GameObjectABC();

        virtual void drawObject() = 0;
        virtual void updateObjectParams() = 0;
        virtual void clean() = 0;

        virtual void initObject(const SetObjectParams* pInput) = 0;
};

#endif // GAMEOBJECTABC_H
