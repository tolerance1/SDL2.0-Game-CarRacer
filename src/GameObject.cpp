#include "GameObject.h"

#include "TextureManager.h"

#include <iostream>
using std::cout;
using std::endl;

GameObject::GameObject()
{
    cout << "_GameObject constructor" << endl;
}

GameObject::~GameObject()
{
    cout << "_GameObject destructor" << endl;
}

void GameObject::setObjectParams(std::string textureID, int destX, int destY,
                                 int width, int height,
                                 int currentRow, int currentFrame,
                                 double rotationAngle,
                                 SDL_RendererFlip flip)
{
    m_textureID = textureID;

    m_x = destX;
    m_y = destY;

    m_width = width;
    m_height = height;

    m_currentRow = currentRow;
    m_currentFrame = currentFrame;

    m_rotationAngle = rotationAngle;

    m_flip = flip;
}

void GameObject::drawObject(SDL_Renderer* pRenderer)
{
    TextureManager::getpTextureManager()->drawTexture(m_textureID, m_x, m_y,
                                                      m_width, m_height,
                                                      m_currentRow, m_currentFrame,
                                                      pRenderer, m_rotationAngle, m_flip);
}

void GameObject::updateObjectParams()
{
    m_x -= 1;
    m_y += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 2));//return an offset
}

void GameObject::clean()
{

}
