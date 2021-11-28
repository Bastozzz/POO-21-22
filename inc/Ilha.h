#ifndef UNTITLED_ILHA_H
#define UNTITLED_ILHA_H

#include "utils.h"
#include "Zona.h"

class Zona;
class Trabalhador;

class Ilha {

    int         lZonas;
    int         cZonas;
    int         dia;
    int         tmpCount;

    //Em que [0] é o número de desertos, [1] é o de florestas, [2] é o de montanha, [3] é o de pantano, e o [4] é o de pastagens
    int         nZonas[5];
    int         riqueza;

public:
    Ilha() {}
    Ilha(int riq, int lzon, int czon, int nd, int tmp = 1) : riqueza(riq), lZonas(lzon), cZonas(czon), dia(nd), tmpCount(tmp){}

    vector<Zona>             Zonas;

    void        criaIlha();
    void        mostraIlha();

    void        retornaZona(int p);
    void        retornaEdificio(int p);
    void        retornaTrabalhadores(int p);

    void        construir(string edifi, int l, int c);
    void        contratar(string nome);

    int         getNTrabalhadores();
    int         getDia();
    int         getCount();

    string      getAsString() const;


    //Por implementar na meta 2
    int         getriqueza();
    void        setriqueza(double dinhinicial);
    void        setDia(double d);

};

#endif //UNTITLED_ILHA_H
