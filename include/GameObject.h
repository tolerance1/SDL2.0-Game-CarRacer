#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GameObjectABC.h"

#include "SetObjectParams.h"
#include "Vector2D.h"

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

        Vector2D vecPosition;//dest. coord. X, Y
        Vector2D vecVelocity;
        Vector2D vecAcceleration;

        int m_width;
        int m_height;

        int m_currentFrame;
        int m_currentRow;

        double m_rotationAngle;//rotate dest. rect.

        SDL_RendererFlip m_flip;
};

#endif // GAMEOBJECT_H
