#include "GameStateMachine.h"

#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"

#include <iostream>
using std::cout;
using std::endl;

GameStateMachine::GameStateMachine()
{
    cout << " 13 C GameStateMachine" << endl;

    registerState<MenuState>(States::Menu);
    registerState<PlayState>(States::Play);
    registerState<PauseState>(States::Pause);
    registerState<GameOverState>(States::Gameover);

    pushState(new MenuState());
}

GameStateMachine::~GameStateMachine()
{
    cout << " 13 D GameStateMachine" << endl;

    //release game state objects
    while(! gameStates.empty())
    {
        delete gameStates.top();
        gameStates.pop();
    }
}

GameStateMachine::PendingChange::PendingChange(Action action, States::ID stateID)
: action(action), stateID(stateID)
{
    cout << " 31 C PendingChange" << endl;
}

GameStateMachine::PendingChange::~PendingChange()
{
    cout << " 31 D PendingChange" << endl;
}

void GameStateMachine::updateCurrentState()
{
    if(! pendingList.empty())
    {
        applyPendingChanges();
    }

    if(! gameStates.empty())
    {
        gameStates.top()->update();
    }
}

void GameStateMachine::renderCurrentState()
{
    if(! gameStates.empty())
    {
        gameStates.top()->render();
    }
}

void GameStateMachine::pushState(GameStateABC* pState)
{
    gameStates.push(pState);
    gameStates.top()->onEnter();
}

void GameStateMachine::popState()
{
    if(! gameStates.empty())
    {
        if(gameStates.top()->onExit())
        {
            delete gameStates.top();//release the state object
            gameStates.pop();//remove the pointer
        }
    }
}

void GameStateMachine::changeState(GameStateABC* pState)
{
    //empty the stack
    while(! gameStates.empty())
    {
        if(gameStates.top()->onExit())
        {
            delete gameStates.top();
            gameStates.pop();
        }
    }

    //add new state
    gameStates.push(pState);
    gameStates.top()->onEnter();
}

void GameStateMachine::requestStackPush(States::ID stateID)
{
    pendingList.push_back(PendingChange(Push, stateID));
}

void GameStateMachine::requestStackPop()
{
    pendingList.push_back(PendingChange(Pop));
}

void GameStateMachine::requestStackChange(States::ID stateID)
{
    pendingList.push_back(PendingChange(Change, stateID));
}

GameStateABC* GameStateMachine::createState(States::ID stateID)
{
    auto Iterator = stateFactory.find(stateID);

    if(Iterator != stateFactory.cend())
    {
        return Iterator->second();
    }

	return nullptr;//state does not exist
}

void GameStateMachine::applyPendingChanges()
{
    for(size_t Index = 0; Index != pendingList.size(); ++Index)
    {
        PendingChange& change = pendingList[Index];

        switch(change.action)
        {
            case Push:
				pushState(createState(change.stateID));
				break;

			case Pop:
				popState();
				break;

			case Change:
				changeState(createState(change.stateID));
				break;
        }
    }

    pendingList.clear();
}
