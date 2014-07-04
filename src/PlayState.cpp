#include "PlayState.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
const std::string PlayState::playID = "PLAY";

PlayState::PlayState()
{
    cout << " 12 C PlayState" << endl;
}

PlayState::~PlayState()
{
    cout << " 12 D PlayState" << endl;
}

void PlayState::update()
{

}

void PlayState::render()
{

}

bool PlayState::onEnter()
{
    cout << " entering PlayState" << endl;
    return true;
}

bool PlayState::onExit()
{
    cout << " exiting PlayState" << endl;
    return true;
}
