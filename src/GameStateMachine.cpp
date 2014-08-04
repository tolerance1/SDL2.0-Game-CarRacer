#include "GameStateMachine.h"

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
    if(bPendingChanges)
    {
        applyPendingChanges();
        bPendingChanges = false;
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
        ( static_cast<MenuState*>(getGameStates().top()) ->* pMenuCallBack )();
        return;
    }
    if(StateID == "PLAY")
    {
        ( static_cast<PlayState*>(getGameStates().top()) ->* pPlayCallBack )();
        return;
    }
    if(StateID == "PAUSE")
    {
        ( static_cast<PauseState*>(getGameStates().top()) ->* pPauseCallBack )();
        return;
    }
    if(StateID == "GAMEOVER")
    {
        ( static_cast<GameOverState*>(getGameStates().top()) ->* pGOverCallBack )();
        return;
    }
}
