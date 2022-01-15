#ifndef UNTITLED_EDIFICIO_H
#define UNTITLED_EDIFICIO_H

#include "utils.h"

class Edificio {
protected:
    string  nome;
    int     nivel;
    bool    ligaEdificio;

public:
    Edificio(){};
    Edificio(string nom, int n) : nome(nom), nivel(n) {};

    string getNome();
    void setNome(string n);

    //Por implementar na meta 2
    void   setNivel(int n);
    int    getNivel() const;

    string  getAsString() const;

    int liga();
    int desliga();

};


//Subclasses

class MinaFerro : public Edificio {
    int maxFerro;
    int ferro;

public:
    MinaFerro(string nom = "mnF", int n = 1, int maxF = 100, int f = 0) : Edificio(nom, n), maxFerro(maxF), ferro(f)  {}
    void produzirF();

};

class MinaCarvao : public Edificio {
    int maxCarvao;
    int carvao;

public:
    MinaCarvao(string nom = "mnC", int n = 1, int maxC = 100, int c = 0) : Edificio(nom, n),  maxCarvao(maxC), carvao(c){}
    void produzirC();
};

class CentralEletrica : public Edificio {
    int maxCarvao;
    int carvao;

public:
    CentralEletrica(string nom = "cEl", int n = 1, int maxC = 100, int c = 0) : Edificio(nom, n), maxCarvao(maxC), carvao(c){}
    void produzirRecursos();
};

class Bateria : public Edificio {
    int maxElet;
    int eletricidade;

public:
    Bateria(string nom = "bat", int n = 1, int max = 100, int e = 0) : Edificio(nom, n), maxElet(max), eletricidade(e){}
    void armazenar();

};

class Fundicao : public Edificio {
    int aco;
public:
    Fundicao(string nom = "fun", int n = 1, int a = 0) : Edificio(nom, n), aco(a)  {}
    void produzir();
};

#endif //UNTITLED_EDIFICIO_H
