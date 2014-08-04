#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include "GameStateABC.h"
#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"

#include <stack>

class GameStateMachine
{
    public:
        typedef void (MenuState::*MenuPtr)();
        typedef void (PlayState::*PlayPtr)();
        typedef void (PauseState::*PausePtr)();
        typedef void (GameOverState::*GOverPtr)();

        GameStateMachine();
        ~GameStateMachine();

        void pushState(GameStateABC* pState);//add a state
        void popState();//remove a state
        void changeState(GameStateABC* pState);//remove all and add a state

        void updateCurrentState();
        void renderCurrentState();

        const std::stack<GameStateABC*>& getGameStates() const {return gameStates; }

        bool& setbPendingChanges() {return bPendingChanges; }
        MenuPtr& setpMenuCallBack() {return pMenuCallBack; }
        PlayPtr& setpPlayCallBack() {return pPlayCallBack; }
        PausePtr& setpPauseCallBack() {return pPauseCallBack; }
        GOverPtr& setpGOverCallBack() {return pGOverCallBack; }

    private:
        //container for game states
        std::stack<GameStateABC*> gameStates;

        union//save memory
        {
            MenuPtr pMenuCallBack;
            PlayPtr pPlayCallBack;
            PausePtr pPauseCallBack;
            GOverPtr pGOverCallBack;
        };

        bool bPendingChanges;

        void applyPendingChanges();
};

#endif // GAMESTATEMACHINE_H
