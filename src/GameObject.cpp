#include "GameObject.h"

#include "TextureManager.h"
#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

GameObject::GameObject()
{
    cout << " 4 C GameObject" << endl;
}

GameObject::~GameObject()
{
    cout << " 4 D GameObject" << endl;
}

void GameObject::initObject(const SetObjectParams* pInput)
{
    Position = Vector2D(pInput->getX(), pInput->getY());

    textureID = pInput->getTextureID();

    width = pInput->getWidth();
    height = pInput->getHeight();

    currentRow = pInput->getCurrentRow();
    currentFrame = pInput->getCurrentFrame();

    numFrames = pInput->getNumFrames();

    rotationAngle = pInput->getRotationAngle();

    flip = pInput->getFlip();

    //release parameters object
    delete pInput;
}

void GameObject::drawObject()
{
    TextureManager::getpTextureManager()->drawTexture(textureID,
                                                      (int)Position.getX(), (int)Position.getY(),
                                                      width, height,
                                                      currentRow, currentFrame,
                                                      Game::getpGame()->getpRenderer(),
                                                      rotationAngle, flip);
}

void GameObject::updateObjectParams()
{
    Velocity += Acceleration;
    Position += Velocity;
}

void GameObject::clean()
{

}
