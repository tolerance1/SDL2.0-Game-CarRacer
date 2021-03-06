#include "SetObjectParams.h"

#include <iostream>
using std::cout;
using std::endl;

SetObjectParams::SetObjectParams(std::string textureID, int destX, int destY,
                                 int width, int height,
                                 int currentRow, int currentFrame,
                                 int numFrames, int animSpeed,
                                 int callbackID,
                                 double rotationAngle,
                                 SDL_RendererFlip flip)
: textureID(textureID), x(destX), y(destY), width(width), height(height),
currentFrame(currentFrame), currentRow(currentRow),
numFrames(numFrames), animSpeed(animSpeed),
callbackID(callbackID), rotationAngle(rotationAngle), flip(flip)
{
    cout << " 7 C SetObjectParams" << endl;
}

SetObjectParams::~SetObjectParams()
{
    cout << " 7 D SetObjectParams" << endl;
}
