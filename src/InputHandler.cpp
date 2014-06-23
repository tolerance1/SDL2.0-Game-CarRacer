#include "InputHandler.h"

#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
InputHandler* InputHandler::pInputHandler = nullptr;

InputHandler* InputHandler::getpInputHandler()
{
    if(pInputHandler == nullptr)
    {
        pInputHandler = new InputHandler();
        return pInputHandler;
    }

    return pInputHandler;
}

InputHandler::InputHandler()
: pMousePosition(new Vector2D(0, 0))
{
    cout << " 9 C InputHandler" << endl;

    pKeyStates = SDL_GetKeyboardState(NULL);//the array memory is released by SDL
}

InputHandler::~InputHandler()
{
    cout << " 9 D InputHandler" << endl;

    delete pMousePosition;//release mouse position memory
}

bool InputHandler::getMouseButtonState(int buttonNumber) const
{
    return mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getpMousePosition() const
{
    return pMousePosition;
}

bool InputHandler::getKeyState(SDL_Scancode keyCode) const
{
    if(pKeyStates != NULL)
    {
        return pKeyStates[keyCode];//returns 1 if key is being pressed
    }

    return false;
}

void InputHandler::updateInputStates()
{
    SDL_Event event;//events are placed into this union of structs

    while(SDL_PollEvent(&event))//returns 1 if an event has been placed into the union
    {
        switch(event.type)//check the event type
        {
            case SDL_QUIT:
                Game::getpGame()->setbRunning() = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;

            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;

            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;

            case SDL_KEYDOWN:
                break;

            case SDL_KEYUP:
                break;

            //unhandled event
            default:
                break;
        }
    }
}

void InputHandler::onMouseButtonDown(SDL_Event& event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates.set(LEFT, true);
    }

    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates.set(MIDDLE, true);
    }

    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates.set(RIGHT, true);
    }
}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates.set(LEFT, false);
    }

    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates.set(MIDDLE, false);
    }

    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates.set(RIGHT, false);
    }
}

void InputHandler::onMouseMove(SDL_Event& event)
{
    pMousePosition->setX(event.motion.x);
    pMousePosition->setY(event.motion.y);
}

void InputHandler::clean()
{

}
