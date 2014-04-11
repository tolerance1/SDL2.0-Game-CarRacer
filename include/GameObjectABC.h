#ifndef GAMEOBJECTABC_H
#define GAMEOBJECTABC_H


class GameObjectABC
{
    public:
        GameObjectABC();
        virtual ~GameObjectABC();

        virtual void drawObject() = 0;
        virtual void updateObjectParams() = 0;
        virtual void clean() = 0;
};

#endif // GAMEOBJECTABC_H
