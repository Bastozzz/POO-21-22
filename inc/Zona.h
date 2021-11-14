#ifndef UNTITLED_ZONA_H
#define UNTITLED_ZONA_H

#include "utils.h"

class Zona {
protected:
    //int posX, posY;
    vector<int, int> = {posX, posY};

public:
    Zona(int px, int py) : posX(px), posY(py) {}

    int getPosX();
    void setPosX(int pos);

    int getPosY();
    void setPosY(int pos);

};

#endif //UNTITLED_ZONA_H
