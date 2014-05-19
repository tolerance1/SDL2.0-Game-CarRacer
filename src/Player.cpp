#include "Player.h"

#include <iostream>
using std::cout;
using std::endl;

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

void Player::updateObjectParams()
{
    vecVelocity.setY(1);
    vecAcceleration.setX(-0.01);

    m_currentFrame = int(((SDL_GetTicks() / 100) % 2));

    GameObject::updateObjectParams();
}

void Player::clean()
{

}
