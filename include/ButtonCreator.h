#ifndef BUTTONCREATOR_H
#define BUTTONCREATOR_H

#include <ObjectCreatorABC.h>

#include "Button.h"

class ButtonCreator : public ObjectCreatorABC
{
    public:
        ButtonCreator();
        ~ButtonCreator();

        GameObjectABC* createGameObject() const
        {
            return new Button();
        }
};

#endif // BUTTONCREATOR_H
