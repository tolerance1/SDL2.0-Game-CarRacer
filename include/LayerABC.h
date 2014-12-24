#ifndef LAYERABC_H
#define LAYERABC_H

#include <vector>
#include <string>

class LayerABC
{
    public:
        LayerABC();
        virtual ~LayerABC();

        virtual void update() = 0;
        virtual void render() = 0;
};

#endif // LAYERABC_H
