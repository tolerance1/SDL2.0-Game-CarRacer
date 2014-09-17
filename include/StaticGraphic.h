#ifndef STATICGRAPHIC_H
#define STATICGRAPHIC_H

#include "GameObject.h"

class StaticGraphic : public GameObject
{
    public:
        StaticGraphic();
        ~StaticGraphic();

        void drawObject();
        void updateObjectParams();
        void clean();

        void initObject(const SetObjectParams* pInput);

    private:
        bool bReleased;

        int callbackID;
};

#endif // STATICGRAPHIC_H
