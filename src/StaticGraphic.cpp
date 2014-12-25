#include "StaticGraphic.h"

#include "InputHandler.h"
#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

StaticGraphic::StaticGraphic()
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

            Game::getpGame()->getpGameStateMachine()->getGameStates().top()->callFunction(callbackID);
        }
    }
}

void StaticGraphic::initObject(const SetObjectParams* pInput)
{
    callbackID = pInput->getCallbackID();

    GameObject::initObject(pInput);
}

void StaticGraphic::clean()
{

}
