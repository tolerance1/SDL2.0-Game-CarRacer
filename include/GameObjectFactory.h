#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include <string>
#include <unordered_map>

#include "ObjectCreatorABC.h"

class GameObjectFactory
{
    public:
        ~GameObjectFactory();

        GameObjectABC* createObject(std::string typeID);

        static GameObjectFactory* getpGameObjectFactory();//create a single instance

    private:
        static GameObjectFactory* pGameObjectFactory;//pointer to the instance

        //container for object creators
        std::unordered_map<std::string, ObjectCreatorABC*> creatorUMAP;

        void registerType(std::string typeID, ObjectCreatorABC* pCreator);

        GameObjectFactory();
        GameObjectFactory(const GameObjectFactory& rhs);
        GameObjectFactory& operator=(const GameObjectFactory& rhs);
};

#endif // GAMEOBJECTFACTORY_H
