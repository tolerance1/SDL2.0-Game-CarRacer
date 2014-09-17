#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "GameStateABC.h"

class PauseState : public GameStateABC
{
    public:
        typedef void (PauseState::*PausePtr)();

        PauseState();
        ~PauseState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return pauseID; }
        const std::vector<PausePtr>& getCallbackFuncs() const {return callbackFuncs; }

    private:
        static const std::string pauseID;

        //function pointers array
        std::vector<PausePtr> callbackFuncs;

        //call back functions
        void resumePlay();
        void switchToMenu();
};

#endif // PAUSESTATE_H
