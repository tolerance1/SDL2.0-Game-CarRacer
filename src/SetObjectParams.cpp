#include "SetObjectParams.h"

#include <iostream>
using std::cout;
using std::endl;

SetObjectParams::SetObjectParams(std::string textureID, int destX, int destY,
                                 int width, int height,
                                 int currentRow, int currentFrame,
                                 double rotationAngle,
                                 SDL_RendererFlip flip)
: m_textureID(textureID), m_x(destX), m_y(destY), m_width(width), m_height(height),
m_currentFrame(currentFrame), m_currentRow(currentRow),
m_rotationAngle(rotationAngle), m_flip(flip)
{
    cout << "_7C SetObjectParams" << endl;
}

SetObjectParams::~SetObjectParams()
{
    cout << "_7D SetObjectParams" << endl;
}
