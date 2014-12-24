#ifndef TILELAYER_H
#define TILELAYER_H

#include "LayerABC.h"

#include "Tileset.h"
#include "Vector2D.h"

class TileLayer : public LayerABC
{
    public:
        TileLayer(int tileSize, const std::vector<Tileset>& tilesets);
        ~TileLayer();

        void update();
        void render();

        const Tileset* getTilesetByID(int tileID);

        void setTileIDs(const std::vector<std::vector<int>>& data) {tileIDs = data; }
        void setTileSize(int data) {tileSize = data; }

    private:
        int numColumns;//screen width in tiles
        int numRows;//screen height in tiles
        int tileSize;

        Vector2D position;//layer's position
        Vector2D velocity;

        const std::vector<Tileset>& tilesets;//reference to Level's all tilesets
        std::vector<std::vector<int>> tileIDs;//own map of tile IDs
};

#endif // TILELAYER_H
