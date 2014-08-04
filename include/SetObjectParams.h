#ifndef SETOBJECTPARAMS_H
#define SETOBJECTPARAMS_H

#include <string>

#include "SDL.h"

//stores game object parameters in a separate object
class SetObjectParams
{
    public:
        SetObjectParams(std::string textureID, int destX, int destY,
                        int width, int height,
                        int currentRow, int currentFrame,
                        int numFrames = 1,
                        double rotationAngle = 0,
                        SDL_RendererFlip flip = SDL_FLIP_NONE);
        ~SetObjectParams();

        const std::string& getTextureID() const {return textureID; }
        int getX() const {return x; }
        int getY() const {return y; }
        int getWidth() const {return width; }
        int getHeight() const {return height; }
        int getCurrentFrame() const {return currentFrame; }
        int getCurrentRow() const {return currentRow; }
        int getNumFrames() const {return numFrames; }
        double getRotationAngle() const {return rotationAngle; }
        SDL_RendererFlip getFlip() const {return flip; }

    private:
        std::string textureID;

        int x;//dest. coord. X
        int y;//dest. coord. Y

        int width;
        int height;

        int currentFrame;
        int currentRow;

        int numFrames;

        double rotationAngle;//rotate dest. rect.

        SDL_RendererFlip flip;
};

#endif // SETOBJECTPARAMS_H
