#ifndef TILESET_H
#define TILESET_H

#include <string>

class Tileset
{
    public:
        Tileset();
        ~Tileset();

        int firstGridID;
        int tileWidth;
        int tileHeight;
        int width;//tileset image width in pixels
        int height;//tileset image height in pixels
        int numColumns;//used to find a tile position
        std::string name;

        int animSpeed {0};//for an animated tile
};

#endif // TILESET_H
