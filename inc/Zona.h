#ifndef UNTITLED_ZONA_H
#define UNTITLED_ZONA_H

#include "utils.h"
#include "Edificio.h"
#include "Trabalhador.h"

class Trabalhador;
class Edificio;

class Zona {
protected:
    string tipo;
    int posX, posY;
    Edificio edif;
    vector<Trabalhador> empreg;

public:
    Zona(string t, int px, int py) : tipo(t), posX(px), posY(py) {}

    void        construirEdificio(string nome);
    void        colocarTrabalhador(string nome, Trabalhador t);
    void        recolherRecurso(string nome);
    void        retirarTrabalhador(int pos);
    void        retirarEdificio(string nome, int pos);

    string      getTipo();
    string      getEdif();
    int         getNivel();

    Trabalhador copyTrab(int pos);
    int         getNTrab();
    string      getTrab();
    string      getTrabId(int pos);
    string      getTrabName(int pos);

    string      getRec();

    //Por implementar na meta 2
    int         getPosX();
    void        setPosX(int pos);
    int         getPosY();
    void        setPosY(int pos);
    void        setTipo();

};


class Deserto : public Zona{

};

class Pastagem : public Zona{

};

class Floresta : public Zona{

    //Armazenar recursos
};

class Montanha : public Zona{

};

class Pantano : public Zona{

};

class Zona_X : public Zona{

};

#endif //UNTITLED_ZONA_H
