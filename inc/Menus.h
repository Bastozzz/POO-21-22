#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include "utils.h"
#include "Edificio.h"
#include "Ilha.h"

class Menus {

public:
    Menus() {}

    int     menu();
    void    execFile(string nomefich, Ilha * i);
};

#endif //UNTITLED_MENU_H
