#ifndef UNTITLED_ILHA_H
#define UNTITLED_ILHA_H

#include "utils.h"

class Ilha {
    int riqueza;
    int lzonas, czonas;
    int dia;

    //Em que [0] é o número de desertos, [1] é o de florestas, [2] é o de montanha, [3] é o de pantano, e o [4] é o de pastagens
    int nzonas[5];


public:
    Ilha() {}
    Ilha(int riq, int lzon, int czon, int nd, int nzon[5]) : riqueza(riq), lzonas(lzon), czonas(czon), dia(nd){}

    int getriqueza();
    void setriqueza(double dinhinicial);

    int getDia();
    void setDia(double d);

    string getAsString() const;

};

#endif //UNTITLED_ILHA_H
