#ifndef LEVELPARSER_H
#define LEVELPARSER_H

#include <unordered_map>

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
        void parseTilesets(TiXmlElement* pTilesetRoot);

        void parseTileLayer(TiXmlElement* pLayerRoot);

        void parseObjectLayer(TiXmlElement* pObjectsRoot);

        void parseTextures(TiXmlElement* pTexturesRoot);

        void parseObject(TiXmlElement* pObjectNode,
                         ObjectLayer* pObjectLayer);

        int tileSize;
        int width;//map horizontal number of tiles
        int height;//map vertical number of tiles

    private:
        std::vector<std::string>* pTextureIDs;//pointer to game state textures
        CollisionManager* pCollisionManager;

    private:
        //pointers to level's attributes
        std::vector<Tileset>* pTilesets;
        std::vector<LayerABC*>* pLayers;

        typedef LayerABC* (*pFunc)(int, std::vector<Tileset>&);

        std::unordered_map<std::string, pFunc> layerFactory;

        template <typename T>
        void registerLayer(std::string layerName);

        LayerABC* createLayer(std::string layerName);
};

template <typename T>
void LevelParser::registerLayer(std::string layerName)
{
    auto Iterator = layerFactory.find(layerName);

    if(Iterator != layerFactory.cend())
    {
        return;//layer already exists
    }

    //map an int to a creator functor
    layerFactory[layerName] = [] (int par1, std::vector<Tileset>& par2) -> LayerABC* {return new T(par1, par2); };
}

#endif // LEVELPARSER_H
