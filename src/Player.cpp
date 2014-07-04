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
        Position.setX(0 + offsetX);
        Position.setY(200 + offsetY);
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

    currentFrame = int(((SDL_GetTicks() / 100) % 2));

    GameObject::updateObjectParams();
}

void Player::clean()
{

}
