#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameStateABC.h"

class GameOverState : public GameStateABC
{
    public:
        typedef void (GameOverState::*GOverPtr)();

        GameOverState();
        ~GameOverState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return gameOverID; }
        const std::vector<GOverPtr>& getCallbackFuncs() const {return callbackFuncs; }

    private:
        static const std::string gameOverID;

        //function pointers array
        std::vector<GOverPtr> callbackFuncs;

        //call back functions
        void restartPlay();
        void switchToMenu();
};

#endif // GAMEOVERSTATE_H
