#include "LevelParser.h"

#include "TextureManager.h"
#include "Game.h"
#include "Tileset.h"
#include "TileLayer.h"
#include "base64.h"
#include "zlib.h"
#include "GameObjectFactory.h"
#include "WaterTileLayer.h"
#include "RoadTileLayer.h"

#include <iostream>
using std::cout;
using std::endl;

LevelParser::LevelParser(std::vector<std::string>* pTextureIDs,
                         CollisionManager* pCollisionManager)
: pTextureIDs(pTextureIDs), pCollisionManager(pCollisionManager)
{
    cout << " 28 C LevelParser" << endl;

    registerLayer<WaterTileLayer>("Tile Layer Water");
    registerLayer<RoadTileLayer>("Tile Layer Road");
}

LevelParser::~LevelParser()
{
    cout << " 28 D LevelParser" << endl;
}

Level* LevelParser::parseLevel(const char* levelFile)
{
    //create the DOM object from XML document
    TiXmlDocument xmlDoc;

    //load the level file
    if(! xmlDoc.LoadFile(levelFile))
    {
        cout << xmlDoc.ErrorDesc() << endl;
        return nullptr;
    }

    //create the level object
    Level* pLevel = new Level();

    //store pointers to level's attributes
    pTilesets = pLevel->getTilesets();
    pLayers = pLevel->getLayers();

    //get the document root element
    TiXmlElement* pRoot = xmlDoc.RootElement();

    //store the tile and map dimensions
    pRoot->Attribute("tilewidth", &tileSize);
    pRoot->Attribute("width", &width);
    pRoot->Attribute("height", &height);

    //parse tilesets, tile layers and object layers
    for(TiXmlElement* elem = pRoot->FirstChildElement();
        elem != nullptr;
        elem = elem->NextSiblingElement())
    {
        if(elem->ValueStr() == "tileset")
        {
            parseTilesets(elem);
        }
        else if(elem->ValueStr() == "layer")
        {
            parseTileLayer(elem);
        }
        else if(elem->ValueStr() == "objectgroup")
        {
            parseObjectLayer(elem);
        }
    }

    return pLevel;
}

void LevelParser::parseTilesets(TiXmlElement* pTilesetRoot)
{
    //store the required values of the tileset node's attributes
    std::string filename = pTilesetRoot->FirstChildElement()->Attribute("source");
    std::string textureID = pTilesetRoot->Attribute("name");

    //bookkeep the tileset's texture ID
    pTextureIDs->push_back(textureID);

    //create a tileset texture
    TextureManager::getpTextureManager()->createTexture(filename,
                                                        textureID,
                                                        Game::getpGame()->getpRenderer());

    //create a tileset object
    Tileset tileset;

    //populate the tileset with data
    tileset.name = pTilesetRoot->Attribute("name");
    pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
    pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
    pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
    pTilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
    pTilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
    tileset.numColumns = tileset.width / tileset.tileWidth;
    pTilesetRoot->Attribute("animSpeed", &tileset.animSpeed);

    pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement* pLayerRoot)
{
    LayerABC* pTileLayer = createLayer(pLayerRoot->Attribute("name"));

    //create an empty tile IDs map
    std::vector<std::vector<int>> tileData;

    TiXmlElement* pDataNode;//to store the data node
    std::string decodedIDs;//to store the decoded string of data node

    //find the data node and store it
    for(TiXmlElement* elem = pLayerRoot->FirstChildElement();
        elem != nullptr;
        elem = elem->NextSiblingElement())
    {
        if(elem->ValueStr() == "data")
        {
            pDataNode = elem;
        }
    }

    //find the encoded data string
    for(TiXmlNode* elem = pDataNode->FirstChild();
        elem != nullptr;
        elem = elem->NextSibling())
    {
        TiXmlText* text = elem->ToText();//downcast TiXmlNode* to TiXmlText*
        std::string encoded = text->ValueStr();//store the encoded string
        decodedIDs = base64_decode(encoded);
    }

    //uncompress zlib compression
                                                    //the total size of the destination buffer
    uLongf sizeofids = width * height * sizeof(int);//number of bytes occupied by IDs

    std::vector<int> ids(width * height);//destination for uncompressed data

                //dest         //destLen   //source                          //the byte length of the source buffer
    uncompress((Bytef*)&ids[0], &sizeofids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());

    std::vector<int> layerRow(width);//horizontal count of tiles

    for(int Index = 0; Index != height; ++Index)//resize the tile id matrix
    {
        tileData.push_back(layerRow);
    }

    for(int Row = 0; Row < height; ++Row)//populate matrix with decoded ids
    {
        for(int Col = 0; Col < width; ++Col)
        {
            tileData[Row][Col] = ids[Row * width + Col];
        }
    }

    static_cast<TileLayer*>(pTileLayer)->setTileIDs(tileData);//move the tile IDs map

    pLayers->push_back(pTileLayer);
}

