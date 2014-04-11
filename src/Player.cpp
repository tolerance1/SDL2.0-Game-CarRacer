#include "Player.h"

#include <iostream>
using std::cout;
using std::endl;

Player::Player(const SetObjectParams* pInput)
: GameObject(pInput)
{
    cout << "_5C Player" << endl;
}

Player::~Player()
{
    cout << "_5D Player" << endl;
}

void Player::drawObject()
{
    GameObject::drawObject();
}

void Player::updateObjectParams()
{
    m_x -= 1;
    m_y += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
}

void Player::clean()
{

}
