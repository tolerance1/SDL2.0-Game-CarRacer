#include "Player.h"

#include "InputHandler.h"
#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

Player::Player()
{
    cout << " 5 C Player" << endl;
}

Player::~Player()
{
    cout << " 5 D Player" << endl;
}

void Player::drawObject()
{
    GameObject::drawObject();
}

void Player::queryMouseStates()
{
    if(InputHandler::getpInputHandler()->getMouseButtonState(RIGHT))
    {
        Position.setX(0);
        Position.setY(200);
    }

    if(InputHandler::getpInputHandler()->getMouseButtonState(MIDDLE))
    {
        Game::getpGame()->getpGameStateMachine()->setCallbackID(callbackID);
    }

}

void Player::queryKeyStates()
{
    if(InputHandler::getpInputHandler()->getKeyState(SDL_SCANCODE_RIGHT))
    {
        Velocity.setX(2);
    }

    if(InputHandler::getpInputHandler()->getKeyState(SDL_SCANCODE_LEFT))
    {
        Velocity.setX(-2);
    }

    if(InputHandler::getpInputHandler()->getKeyState(SDL_SCANCODE_UP))
    {
        Velocity.setY(-2);
    }

    if(InputHandler::getpInputHandler()->getKeyState(SDL_SCANCODE_DOWN))
    {
        Velocity.setY(2);
    }

}

void Player::updateObjectParams()
{
    //reset velocity
    Velocity.setX(0);
    Velocity.setY(0);

    queryMouseStates();
    queryKeyStates();

    currentFrame = int(((SDL_GetTicks() / 100) % numFrames));

    GameObject::updateObjectParams();
}

void Player::initObject(const SetObjectParams* pInput)
{
    callbackID = pInput->getCallbackID();

    GameObject::initObject(pInput);
}

void Player::clean()
{

}
