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

        std::string getStateID() const {return menuID; }

    private:
        static const std::string menuID;
};

#endif // MENUSTATE_H
