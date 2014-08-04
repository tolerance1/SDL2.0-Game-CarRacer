#ifndef STATICGRAPHIC_H
#define STATICGRAPHIC_H

#include "GameObject.h"

#include "MenuState.h"

class StaticGraphic : public GameObject
{
    public:
        typedef void (MenuState::*MenuPtr)();

        StaticGraphic(const SetObjectParams* pInput);
        StaticGraphic(const SetObjectParams* pInput, MenuPtr pFunc);
        ~StaticGraphic();

        void drawObject();
        void updateObjectParams();
        void clean();

    private:
        MenuPtr pMenuCallBack;
        bool bReleased;
};

#endif // STATICGRAPHIC_H
