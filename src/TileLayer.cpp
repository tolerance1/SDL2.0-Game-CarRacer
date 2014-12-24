#include "TileLayer.h"

#include "Game.h"
#include "TextureManager.h"

#include <iostream>
using std::cout;
using std::endl;

TileLayer::TileLayer(int tileSize, const std::vector<Tileset>& tilesets)
: tileSize(tileSize), tilesets(tilesets)
{
    cout << " 27 C TileLayer" << endl;

    numColumns = (Game::getpGame()->getGameWidth() / tileSize);
    numRows = (Game::getpGame()->getGameHeight() / tileSize);
}

TileLayer::~TileLayer()
{
    cout << " 27 D TileLayer" << endl;
}

void TileLayer::update()
{
    if(position.getX() == Game::getpGame()->getGameWidth())
    {
        position.setX(0);
    }

    position += velocity;
    velocity.setX(1);
}

void TileLayer::render()
{
    int x = 0, y = 0, x2 = 0, y2 = 0;//used for map scrolling

    x = position.getX() / tileSize;//map displacement in whole number of tiles
    y = position.getY() / tileSize;

    x2 = int(position.getX()) % tileSize;//displacement remainder
    y2 = int(position.getY()) % tileSize;

    for(int i = 0; i < numRows; ++i)//draw only screen-worth of map's IDs
    {
        for(int j = 0; j <= numColumns; ++j)//draw one extra column ahead
        {
            int id = tileIDs[i + y][j + x];

            if(id == 0)
            {
                continue;
            }

            const Tileset* tileset = getTilesetByID(id);

            int destX = (j * tileSize) - x2;
            int destY = (i * tileSize) - y2;
            int idRow = (id - tileset->firstGridID) / tileset->numColumns;//count tiles from zero
            int idCol = (id - tileset->firstGridID) % tileset->numColumns;
            double rotationAngle = 0;
            SDL_RendererFlip flip = SDL_FLIP_NONE;

            TextureManager::getpTextureManager()->drawTexture(tileset->name,
                                                              destX, destY,
                                                              tileSize, tileSize,
                                                              idRow, idCol,
                                                              Game::getpGame()->getpRenderer(),
                                                              rotationAngle, flip);
        }
    }
}

const Tileset* TileLayer::getTilesetByID(int tileID)
{
    for(size_t Index = 0; Index != tilesets.size(); ++Index)//search through all tilesets
    {
        if(Index < tilesets.size() - 1)//check if there is a one tileset ahead
        {
            if(tileID >= tilesets[Index].firstGridID && tileID < tilesets[Index + 1].firstGridID)
            {
                return &tilesets[Index];
            }
        }
        else
        {
            return &tilesets[Index];//return the last tileset
        }
    }

    cout << "The required tileset was not found, returning a null pointer" << endl;
    return nullptr;
}
