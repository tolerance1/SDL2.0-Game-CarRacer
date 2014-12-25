#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameStateABC.h"

#include "CollisionManager.h"

class PlayState : public GameStateABC
{
    public:
        PlayState();
        ~PlayState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return playID; }

        void callFunction(size_t callbackID)
        {
            (this->*callbackFuncs[callbackID])();
        }

    private:
        typedef void (PlayState::*PlayPtr)();

        static const std::string playID;

        //function pointers array
        std::vector<PlayPtr> callbackFuncs;

        //call back functions
        void switchToPause();
        void switchToGameOver();

    private:
        CollisionManager* pCollisionManager;
};

#endif // PLAYSTATE_H