void LevelParser::parseObjectLayer(TiXmlElement* pObjectsRoot)
{
    //create an object layer
    ObjectLayer* pObjectLayer = new ObjectLayer();

    //parse textures and objects
    for(TiXmlElement* elem = pObjectsRoot->FirstChildElement();
        elem != nullptr;
        elem = elem->NextSiblingElement())
    {
        if(elem->ValueStr() == "properties")
        {
            parseTextures(elem);
        }
        else if(elem->ValueStr() == "object")
        {
            parseObject(elem, pObjectLayer);
        }
    }

    pLayers->push_back(pObjectLayer);
}

void LevelParser::parseTextures(TiXmlElement* pTexturesRoot)
{
    //process all texture nodes
    for(TiXmlElement* elem = pTexturesRoot->FirstChildElement();
        elem != nullptr;
        elem = elem->NextSiblingElement())
    {
        //store the value of the node's each attribute
        std::string filename = elem->Attribute("value");
        std::string textureID = elem->Attribute("name");

        //bookkeep the object's texture ID
        pTextureIDs->push_back(textureID);

        //create texture
        TextureManager::getpTextureManager()->createTexture(filename,
                                                            textureID,
                                                            Game::getpGame()->getpRenderer());
    }
}

void LevelParser::parseObject(TiXmlElement* pObjectNode,
                              ObjectLayer* pObjectLayer)
{
    //object parameters placeholders
    std::string textureID;
    int destX = 0, destY = 0;
    int width = 0, height = 0;
    int currentRow = 0, currentFrame = 0;
    int numFrames = 1, animSpeed = 1;
    int callbackID = 0;

    //store the values of the node's attributes
    textureID = pObjectNode->Attribute("name");
    pObjectNode->Attribute("x", &destX);
    pObjectNode->Attribute("y", &destY);
    pObjectNode->Attribute("width", &width);
    pObjectNode->Attribute("height", &height);

    //find the "properties" node
    for(TiXmlElement* elem = pObjectNode->FirstChildElement();
        elem != nullptr;
        elem = elem->NextSiblingElement())
    {
        if(elem->ValueStr() == "properties")
        {
            //find the "property" nodes
            for(TiXmlElement* property = elem->FirstChildElement();
                property != nullptr;
                property = property->NextSiblingElement())
            {
                if(property->ValueStr() == "property")
                {
                    if(property->Attribute("name") == std::string("callbackID"))
                    {
                        property->Attribute("value", &callbackID);
                    }
                    else if(property->Attribute("name") == std::string("currentFrame"))
                    {
                        property->Attribute("value", &currentFrame);
                    }
                    else if(property->Attribute("name") == std::string("currentRow"))
                    {
                        property->Attribute("value", &currentRow);
                    }
                    else if(property->Attribute("name") == std::string("numFrames"))
                    {
                        property->Attribute("value", &numFrames);
                    }
                    else if(property->Attribute("name") == std::string("animSpeed"))
                    {
                        property->Attribute("value", &animSpeed);
                    }

                }
            }
        }
    }

    //create object
    GameObjectABC* pObject =
    GameObjectFactory::getpGameObjectFactory()->createObject(pObjectNode->Attribute("type"));

    //set dummy object parameters
    pObject->initObject(new SetObjectParams(textureID,
                                            destX, destY,
                                            width, height,
                                            currentRow, currentFrame,
                                            numFrames, animSpeed,
                                            callbackID));

    if(pObjectNode->Attribute("type") == std::string("Player"))//store pointer to a Player
    {
        pCollisionManager->setpPlayer(static_cast<Player*>(pObject));
    }
    else if(pObjectNode->Attribute("type") == std::string("Enemy"))//store pointer to an Enemy
    {
        pCollisionManager->getEnemyList()->push_back(static_cast<GameObject*>(pObject));
    }

    //push object into layer's container
    pObjectLayer->getGameObjects()->push_back(pObject);
}

LayerABC* LevelParser::createLayer(std::string layerName)
{
    auto Iterator = layerFactory.find(layerName);

    if(Iterator != layerFactory.cend())
    {
        return Iterator->second(tileSize, *pTilesets);
    }

	return nullptr;//layer does not exist
}
