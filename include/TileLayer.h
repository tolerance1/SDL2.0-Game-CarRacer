#ifndef TILELAYER_H
#define TILELAYER_H

#include "LayerABC.h"

#include "SDL.h"
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

    protected:
        int numColumns;//screen width in tiles
        int numRows;//screen height in tiles

        Vector2D position;//layer's viewport position
        Vector2D velocity;

        const std::vector<Tileset>& tilesets;//reference to Level's all tilesets
        std::vector<std::vector<int>> tileIDs;//own map of tile IDs

    protected:
        SDL_Renderer* pRenderer;//layer's render target

        class Tile
        {
            public:
                Tile (int tileSize): size(tileSize) {}
                int size;
                int id {0};
                int destX {0};
                int destY {0};
                int idRow {0};
                int idCol {0};
                double rotationAngle {0};
                SDL_RendererFlip flip {SDL_FLIP_NONE};
        };

        Tile tile;//individual tile properties
};

#endif // TILELAYER_H
