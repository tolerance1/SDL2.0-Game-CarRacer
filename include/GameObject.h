#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

#include "SDL.h"

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        void setObjectParams(std::string textureID, int destX, int destY,
                             int width, int height,
                             int currentRow, int currentFrame,
                             double rotationAngle = 0,
                             SDL_RendererFlip flip = SDL_FLIP_NONE);
        void drawObject(SDL_Renderer* pRenderer);
        void updateObjectParams();
        void clean();

    protected:
        std::string m_textureID;

        int m_x;//dest. coord. X
        int m_y;//dest. coord. Y

        int m_width;
        int m_height;

        int m_currentFrame;
        int m_currentRow;

        double m_rotationAngle;//applied to dest. rect.

        SDL_RendererFlip m_flip;
};

#endif // GAMEOBJECT_H
