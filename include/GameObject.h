#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GameObjectABC.h"

#include <string>

#include "SDL.h"
#include "SetObjectParams.h"

class GameObject : public GameObjectABC
{
    public:
        GameObject(const SetObjectParams* pInput);
        ~GameObject();

        void drawObject();
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

        double m_rotationAngle;//rotate dest. rect.

        SDL_RendererFlip m_flip;
};

#endif // GAMEOBJECT_H
