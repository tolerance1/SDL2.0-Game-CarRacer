#include "GameObject.h"

#include "TextureManager.h"
#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

GameObject::GameObject(const SetObjectParams* pInput)
{
    cout << "_4C GameObject" << endl;

    m_textureID = pInput->getTextureID();

    m_x = pInput->getX();
    m_y = pInput->getY();

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
    cout << "_4D GameObject" << endl;
}

void GameObject::drawObject()
{
    TextureManager::getpTextureManager()->drawTexture(m_textureID, m_x, m_y,
                                                      m_width, m_height,
                                                      m_currentRow, m_currentFrame,
                                                      Game::getpGame()->getpRenderer(),
                                                      m_rotationAngle, m_flip);
}

void GameObject::updateObjectParams()
{

}

void GameObject::clean()
{

}
