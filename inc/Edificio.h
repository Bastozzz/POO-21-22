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

};

class MinaCarvao : public Edificio {
    int maxCarvao;
    int carvao;

public:
    MinaCarvao(string nom = "mnC", int n = 1, int maxC = 100, int c = 0) : Edificio(nom, n),  maxCarvao(maxC), carvao(c){}

};

class CentralEletrica : public Edificio {
    int maxCarvao;
    int carvao;

    bool bateriaAdj;
    bool florestaAdj;
public:
    CentralEletrica(string nom = "cEl", int n = 1, int maxC = 100, int c = 0, int bAd = 0, int fAd = 0) : Edificio(nom, n), maxCarvao(maxC), carvao(c), bateriaAdj(bAd), florestaAdj(fAd){}

};

class Bateria : public Edificio {
    int maxElet;
    int eletricidade;

public:
    Bateria(string nom = "bat", int n = 1, int max = 100, int e = 0) : Edificio(nom, n), maxElet(max), eletricidade(e){}

};

class Fundicao : public Edificio {
    bool minaFerroAdj;
    bool minaCarvaoAdj;
    bool centralAdj;

public:
    Fundicao(string nom = "fun", int n = 1, int mFA = 0, int mCA = 0, int cA = 0) : Edificio(nom, n), minaFerroAdj(mFA), minaCarvaoAdj(mCA), centralAdj(cA)  {}

};

#endif //UNTITLED_EDIFICIO_H
