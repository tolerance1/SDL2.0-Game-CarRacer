#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameStateABC.h"

#include "GameObject.h"

class PlayState : public GameStateABC
{
    public:
        typedef void (PlayState::*PlayPtr)();

        PlayState();
        ~PlayState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return playID; }
        const std::vector<PlayPtr>& getCallbackFuncs() const {return callbackFuncs; }

    private:
        static const std::string playID;

        //function pointers array
        std::vector<PlayPtr> callbackFuncs;

        //call back functions
        void switchToPause();
        void switchToGameOver();

        bool checkCollision(GameObject* p1, GameObject* p2) const;

        enum FunctionId {SWITCHTOPAUSE = 1, SWITCHTOGAMEOVER = 2};
};

#endif // PLAYSTATE_H
