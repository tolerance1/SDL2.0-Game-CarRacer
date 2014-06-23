#include "Player.h"

#include "InputHandler.h"

#include <iostream>
using std::cout;
using std::endl;

extern const int offsetX;
extern const int offsetY;

Player::Player(const SetObjectParams* pInput)
: GameObject(pInput)
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
    if(InputHandler::getpInputHandler()->getMouseButtonState(LEFT))
    {
        vecPosition.setX(0 + offsetX);
        vecPosition.setY(200 + offsetY);
    }

}

void Player::queryKeyStates()
{
    if(InputHandler::getpInputHandler()->getKeyState(SDL_SCANCODE_RIGHT))
    {
        vecVelocity.setX(2);
    }

    if(InputHandler::getpInputHandler()->getKeyState(SDL_SCANCODE_LEFT))
    {
        vecVelocity.setX(-2);
    }

    if(InputHandler::getpInputHandler()->getKeyState(SDL_SCANCODE_UP))
    {
        vecVelocity.setY(-2);
    }

    if(InputHandler::getpInputHandler()->getKeyState(SDL_SCANCODE_DOWN))
    {
        vecVelocity.setY(2);
    }

}

void Player::updateObjectParams()
{
    //reset velocity
    vecVelocity.setX(0);
    vecVelocity.setY(0);

    queryMouseStates();
    queryKeyStates();

    m_currentFrame = int(((SDL_GetTicks() / 100) % 2));

    GameObject::updateObjectParams();
}

void Player::clean()
{

}
