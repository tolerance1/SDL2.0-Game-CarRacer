#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameStateABC.h"

class MenuState : public GameStateABC
{
    public:
        MenuState();
        ~MenuState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return menuID; }

        void callFunction(size_t callbackID)
        {
            (this->*callbackFuncs[callbackID])();
        }

    private:
        typedef void (MenuState::*MenuPtr)();

        static const std::string menuID;

        //function pointers array
        std::vector<MenuPtr> callbackFuncs;

        //call back functions
        void switchToPlay();
        void exitFromGame();
};

#endif // MENUSTATE_H
