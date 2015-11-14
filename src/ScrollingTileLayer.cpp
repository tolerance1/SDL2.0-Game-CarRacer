#include "ScrollingTileLayer.h"

#include <iostream>
using std::cout;
using std::endl;

ScrollingTileLayer::ScrollingTileLayer(int tileSize, const std::vector<Tileset>& tilesets)
: TileLayer(tileSize, tilesets)
{
    cout << " 32 C ScrollingTileLayer" << endl;

    gameWidth = numColumns * tile.size;
    gameHeight = numRows * tile.size;
}

ScrollingTileLayer::~ScrollingTileLayer()
{
    cout << " 32 D ScrollingTileLayer" << endl;
}

void ScrollingTileLayer::update()
{
    TileLayer::update();

    //reset viewports
    if(position.getX() >= gameWidth)
    {
        position.setX(0);
    }

    //make left viewport smaller
    leftViewport.x = 0;
    leftViewport.y = 0;
    leftViewport.w = gameWidth - position.getX();
    leftViewport.h = gameHeight;

    //make right viewport larger
    rightViewport.x = leftViewport.x + leftViewport.w;
    rightViewport.y = 0;
    rightViewport.w = gameWidth - leftViewport.w;
    rightViewport.h = gameHeight;
}

void ScrollingTileLayer::render()
{
    //draw within left viewport
    SDL_RenderSetViewport(pRenderer, &leftViewport);
    numColumns = leftViewport.w / tile.size;//draw just enough of tile columns
    TileLayer::render();

    //draw within right viewport
    SDL_RenderSetViewport(pRenderer, &rightViewport);
    numColumns = rightViewport.w / tile.size;
    float restore = position.getX();
    position.setX(0);//reset displacement
    TileLayer::render();
    position.setX(restore);//restore displacement

    //set the default viewport
    SDL_RenderSetViewport(pRenderer, NULL);
}
