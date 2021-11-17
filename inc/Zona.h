#ifndef UNTITLED_ZONA_H
#define UNTITLED_ZONA_H

#include "utils.h"
#include "Edificio.h"
#include "Trabalhador.h"

class Trabalhador;
class Edificio;

class Zona {
protected:
    int posX, posY;
    string tipo;

    Edificio edif;
    vector<Trabalhador*> empreg;


public:
    Zona(string t, int px, int py) : tipo(t), posX(px), posY(py) {}

    int getPosX();
    void setPosX(int pos);

    int getPosY();
    void setPosY(int pos);

    string getTipo();
    void setTipo();

    string getEdif();

    void construirEdificio(string nome);

};


/*
 *
 *
 *
 */

class Deserto : public Zona{

};

class Pastagem : public Zona{

};

class Floresta : public Zona{

};

class Montanha : public Zona{

};

class Pantano : public Zona{

};

class Zona_X : public Zona{

};

#endif //UNTITLED_ZONA_H
