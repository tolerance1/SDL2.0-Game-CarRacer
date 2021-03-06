#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject
{
    public:
        Enemy();
        ~Enemy();

        void drawObject();
        void updateObjectParams();
        void clean();

        void initObject(const SetObjectParams* pInput);

    private:
        int animSpeed;
};

#endif // ENEMY_H
