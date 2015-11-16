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
    const Vector2D& mousePosition = InputHandler::getpInputHandler()->getMousePosition();

    if(mousePosition.getX() > Position.getX() &&
       mousePosition.getX() < Position.getX() + width &&
       mousePosition.getY() > Position.getY() &&
       mousePosition.getY() < Position.getY() + height)
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

            Game::getpGame()->getpGameStateMachine()->getGameStates().top()->callFunction(callbackID);
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
