#ifndef UNTITLED_EDIFICIO_H
#define UNTITLED_EDIFICIO_H

#include "utils.h"

class Edificio {
protected:
    string  nome;
    int     nivel;

public:
    Edificio(){};
    Edificio(string nom, int n) : nome(nom), nivel(n) {};

    string getNome();


    //Por implementar na meta 2
    void   setNivel(int n);
    int    getNivel() const;

};

/*
 *
 *
 *
 */

class MinaFerro : public Edificio {

public:
    MinaFerro(string nom = "mnF", int n = 1) : Edificio(nom, n)  {}

    string  getAsString() const;
};

#endif //UNTITLED_EDIFICIO_H
