#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
    public:
        Player(const SetObjectParams* pInput);
        ~Player();

        void drawObject();
        void updateObjectParams();
        void clean();

    private:
        void queryMouseStates();
        void queryKeyStates();
};

#endif // PLAYER_H
