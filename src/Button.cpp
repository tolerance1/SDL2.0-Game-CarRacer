#include "Button.h"

#include "InputHandler.h"
#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

Button::Button()
{
    cout << " 14 C Button" << endl;
}

Button::~Button()
{
    cout << " 14 D Button" << endl;
}

void Button::drawObject()
{
    GameObject::drawObject();
}

void Button::updateObjectParams()
{
    Vector2D* pMousePosition = InputHandler::getpInputHandler()->getpMousePosition();

    if(pMousePosition->getX() > Position.getX() &&
       pMousePosition->getX() < Position.getX() + width &&
       pMousePosition->getY() > Position.getY() &&
       pMousePosition->getY() < Position.getY() + height)
    {
        if(! InputHandler::getpInputHandler()->getMouseButtonState(LEFT))
        {
            currentFrame = MOUSE_OVER;
            bReleased = true;
        }
        else if(InputHandler::getpInputHandler()->getMouseButtonState(LEFT) && bReleased)
        {
            currentFrame = CLICKED;
            bReleased = false;

            Game::getpGame()->getpGameStateMachine()->setCallbackID(callbackID);
        }
    }
    else
    {
        currentFrame = MOUSE_OUT;
    }
}

void Button::initObject(const SetObjectParams* pInput)
{
    callbackID = pInput->getCallbackID();

    GameObject::initObject(pInput);
}

void Button::clean()
{

}
