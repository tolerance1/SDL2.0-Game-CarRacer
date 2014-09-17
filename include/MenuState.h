#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameStateABC.h"

class MenuState : public GameStateABC
{
    public:
        typedef void (MenuState::*MenuPtr)();

        MenuState();
        ~MenuState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return menuID; }
        const std::vector<MenuPtr>& getCallbackFuncs() const {return callbackFuncs; }

    private:
        static const std::string menuID;

        //function pointers array
        std::vector<MenuPtr> callbackFuncs;

        //call back functions
        void switchToPlay();
        void exitFromGame();
};

#endif // MENUSTATE_H
