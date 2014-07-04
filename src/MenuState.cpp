#include "MenuState.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
const std::string MenuState::menuID = "MENU";

MenuState::MenuState()
{
    cout << " 11 C MenuState" << endl;
}

MenuState::~MenuState()
{
    cout << " 11 D MenuState" << endl;
}

void MenuState::update()
{

}

void MenuState::render()
{

}

bool MenuState::onEnter()
{
    cout << " entering MenuState" << endl;
    return true;
}

bool MenuState::onExit()
{
    cout << " exiting MenuState" << endl;
    return true;
}


