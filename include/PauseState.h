#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "GameStateABC.h"

class PauseState : public GameStateABC
{
    public:
        PauseState();
        ~PauseState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return pauseID; }

        void callFunction(size_t callbackID)
        {
            (this->*callbackFuncs[callbackID])();
        }

    private:
        typedef void (PauseState::*PausePtr)();

        static const std::string pauseID;

        //function pointers array
        std::vector<PausePtr> callbackFuncs;

        //call back functions
        void resumePlay();
        void switchToMenu();
};

#endif // PAUSESTATE_H
