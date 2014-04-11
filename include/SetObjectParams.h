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
                        double rotationAngle = 0,
                        SDL_RendererFlip flip = SDL_FLIP_NONE);
        ~SetObjectParams();

        const std::string& getTextureID() const {return m_textureID; }
        int getX() const {return m_x; }
        int getY() const {return m_y; }
        int getWidth() const {return m_width; }
        int getHeight() const {return m_height; }
        int getCurrentFrame() const {return m_currentFrame; }
        int getCurrentRow() const {return m_currentRow; }
        double getRotationAngle() const {return m_rotationAngle; }
        SDL_RendererFlip getFlip() const {return m_flip; }

    private:
        std::string m_textureID;

        int m_x;//dest. coord. X
        int m_y;//dest. coord. Y

        int m_width;
        int m_height;

        int m_currentFrame;
        int m_currentRow;

        double m_rotationAngle;//rotate dest. rect.

        SDL_RendererFlip m_flip;
};

#endif // SETOBJECTPARAMS_H
