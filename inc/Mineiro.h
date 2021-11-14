#ifndef UNTITLED_MINEIRO_H
#define UNTITLED_MINEIRO_H

#include "utils.h"
#include "Trabalhador.h"

class Mineiro : public Trabalhador {

public:
    Mineiro(int quant) : Trabalhador(quant) {}
    Mineiro(string id, int price, double prob) : Trabalhador(id, price, prob) {}

    int Contratar();
    void Desistir(int dias);

    string getAsString() const;

};

#endif //UNTITLED_MINEIRO_H
