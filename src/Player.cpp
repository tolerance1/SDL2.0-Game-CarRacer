#include "Player.h"

#include <iostream>
using std::cout;
using std::endl;

Player::Player()
{
    cout << "_Player constructor" << endl;
}

Player::~Player()
{
    cout << "_Player destructor" << endl;
}

void Player::setObjectParams(std::string textureID, int destX, int destY,
                             int width, int height,
                             int currentRow, int currentFrame,
                             double rotationAngle,
                             SDL_RendererFlip flip)
{
    //reuse functionality
    GameObject::setObjectParams(textureID, destX, destY, width, height,
                                currentRow, currentFrame,
                                rotationAngle, flip);
}

void Player::drawObject(SDL_Renderer* pRenderer)
{
    GameObject::drawObject(pRenderer);
}

void Player::updateObjectParams()
{
    m_x += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
}

void Player::clean()
{

}
