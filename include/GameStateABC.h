#ifndef GAMESTATEABC_H
#define GAMESTATEABC_H

#include <string>
#include <vector>

#include "GameObjectABC.h"

class GameStateABC
{
    public:
        GameStateABC();
        virtual ~GameStateABC();

        virtual void update() = 0;
        virtual void render() = 0;

        virtual bool onEnter() = 0;
        virtual bool onExit() = 0;

        virtual const std::string& getStateID() const = 0;

    protected:
        //bookkeep the state's loaded textures
        std::vector<std::string> textureIDs;

        //container for game objects
        std::vector<GameObjectABC*> gameObjects;
};

#endif // GAMESTATEABC_H
