#include "GameStateABC.h"

#include"TextureManager.h"

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

    //release the level object
    delete pLevel;
}

bool GameStateABC::onExit()
{
    //release the state's textures
    for(size_t Index = 0; Index != textureIDs.size(); ++Index)
    {
        TextureManager::getpTextureManager()->destroyTexture(textureIDs[Index]);
    }

    return true;
}
