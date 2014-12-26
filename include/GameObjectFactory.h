#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include <string>
#include <unordered_map>

#include "GameObjectABC.h"

class GameObjectFactory
{
    public:
        ~GameObjectFactory();

        GameObjectABC* createObject(std::string typeID);

        static GameObjectFactory* getpGameObjectFactory();//create a single instance

    private:
        static GameObjectFactory* pGameObjectFactory;//pointer to the instance

        typedef GameObjectABC* (*pFunc)();

        //container for object creators
        std::unordered_map<std::string, pFunc> objectFactory;

        template <typename T>
        void registerType(std::string typeID);

        GameObjectFactory();
        GameObjectFactory(const GameObjectFactory& rhs);
        GameObjectFactory& operator=(const GameObjectFactory& rhs);
};

template <typename T>
void GameObjectFactory::registerType(std::string typeID)
{
    auto Iterator = objectFactory.find(typeID);

    if(Iterator != objectFactory.cend())
    {
        return;//type already exists
    }

    //map a string to a creator functor
    objectFactory[typeID] = [] () -> GameObjectABC* {return new T(); };
}

#endif // GAMEOBJECTFACTORY_H
