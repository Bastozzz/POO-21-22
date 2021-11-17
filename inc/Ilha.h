#ifndef UNTITLED_ILHA_H
#define UNTITLED_ILHA_H

#include "utils.h"
#include "Zona.h"

class Zona;

class Ilha {

    int             riqueza;
    int             lZonas;
    int             cZonas;
    int             dia;

    //Em que [0] é o número de desertos, [1] é o de florestas, [2] é o de montanha, [3] é o de pantano, e o [4] é o de pastagens
    int             nZonas[5];


public:
    Ilha() {}
    Ilha(int riq, int lzon, int czon, int nd) : riqueza(riq), lZonas(lzon), cZonas(czon), dia(nd){}

    vector<Zona>    Zonas;

    int getriqueza();
    void setriqueza(double dinhinicial);

    int getDia();
    void setDia(double d);

    void mostraIlha();
    void retornaZona(int i);

    void retornaEdificio(int i);

    void criaIlha();

    string getAsString() const;

    void construir(string edifi, int l, int c);


};

#endif //UNTITLED_ILHA_H
