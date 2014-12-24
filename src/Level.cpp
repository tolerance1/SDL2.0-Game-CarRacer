#include "Level.h"

#include <iostream>
using std::cout;
using std::endl;

Level::Level()
{
    cout << " 24 C Level" << endl;
}

Level::~Level()
{
    cout << " 24 D Level" << endl;

    //release layer objects
    for(size_t Index = 0; Index != layers.size(); ++Index)
    {
        delete layers[Index];
    }
}

void Level::update()
{
    for(size_t Index = 0; Index != layers.size(); ++Index)
    {
        layers[Index]->update();
    }
}

void Level::render()
{
    for(size_t Index = 0; Index != layers.size(); ++Index)
    {
        layers[Index]->render();
    }
}
