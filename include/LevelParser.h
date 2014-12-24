#ifndef LEVELPARSER_H
#define LEVELPARSER_H

#include "tinyxml.h"//added "#define TIXML_USE_STL" directive into the header
#include "Level.h"
#include "ObjectLayer.h"
#include "CollisionManager.h"

class LevelParser
{
    public:
        LevelParser(std::vector<std::string>* pTextureIDs,
                    CollisionManager* pCollisionManager = nullptr);
        ~LevelParser();

        Level* parseLevel(const char* levelFile);

    private:
        void parseTilesets(TiXmlElement* pTilesetRoot,
                           std::vector<Tileset>* pTilesets);

        void parseTileLayer(TiXmlElement* pLayerRoot,
                            std::vector<LayerABC*>* pLayers,
                            const std::vector<Tileset>* pTilesets);

        void parseObjectLayer(TiXmlElement* pObjectsRoot,
                              std::vector<LayerABC*>* pLayers);

        void parseTextures(TiXmlElement* pTexturesRoot);

        void parseObject(TiXmlElement* pObjectNode,
                         ObjectLayer* pObjectLayer);

        int tileSize;
        int width;//map horizontal number of tiles
        int height;//map vertical number of tiles

    private:
        std::vector<std::string>* pTextureIDs;//pointer to game state textures
        CollisionManager* pCollisionManager;
};

#endif // LEVELPARSER_H
