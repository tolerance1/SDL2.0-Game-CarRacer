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
    if(! gameStates.empty())
    {
        if(gameStates.top()->getStateID() == pState->getStateID())
        {
            return;//do nothing
        }

        //pop current state
        if(gameStates.top()->onExit())
        {
            delete gameStates.top();
            gameStates.pop();
        }

        //add new state
        gameStates.push(pState);
        gameStates.top()->onEnter();
    }
}

void GameStateMachine::updateCurrentState()
{
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
