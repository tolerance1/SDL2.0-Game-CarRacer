#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <bitset>

#include "Vector2D.h"
#include "SDL.h"

enum MouseButtons {LEFT = 0, MIDDLE = 1, RIGHT = 2};

class InputHandler
{
    public:
        ~InputHandler();

        void updateInputStates();//poll events and update InputHandler
        void clean();//clean initialised devices

        bool getKeyState(SDL_Scancode keyCode) const;
        bool getMouseButtonState(int buttonNumber) const;

        Vector2D* getpMousePosition() const;

        static InputHandler* getpInputHandler();//create a single instance

    private:
        static InputHandler* pInputHandler;//pointer to the instance

        const Uint8* pKeyStates;//pointer to the SDL inbuilt key states array

        Vector2D* pMousePosition;

        std::bitset<3> mouseButtonStates;//3 bits set to zero

        //handle mouse events
        void onMouseButtonDown(SDL_Event& event);
        void onMouseButtonUp(SDL_Event& event);
        void onMouseMove(SDL_Event& event);

        InputHandler();
        InputHandler(const InputHandler& rhs);
        InputHandler& operator=(const InputHandler& rhs);
};

#endif // INPUTHANDLER_H
