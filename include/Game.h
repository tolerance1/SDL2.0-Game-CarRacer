#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "GameObject.h"

#include <vector>

class Game
{
    public:
        ~Game();

        bool init();
        void getInput();
        void update();
        void render();
        void clean();

        SDL_Renderer* getpRenderer() const {return pRenderer; }
        bool getbRunning() const {return bRunning; }
        static Game* getpGame();//create a single instance

        bool& setbRunning() {return bRunning; }

    private:
        SDL_Window* pWindow;
        SDL_Renderer* pRenderer;
        bool bRunning;
        static Game* pGame;//pointer to the instance

        //container for game objects
        std::vector<GameObject*> gameObjects;

        Game();//default constructor
        Game(const Game& rhs);//copy constructor
        Game& operator=(const Game& rhs);//copy assignment operator
};

#endif // GAME_H
