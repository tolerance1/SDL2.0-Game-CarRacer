#ifndef STATICGRAPHICCREATOR_H
#define STATICGRAPHICCREATOR_H

#include <ObjectCreatorABC.h>

#include "StaticGraphic.h"

class StaticGraphicCreator : public ObjectCreatorABC
{
    public:
        StaticGraphicCreator();
        ~StaticGraphicCreator();

        GameObjectABC* createGameObject() const
        {
            return new StaticGraphic();
        }
};

#endif // STATICGRAPHICCREATOR_H
