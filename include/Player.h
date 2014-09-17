#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
    public:
        Player();
        ~Player();

        void drawObject();
        void updateObjectParams();
        void clean();

        void initObject(const SetObjectParams* pInput);

    private:
        int callbackID;

        void queryMouseStates();
        void queryKeyStates();
};

#endif // PLAYER_H
