#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameStateABC.h"

class PlayState : public GameStateABC
{
    public:
        PlayState();
        ~PlayState();

        void update();
        void render();

        bool onEnter();
        bool onExit();

        std::string getStateID() const {return playID; }

    private:
        static const std::string playID;
};

#endif // PLAYSTATE_H
