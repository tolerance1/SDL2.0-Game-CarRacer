#ifndef STATEPARSER_H
#define STATEPARSER_H

#include <vector>

#include "tinyxml.h"//added "#define TIXML_USE_STL" directive into the header
#include "GameObjectABC.h"

class StateParser
{
    public:
        StateParser();
        ~StateParser();

        bool parseState(const char* stateFile, std::string stateID,
                        std::vector<std::string> *pTextureIDs,
                        std::vector<GameObjectABC*> *pGameObjects);

    private:
        void parseTextures(TiXmlElement* pTexturesRoot,
                           std::vector<std::string> *pTextureIDs);

        void parseObjects(TiXmlElement* pObjectsRoot,
                          std::vector<GameObjectABC*> *pGameObjects);
};

#endif // STATEPARSER_H
