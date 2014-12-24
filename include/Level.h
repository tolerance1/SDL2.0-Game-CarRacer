#ifndef LEVEL_H
#define LEVEL_H

#include "Tileset.h"
#include "LayerABC.h"

#include <vector>

class Level
{
    public:
        ~Level();

        void update();
        void render();

        std::vector<Tileset>* getTilesets() {return &tilesets; }
        std::vector<LayerABC*> *getLayers() {return &layers; }

    private:
        Level();//invoked by LevelParser
        friend class LevelParser;

        std::vector<Tileset> tilesets;
        std::vector<LayerABC*> layers;
};

#endif // LEVEL_H
