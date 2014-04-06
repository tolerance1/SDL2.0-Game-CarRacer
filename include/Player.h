#ifndef PLAYER_H
#define PLAYER_H

#include <GameObject.h>


class Player : public GameObject
{
    public:
        Player();
        ~Player();

        void setObjectParams(std::string textureID, int destX, int destY,
                             int width, int height,
                             int currentRow, int currentFrame,
                             double rotationAngle = 0,
                             SDL_RendererFlip flip = SDL_FLIP_NONE);
        void drawObject(SDL_Renderer* pRenderer);
        void updateObjectParams();
        void clean();

};

#endif // PLAYER_H
