#include "StateParser.h"

#include "TextureManager.h"
#include "Game.h"
#include "GameObjectFactory.h"

#include <iostream>
using std::cout;
using std::endl;

StateParser::StateParser()
{
    cout << " 23 C StateParser" << endl;
}

StateParser::~StateParser()
{
    cout << " 23 D StateParser" << endl;
}

bool StateParser::parseState(const char* stateFile, std::string stateID,
                             std::vector<std::string> *pTextureIDs,
                             std::vector<GameObjectABC*> *pGameObjects)
{
    //create the XML document
    TiXmlDocument xmlDoc;

    //load the state file
    if(! xmlDoc.LoadFile(stateFile))
    {
        cout << xmlDoc.ErrorDesc() << endl;
        return false;
    }

    //get the document root element
    TiXmlElement* pRoot = xmlDoc.RootElement();


    //to store the game state's root node
    TiXmlElement* pStateRoot = nullptr;

    //find the state's root node and store it
    for(TiXmlElement* elem = pRoot->FirstChildElement();
        elem != nullptr;
        elem = elem->NextSiblingElement())
    {
        if(elem->ValueStr() == stateID)
        {
            pStateRoot = elem;//found the game state's root node
        }
    }


    //to store the textures' root node
    TiXmlElement* pTexturesRoot = nullptr;

    //find the textures' root node and store it
    for(TiXmlElement* elem = pStateRoot->FirstChildElement();
        elem != nullptr;
        elem = elem->NextSiblingElement())
    {
        if(elem->ValueStr() == "TEXTURES")
        {
            pTexturesRoot = elem;//found the textures' root node
        }
    }

    //parse the textures
    parseTextures(pTexturesRoot, pTextureIDs);


    //to store the objects' root node
    TiXmlElement* pObjectsRoot = nullptr;

    //find the objects' root node and store it
    for(TiXmlElement* elem = pStateRoot->FirstChildElement();
        elem != nullptr;
        elem = elem->NextSiblingElement())
    {
        if(elem->ValueStr() == "OBJECTS")
        {
            pObjectsRoot = elem;//found the objects' root node
        }
    }

    //parse the objects
    parseObjects(pObjectsRoot, pGameObjects);


    return true;
}

void StateParser::parseTextures(TiXmlElement* pTexturesRoot,
                                std::vector<std::string> *pTextureIDs)
{
    //process all texture nodes
    for(TiXmlElement* elem = pTexturesRoot->FirstChildElement();
        elem != nullptr;
        elem = elem->NextSiblingElement())
    {
        //store the value of the node's each attribute
        std::string filename = elem->Attribute("filename");
        std::string textureID = elem->Attribute("textureID");

        //bookkeep the texture ID
        pTextureIDs->push_back(textureID);

        //create texture
        TextureManager::getpTextureManager()->createTexture(filename,
                                                            textureID,
                                                            Game::getpGame()->getpRenderer());
    }
}

void StateParser::parseObjects(TiXmlElement* pObjectsRoot,
                               std::vector<GameObjectABC*> *pGameObjects)
{
    //process all object nodes
    for(TiXmlElement* elem = pObjectsRoot->FirstChildElement();
        elem != nullptr;
        elem = elem->NextSiblingElement())
    {
        //object parameters placeholders
        std::string textureID;
        int destX = 0, destY = 0;
        int width = 0, height = 0;
        int currentRow = 0, currentFrame = 0;
        int numFrames = 1;
        int callbackID = 0;

        //store the value of the node's each attribute
        textureID = elem->Attribute("textureID");
        elem->Attribute("destX", &destX);
        elem->Attribute("destY", &destY);
        elem->Attribute("width", &width);
        elem->Attribute("height", &height);
        elem->Attribute("currentRow", &currentRow);
        elem->Attribute("currentFrame", &currentFrame);
        elem->Attribute("numFrames", &numFrames);
        elem->Attribute("callbackID", &callbackID);

        //create object
        GameObjectABC* pObject =
        GameObjectFactory::getpGameObjectFactory()->createObject(elem->Attribute("type"));

        //set dummy object parameters
        pObject->initObject(new SetObjectParams(textureID,
                                                destX, destY,
                                                width, height,
                                                currentRow, currentFrame,
                                                numFrames, callbackID));

        //push object into game state container
        pGameObjects->push_back(pObject);
    }
}
