#ifndef ROADTILELAYER_H
#define ROADTILELAYER_H

#include "ScrollingTileLayer.h"

class RoadTileLayer : public ScrollingTileLayer
{
    public:
        RoadTileLayer(int tileSize, const std::vector<Tileset>& tilesets);
        ~RoadTileLayer();

        void update();
        void render();
};

#endif // ROADTILELAYER_H
