#include "ObjectLayer.h"

#include <iostream>
using std::cout;
using std::endl;

ObjectLayer::ObjectLayer()
{
    cout << " 29 C ObjectLayer" << endl;
}

ObjectLayer::~ObjectLayer()
{
    cout << " 29 D ObjectLayer" << endl;

    //release game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        delete gameObjects[Index];
    }
}

void ObjectLayer::update()
{
    //update game objects destination coordinates and current frame
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->updateObjectParams();
    }
}

void ObjectLayer::render()
{
    //draw game objects
    for(size_t Index = 0; Index != gameObjects.size(); ++Index)
    {
        gameObjects[Index]->drawObject();
    }
}
