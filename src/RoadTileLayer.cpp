#include "RoadTileLayer.h"

#include <iostream>
using std::cout;
using std::endl;

RoadTileLayer::RoadTileLayer(int tileSize, const std::vector<Tileset>& tilesets)
: ScrollingTileLayer(tileSize, tilesets)
{
    cout << " 34 C RoadTileLayer" << endl;
}

RoadTileLayer::~RoadTileLayer()
{
    cout << " 34 D RoadTileLayer" << endl;
}

void RoadTileLayer::update()
{
    ScrollingTileLayer::update();

    velocity.setX(1);
}

void RoadTileLayer::render()
{
    ScrollingTileLayer::render();
}
