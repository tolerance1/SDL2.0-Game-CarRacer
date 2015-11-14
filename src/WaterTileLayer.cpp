#include "WaterTileLayer.h"

#include <iostream>
using std::cout;
using std::endl;

WaterTileLayer::WaterTileLayer(int tileSize, const std::vector<Tileset>& tilesets)
: ScrollingTileLayer(tileSize, tilesets)
{
    cout << " 33 C WaterTileLayer" << endl;
}

WaterTileLayer::~WaterTileLayer()
{
    cout << " 33 D WaterTileLayer" << endl;
}

void WaterTileLayer::update()
{
    ScrollingTileLayer::update();

    velocity.setX(0.25);
}

void WaterTileLayer::render()
{
    ScrollingTileLayer::render();
}
