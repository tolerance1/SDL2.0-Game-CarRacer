#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "GameStateABC.h"

#include "GameObjectABC.h"

#include <vector>

class PauseState : public GameStateABC
{
    public:
        PauseState();
        ~PauseState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return pauseID; }

    private:
        static const std::string pauseID;

        //container for game objects
        std::vector<GameObjectABC*> gameObjects;

        //call back functions
        void resumePlay();
        void switchToMenu();
};

#endif // PAUSESTATE_H
