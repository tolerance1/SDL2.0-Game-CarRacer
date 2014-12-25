#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "GameStateMachine.h"

class Game
{
    public:
        ~Game();

        bool init();
        void getInput();
        void update();
        void render();
        void clean();

        GameStateMachine* getpGameStateMachine() const {return pGameStateMachine; }
        SDL_Renderer* getpRenderer() const {return pRenderer; }
        bool getbRunning() const {return bRunning; }
        int getGameWidth() const {return gameWidth; }
        int getGameHeight() const {return gameHeight; }
        static Game* getpGame();//create a single instance

        bool& setbRunning() {return bRunning; }

    private:
        bool bRunning;
        int gameWidth;
        int gameHeight;
        SDL_Window* pWindow;
        SDL_Renderer* pRenderer;
        GameStateMachine* pGameStateMachine;
        static Game* pGame;//pointer to the instance

        Game();//default constructor
        Game(const Game& rhs);//copy constructor
        Game& operator=(const Game& rhs);//copy assignment operator
};

#endif // GAME_H
