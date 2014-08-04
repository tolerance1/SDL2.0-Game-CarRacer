#include "Button.h"

#include "InputHandler.h"
#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

Button::Button(const SetObjectParams* pInput, MenuPtr pFunc)
: GameObject(pInput), pMenuCallBack(pFunc)
{
    cout << " 14 C Button" << endl;
}

Button::Button(const SetObjectParams* pInput, PlayPtr pFunc)
: GameObject(pInput), pPlayCallBack(pFunc)
{
    cout << " 14 C Button" << endl;
}

Button::Button(const SetObjectParams* pInput, PausePtr pFunc)
: GameObject(pInput), pPauseCallBack(pFunc)
{
    cout << " 14 C Button" << endl;
}

Button::Button(const SetObjectParams* pInput, GOverPtr pFunc)
: GameObject(pInput), pGOverCallBack(pFunc)
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

            Game::getpGame()->getpGameStateMachine()->setbPendingChanges() = true;
            transferFuncPtr();
        }
    }
    else
    {
        currentFrame = MOUSE_OUT;
    }
}

void Button::transferFuncPtr()
{
    const std::string& StateID =
    Game::getpGame()->getpGameStateMachine()->getGameStates().top()->getStateID();

    if(StateID == "MENU")
    {
        Game::getpGame()->getpGameStateMachine()->setpMenuCallBack() = pMenuCallBack;
    }
    if(StateID == "PLAY")
    {
        Game::getpGame()->getpGameStateMachine()->setpPlayCallBack() = pPlayCallBack;
    }
    if(StateID == "PAUSE")
    {
        Game::getpGame()->getpGameStateMachine()->setpPauseCallBack() = pPauseCallBack;
    }
    if(StateID == "GAMEOVER")
    {
        Game::getpGame()->getpGameStateMachine()->setpGOverCallBack() = pGOverCallBack;
    }
}

void Button::clean()
{

}
