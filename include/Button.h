#ifndef BUTTON_H
#define BUTTON_H

#include "GameObject.h"

#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"

class Button : public GameObject
{
    public:
        typedef void (MenuState::*MenuPtr)();
        typedef void (PlayState::*PlayPtr)();
        typedef void (PauseState::*PausePtr)();
        typedef void (GameOverState::*GOverPtr)();

        Button(const SetObjectParams* pInput, MenuPtr pFunc);
        Button(const SetObjectParams* pInput, PlayPtr pFunc);
        Button(const SetObjectParams* pInput, PausePtr pFunc);
        Button(const SetObjectParams* pInput, GOverPtr pFunc);
        ~Button();

        void drawObject();
        void updateObjectParams();
        void clean();

    private:
        enum ButtonState {MOUSE_OUT = 0, MOUSE_OVER = 1, CLICKED = 2};

        union//save memory
        {
            MenuPtr pMenuCallBack;
            PlayPtr pPlayCallBack;
            PausePtr pPauseCallBack;
            GOverPtr pGOverCallBack;
        };

        bool bReleased;

        void transferFuncPtr();
};

#endif // BUTTON_H
