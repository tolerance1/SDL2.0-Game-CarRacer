#include "Enemy.h"

#include <iostream>
using std::cout;
using std::endl;

Enemy::Enemy()
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
    Acceleration.setX(0.02);

    currentFrame = int(((SDL_GetTicks() / 100) % numFrames));

    GameObject::updateObjectParams();
}

void Enemy::initObject(const SetObjectParams* pInput)
{
    GameObject::initObject(pInput);
}

void Enemy::clean()
{

}
