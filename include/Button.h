#ifndef BUTTON_H
#define BUTTON_H

#include "GameObject.h"

class Button : public GameObject
{
    public:
        Button();
        ~Button();

        void drawObject();
        void updateObjectParams();
        void clean();

        void initObject(const SetObjectParams* pInput);

    private:
        enum ButtonState {MOUSE_OUT = 0, MOUSE_OVER = 1, CLICKED = 2};

        bool bReleased;

        size_t callbackID;//index into function pointers array
};

#endif // BUTTON_H
