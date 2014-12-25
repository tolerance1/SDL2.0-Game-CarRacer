#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameStateABC.h"

class GameOverState : public GameStateABC
{
    public:
        GameOverState();
        ~GameOverState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return gameOverID; }

        void callFunction(size_t callbackID)
        {
            (this->*callbackFuncs[callbackID])();
        }

    private:
        typedef void (GameOverState::*GOverPtr)();

        static const std::string gameOverID;

        //function pointers array
        std::vector<GOverPtr> callbackFuncs;

        //call back functions
        void restartPlay();
        void switchToMenu();
};

#endif // GAMEOVERSTATE_H
