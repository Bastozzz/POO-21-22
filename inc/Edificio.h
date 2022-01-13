#ifndef UNTITLED_EDIFICIO_H
#define UNTITLED_EDIFICIO_H

#include "utils.h"

class Edificio {
protected:
    string  nome;
    int     nivel;
    bool ligaEdificio;

public:
    Edificio(){};
    Edificio(string nom, int n) : nome(nom), nivel(n) {};

    string getNome();

    //Por implementar na meta 2
    void   setNivel(int n);
    int    getNivel() const;

    string  getAsString() const;

    int liga();
    int desliga();

};

/*
 *
 *
 *
 */

//Subclasses

class MinaFerro : public Edificio {
public:
    MinaFerro(string nom = "mnF", int n = 1) : Edificio(nom, n)  {}

};

class MinaCarvao : public Edificio {
public:
    MinaCarvao(string nom = "mnC", int n = 1) : Edificio(nom, n)  {}

};

class CentralEletrica : public Edificio {
public:
    CentralEletrica(string nom = "cEl", int n = 1) : Edificio(nom, n)  {}

};

class Bateria : public Edificio {
public:
    Bateria(string nom = "bat", int n = 1) : Edificio(nom, n)  {}

};

class Fundicao : public Edificio {
public:
    Fundicao(string nom = "fun", int n = 1) : Edificio(nom, n)  {}

};

#endif //UNTITLED_EDIFICIO_H
