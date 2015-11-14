#ifndef WATERTILELAYER_H
#define WATERTILELAYER_H

#include "ScrollingTileLayer.h"

class WaterTileLayer : public ScrollingTileLayer
{
    public:
        WaterTileLayer(int tileSize, const std::vector<Tileset>& tilesets);
        ~WaterTileLayer();

        void update();
        void render();
};

#endif // WATERTILELAYER_H
