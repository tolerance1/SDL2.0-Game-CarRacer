#include "Enemy.h"

#include <iostream>
using std::cout;
using std::endl;

Enemy::Enemy(const SetObjectParams* pInput)
: GameObject(pInput)
{
    cout << "_6C Enemy" << endl;
}

Enemy::~Enemy()
{
    cout << "_6D Enemy" << endl;
}

void Enemy::drawObject()
{
    GameObject::drawObject();
}

void Enemy::updateObjectParams()
{
    m_x += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
}

void Enemy::clean()
{

}
