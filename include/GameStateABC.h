#ifndef GAMESTATEABC_H
#define GAMESTATEABC_H

#include <string>

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
};

#endif // GAMESTATEABC_H
