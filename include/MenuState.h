#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameStateABC.h"

#include "GameObjectABC.h"

#include <vector>

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

    private:
        static const std::string menuID;

        //container for game objects
        std::vector<GameObjectABC*> gameObjects;

        //call back functions
        void switchToPlay();
        void exitFromGame();
};

#endif // MENUSTATE_H
