#include "PlayState.h"

#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Button.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
const std::string PlayState::playID = "PLAY";

PlayState::PlayState()
{
    cout << " 12 C PlayState" << endl;
}

PlayState::~PlayState()
{
    cout << " 12 D PlayState" << endl;

    //release game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        delete gameObjects[Index];
    }
}

void PlayState::update()
{
    //update game objects destination coordinates and current frame
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->updateObjectParams();
    }

    for(size_t EnemyIndex = 1; EnemyIndex <= 2; ++EnemyIndex)
    {
        if(checkCollision(static_cast<GameObject*>(gameObjects[0]),
                          static_cast<GameObject*>(gameObjects[EnemyIndex])))
        {
            Game::getpGame()->getpGameStateMachine()->setbPendingChanges() = true;
            Game::getpGame()->getpGameStateMachine()->setpPlayCallBack() = &PlayState::switchToGameOver;
        }
    }
}

void PlayState::render()
{
    //draw game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->drawObject();
    }
}

bool PlayState::onEnter()
{
    //create textures
    if(! TextureManager::getpTextureManager()->createTexture("images/player_car_yellow.png",
                                                             "player_car_yellow",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;//don't start the loop
    }
    if(! TextureManager::getpTextureManager()->createTexture("images/traffic_car_blue.png",
                                                             "traffic_car_blue",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;
    }
    if(! TextureManager::getpTextureManager()->createTexture("images/traffic_car_orange.png",
                                                             "traffic_car_orange",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;
    }
    if(! TextureManager::getpTextureManager()->createTexture("images/play_button_pause.png",
                                                             "play_button_pause",
                                                             Game::getpGame()->getpRenderer()) )
    {
        return false;
    }

    //create objects and push them into container
    gameObjects.push_back(new Player(new SetObjectParams("player_car_yellow", 0, 200, 80, 45, 0, 0, 2), &PlayState::switchToGameOver));
    gameObjects.push_back(new Enemy(new SetObjectParams("traffic_car_blue", 0, 100, 80, 45, 0, 0, 2)));
    gameObjects.push_back(new Enemy(new SetObjectParams("traffic_car_orange", 0, 300, 80, 45, 0, 0, 2)));
    gameObjects.push_back(new Button(new SetObjectParams("play_button_pause", 0, 0, 45, 45, 0, 0), &PlayState::switchToPause));

    cout << "entering PlayState" << endl;
    return true;
}

bool PlayState::onExit()
{
    TextureManager::getpTextureManager()->destroyTexture("player_car_yellow");
    TextureManager::getpTextureManager()->destroyTexture("traffic_car_blue");
    TextureManager::getpTextureManager()->destroyTexture("traffic_car_orange");
    TextureManager::getpTextureManager()->destroyTexture("play_button_pause");

    cout << "exiting PlayState" << endl;
    return true;
}

void PlayState::switchToPause()
{
    Game::getpGame()->getpGameStateMachine()->pushState(new PauseState());
}

void PlayState::switchToGameOver()
{
    Game::getpGame()->getpGameStateMachine()->pushState(new GameOverState());
}

bool PlayState::checkCollision(GameObject* p1, GameObject* p2) const
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = p1->getPosition().getX();
    rightA = p1->getPosition().getX() + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = p1->getPosition().getY() + p1->getHeight();

    leftB = p2->getPosition().getX();
    rightB = p2->getPosition().getX() + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = p2->getPosition().getY() + p2->getHeight();

    if( bottomA <= topB ){return false; }
    if( topA >= bottomB ){return false; }
    if( rightA <= leftB ){return false; }
    if( leftA >= rightB ){return false; }

    return true;
}
