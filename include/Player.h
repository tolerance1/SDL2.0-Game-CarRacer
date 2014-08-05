#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

#include "PlayState.h"

class Player : public GameObject
{
    public:
        typedef void (PlayState::*PlayPtr)();

        Player(const SetObjectParams* pInput, PlayPtr pFunc);
        ~Player();

        void drawObject();
        void updateObjectParams();
        void clean();

    private:
        void queryMouseStates();
        void queryKeyStates();

        PlayPtr pPlayCallBack;
};

#endif // PLAYER_H
