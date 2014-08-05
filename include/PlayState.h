#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameStateABC.h"

#include "GameObjectABC.h"
#include "GameObject.h"

#include <vector>

class PlayState : public GameStateABC
{
    public:
        PlayState();
        ~PlayState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        const std::string& getStateID() const {return playID; }

    private:
        static const std::string playID;

        //container for game objects
        std::vector<GameObjectABC*> gameObjects;

        //call back functions
        void switchToPause();
        void switchToGameOver();

        bool checkCollision(GameObject* p1, GameObject* p2) const;
};

#endif // PLAYSTATE_H
