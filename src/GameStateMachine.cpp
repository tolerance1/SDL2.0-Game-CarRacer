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
}

GameStateMachine::~GameStateMachine()
{
    cout << " 13 D GameStateMachine" << endl;

    //release game states objects
    while(! gameStates.empty())
    {
        delete gameStates.top();
        gameStates.pop();
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

void GameStateMachine::updateCurrentState()
{
    if(callbackID)
    {
        applyPendingChanges();
        callbackID = 0;
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

void GameStateMachine::applyPendingChanges()
{
    const std::string& StateID = getGameStates().top()->getStateID();

    if(StateID == "MENU")
    {
        MenuState* pState = static_cast<MenuState*>(getGameStates().top());

        ( pState ->* (pState->getCallbackFuncs()[callbackID]) )();
        return;
    }
    if(StateID == "PLAY")
    {
        PlayState* pState = static_cast<PlayState*>(getGameStates().top());

        ( pState ->* (pState->getCallbackFuncs()[callbackID]) )();
        return;
    }
    if(StateID == "PAUSE")
    {
        PauseState* pState = static_cast<PauseState*>(getGameStates().top());

        ( pState ->* (pState->getCallbackFuncs()[callbackID]) )();
        return;
    }
    if(StateID == "GAMEOVER")
    {
        GameOverState* pState = static_cast<GameOverState*>(getGameStates().top());

        ( pState ->* (pState->getCallbackFuncs()[callbackID]) )();
        return;
    }
}
