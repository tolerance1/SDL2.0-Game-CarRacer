#include "StaticGraphic.h"

#include "InputHandler.h"
#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

StaticGraphic::StaticGraphic(const SetObjectParams* pInput)
: GameObject(pInput)
{
    cout << " 15 C StaticGraphic" << endl;
}

StaticGraphic::StaticGraphic(const SetObjectParams* pInput, MenuPtr pFunc)
: GameObject(pInput), pMenuCallBack(pFunc)
{
    cout << " 15 C StaticGraphic" << endl;
}

StaticGraphic::~StaticGraphic()
{
    cout << " 15 D StaticGraphic" << endl;
}

void StaticGraphic::drawObject()
{
    GameObject::drawObject();
}

void StaticGraphic::updateObjectParams()
{
    const std::string& StateID =
    Game::getpGame()->getpGameStateMachine()->getGameStates().top()->getStateID();

    if(StateID == "MENU")
    {
        if(! InputHandler::getpInputHandler()->getKeyState(SDL_SCANCODE_RETURN))
        {
            bReleased = true;
        }
        else if(InputHandler::getpInputHandler()->getKeyState(SDL_SCANCODE_RETURN) && bReleased)
        {
            bReleased = false;

            Game::getpGame()->getpGameStateMachine()->setbPendingChanges() = true;
            Game::getpGame()->getpGameStateMachine()->setpMenuCallBack() = pMenuCallBack;
        }
    }
}

void StaticGraphic::clean()
{

}
