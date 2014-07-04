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
        void changeState(GameStateABC* pState);//remove first and add a state

        void updateCurrentState();
        void renderCurrentState();

        const std::stack<GameStateABC*>& getGameStates() const {return gameStates; }

    private:
        //container for game states
        std::stack<GameStateABC*> gameStates;
};

#endif // GAMESTATEMACHINE_H
