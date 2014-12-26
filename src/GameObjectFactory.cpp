#include "GameObjectFactory.h"

#include "Button.h"
#include "Enemy.h"
#include "Player.h"
#include "StaticGraphic.h"

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

    registerType<Button>("Button");
    registerType<Enemy>("Enemy");
    registerType<Player>("Player");
    registerType<StaticGraphic>("StaticGraphic");
}

GameObjectFactory::~GameObjectFactory()
{
    cout << " 17 D GameObjectFactory" << endl;
}

GameObjectABC* GameObjectFactory::createObject(std::string typeID)
{
    auto Iterator = objectFactory.find(typeID);

    if(Iterator == objectFactory.cend())
    {
        return nullptr;//type does not exist
    }

    return Iterator->second();
}
