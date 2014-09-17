#include "GameStateABC.h"

#include "TextureManager.h"

#include <iostream>
using std::cout;
using std::endl;

GameStateABC::GameStateABC()
{
    cout << " 10 C GameStateABC" << endl;
}

GameStateABC::~GameStateABC()
{
    cout << " 10 D GameStateABC" << endl;

    //release game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        delete gameObjects[Index];
    }
}

bool GameStateABC::onExit()
{
    //release the state's textures
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        TextureManager::getpTextureManager()->destroyTexture(textureIDs[Index]);
    }

    return true;
}
