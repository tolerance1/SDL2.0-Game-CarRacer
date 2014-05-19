#include "GameObject.h"

#include "TextureManager.h"
#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

GameObject::GameObject(const SetObjectParams* pInput)
: vecPosition(pInput->getX(), pInput->getY()), vecVelocity(0, 0), vecAcceleration(0, 0)
{
    cout << " 4 C GameObject" << endl;

    m_textureID = pInput->getTextureID();

    m_width = pInput->getWidth();
    m_height = pInput->getHeight();

    m_currentRow = pInput->getCurrentRow();
    m_currentFrame = pInput->getCurrentFrame();

    m_rotationAngle = pInput->getRotationAngle();

    m_flip = pInput->getFlip();

    //release parameters object
    delete pInput;
}

GameObject::~GameObject()
{
    cout << " 4 D GameObject" << endl;
}

void GameObject::drawObject()
{
    TextureManager::getpTextureManager()->drawTexture(m_textureID,
                                                      (int)vecPosition.getX(), (int)vecPosition.getY(),
                                                      m_width, m_height,
                                                      m_currentRow, m_currentFrame,
                                                      Game::getpGame()->getpRenderer(),
                                                      m_rotationAngle, m_flip);
}

void GameObject::updateObjectParams()
{
    vecVelocity += vecAcceleration;
    vecPosition += vecVelocity;
}

void GameObject::clean()
{

}
