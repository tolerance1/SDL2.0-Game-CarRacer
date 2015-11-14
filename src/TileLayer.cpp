#include "TileLayer.h"

#include "Game.h"
#include "TextureManager.h"

#include <iostream>
using std::cout;
using std::endl;

TileLayer::TileLayer(int tileSize, const std::vector<Tileset>& tilesets)
: tilesets(tilesets), tile(Tile(tileSize))
{
    cout << " 27 C TileLayer" << endl;

    numColumns = (Game::getpGame()->getGameWidth() / tile.size);
    numRows = (Game::getpGame()->getGameHeight() / tile.size);

    pRenderer = Game::getpGame()->getpRenderer();
}

TileLayer::~TileLayer()
{
    cout << " 27 D TileLayer" << endl;
}

void TileLayer::update()
{
    position += velocity;
}

void TileLayer::render()
{
    int x = 0, y = 0, x2 = 0, y2 = 0;//used for map scrolling

    x = position.getX() / tile.size;//map viewport displacement in whole number of tiles
    y = position.getY() / tile.size;

    x2 = int(position.getX()) % tile.size;//displacement remainder in pixels
    y2 = int(position.getY()) % tile.size;

    for(int i = 0; i < numRows; ++i)//draw only screen-worth of map's IDs
    {
        for(int j = 0; j < (numColumns + 1); ++j)//draw one extra column ahead
        {
            tile.id = tileIDs[i + y][j + x];//get the selected tile's id

            if(tile.id == 0)
            {
                continue;
            }

            const Tileset* tileset = getTilesetByID(tile.id);//get the tileset object that contains the id

            tile.destX = (j * tile.size) - x2;//place the tile on the screen
            tile.destY = (i * tile.size) - y2;

            //figure out the tile position on the tileset image (count tiles from zero)
            tile.idRow = (tile.id - tileset->firstGridID) / tileset->numColumns;
            tile.idCol = (tile.id - tileset->firstGridID) % tileset->numColumns;

            //for an animated tile
            if(tileset->animSpeed)
            {
                tile.idCol = (SDL_GetTicks() / tileset->animSpeed) % tileset->numColumns;
            }

            //draw a single tile
            TextureManager::getpTextureManager()->drawTexture(tileset->name,
                                                              tile.destX, tile.destY,
                                                              tile.size, tile.size,
                                                              tile.idRow, tile.idCol,
                                                              pRenderer,
                                                              tile.rotationAngle, tile.flip);
        }
    }
}

const Tileset* TileLayer::getTilesetByID(int tileID)
{
    for(size_t Index = 0; Index != tilesets.size(); ++Index)//search through all tilesets
    {
        if(Index < tilesets.size() - 1)//check if there is a one tileset ahead
        {
            if(tileID >= tilesets[Index].firstGridID &&
               tileID < tilesets[Index + 1].firstGridID)
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
