#ifndef SCROLLINGTILELAYER_H
#define SCROLLINGTILELAYER_H

#include "SDL.h"
#include "TileLayer.h"

class ScrollingTileLayer : public TileLayer
{
    public:
        ScrollingTileLayer(int tileSize, const std::vector<Tileset>& tilesets);
        ~ScrollingTileLayer();

        void update();
        void render();

    private:
        int gameWidth;//screen width in pixels
        int gameHeight;//screen height in pixels

        SDL_Rect leftViewport;
        SDL_Rect rightViewport;
};

#endif // SCROLLINGTILELAYER_H
