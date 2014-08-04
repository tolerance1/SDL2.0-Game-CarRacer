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

        const Vector2D& getPosition() const {return Position; }
        int getWidth() const {return width; }
        int getHeight() const {return height; }

    protected:
        std::string textureID;

        Vector2D Position;//dest. coord. X, Y
        Vector2D Velocity;
        Vector2D Acceleration;

        int width;
        int height;

        int currentFrame;
        int currentRow;

        int numFrames;

        double rotationAngle;//rotate dest. rect.

        SDL_RendererFlip flip;
};

#endif // GAMEOBJECT_H
