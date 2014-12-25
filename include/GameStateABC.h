#ifndef GAMESTATEABC_H
#define GAMESTATEABC_H

#include <string>

#include "Level.h"

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

        virtual void callFunction(size_t callbackID) = 0;

    protected:
        Level* pLevel;//current game level

        //bookkeep the state's loaded textures
        std::vector<std::string> textureIDs;
};

#endif // GAMESTATEABC_H
