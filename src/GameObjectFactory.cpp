#include "GameObjectFactory.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
GameObjectFactory* GameObjectFactory::pGameObjectFactory = nullptr;

GameObjectFactory* GameObjectFactory::getpGameObjectFactory()
{
    if(pGameObjectFactory == nullptr)
    {
        pGameObjectFactory = new GameObjectFactory();
        return pGameObjectFactory;
    }

    return pGameObjectFactory;
}

GameObjectFactory::GameObjectFactory()
{
    cout << " 17 C GameObjectFactory" << endl;
}

GameObjectFactory::~GameObjectFactory()
{
    cout << " 17 D GameObjectFactory" << endl;

    //release the object creators
    while(! creatorUMAP.empty())
    {
        delete creatorUMAP.begin()->second;//deletes the object creator pointed to
        creatorUMAP.erase(creatorUMAP.begin());
    }
}

bool GameObjectFactory::registerType(std::string typeID, ObjectCreatorABC* pCreator)
{
    auto Iterator = creatorUMAP.find(typeID);

    if(Iterator != creatorUMAP.cend())
    {
        delete pCreator;
        return false;//type already exists
    }

    creatorUMAP[typeID] = pCreator;//map string to creator
    return true;
}

GameObjectABC* GameObjectFactory::createObject(std::string typeID)
{
    auto Iterator = creatorUMAP.find(typeID);

    if(Iterator == creatorUMAP.cend())
       return nullptr;//type does not exist

    ObjectCreatorABC* pCreator = (*Iterator).second;
    return pCreator->createGameObject();
}
