#include "Enemy.h"

#include <iostream>
using std::cout;
using std::endl;

Enemy::Enemy(const SetObjectParams* pInput)
: GameObject(pInput)
{
    cout << " 6 C Enemy" << endl;
}

Enemy::~Enemy()
{
    cout << " 6 D Enemy" << endl;
}

void Enemy::drawObject()
{
    GameObject::drawObject();
}

void Enemy::updateObjectParams()
{
    vecAcceleration.setX(0.02);

    m_currentFrame = int(((SDL_GetTicks() / 100) % 2));

    GameObject::updateObjectParams();
}

void Enemy::clean()
{

}
