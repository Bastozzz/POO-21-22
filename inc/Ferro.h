#ifndef UNTITLED_FERRO_H
#define UNTITLED_FERRO_H

#include "utils.h"
#include "Recurso.h"


class Ferro : public Recurso {
public:
    Ferro(double q, int p) : Recurso(q, p) {};
    void Venda(bool sell);
};

#endif //UNTITLED_FERRO_H
