#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include "GameStateABC.h"

#include <stack>

class GameStateMachine
{
    public:

        GameStateMachine();
        ~GameStateMachine();

        void pushState(GameStateABC* pState);//add a state
        void popState();//remove a state
        void changeState(GameStateABC* pState);//remove all and add a state

        void updateCurrentState();
        void renderCurrentState();

        const std::stack<GameStateABC*>& getGameStates() const {return gameStates; }

        void setCallbackID(int id) {callbackID = id; }

    private:
        //container for game states
        std::stack<GameStateABC*> gameStates;

        int callbackID;//index into function pointers array

        void applyPendingChanges();
};

#endif // GAMESTATEMACHINE_H
