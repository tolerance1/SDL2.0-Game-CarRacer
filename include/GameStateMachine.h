#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include "GameStateABC.h"

#include <stack>
#include <map>

namespace States
{
    enum ID {None, Menu, Play, Pause, Gameover};
}

class GameStateMachine
{
    public:
        GameStateMachine();
        ~GameStateMachine();

        void updateCurrentState();
        void renderCurrentState();

        const std::stack<GameStateABC*>& getGameStates() const {return gameStates; }

    private:
        //container for game states
        std::stack<GameStateABC*> gameStates;

        void pushState(GameStateABC* pState);//add a state
        void popState();//remove a state
        void changeState(GameStateABC* pState);//remove all and add a state

    public:
        void requestStackPush(States::ID stateID);
        void requestStackPop();
        void requestStackChange(States::ID stateID);

    private:
        enum Action {Push, Pop, Change};

        class PendingChange
        {
            public:
                PendingChange(Action action, States::ID stateID = States::None);
                ~PendingChange();

                Action action;
                States::ID stateID;
        };

    private:
        typedef GameStateABC* (*pFunc)();

        std::vector<PendingChange> pendingList;
        std::map<States::ID, pFunc> stateFactory;

        template <typename T>
        void registerState(States::ID stateID);

        GameStateABC* createState(States::ID stateID);

        void applyPendingChanges();
};

template <typename T>
void GameStateMachine::registerState(States::ID stateID)
{
    auto Iterator = stateFactory.find(stateID);

    if(Iterator != stateFactory.cend())
    {
        return;//state already exists
    }

    //map an int to a creator functor
    stateFactory[stateID] = [] () -> GameStateABC* {return new T(); };
}

#endif // GAMESTATEMACHINE_H
