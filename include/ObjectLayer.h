#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H

#include "LayerABC.h"

#include "GameObjectABC.h"

class ObjectLayer : public LayerABC
{
    public:
        ObjectLayer();
        ~ObjectLayer();

        void update();
        void render();

        std::vector<GameObjectABC*>* getGameObjects() {return &gameObjects; }

    private:
        //container for game objects
        std::vector<GameObjectABC*> gameObjects;
};

#endif // OBJECTLAYER_H
