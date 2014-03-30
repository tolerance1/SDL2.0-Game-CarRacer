#ifndef GAME_H
#define GAME_H

#include <iostream>
using std::cout;
using std::endl;

class Game
{
    public:
        ~Game() {cout << "_Game destructor" << endl;}

        bool init();
        void getInput();
        void update();
        void render();
        void clean();

        bool getbRunning() const {return bRunning;}
        static Game* getpGame();//create a single instance

    private:
        bool bRunning;
        static Game* pGame;//pointer to the instance

        Game(): bRunning(true) {cout << "_Game constructor" << endl;}//default constructor
        Game(const Game& rhs);//copy constructor
        Game& operator=(const Game& rhs);//copy assignment operator
};

#endif // GAME_H
