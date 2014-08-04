#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameStateABC.h"

#include "GameObjectABC.h"

#include <vector>

class GameOverState : public GameStateABC
{
    public:
        GameOverState();
        ~GameOverState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return gameOverID; }

    private:
        static const std::string gameOverID;

        //container for game objects
        std::vector<GameObjectABC*> gameObjects;

        //call back functions
        void restartPlay();
        void switchToMenu();
};

#endif // GAMEOVERSTATE_H
