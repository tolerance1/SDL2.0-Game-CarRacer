#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject
{
    public:
        Enemy(const SetObjectParams* pInput);
        ~Enemy();

        void drawObject();
        void updateObjectParams();
        void clean();

};

#endif // ENEMY_H
