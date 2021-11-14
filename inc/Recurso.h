#ifndef UNTITLED_RECURSO_H
#define UNTITLED_RECURSO_H

#include "utils.h"

class Recurso {
    double quantidade;
    int preco;
public:
    Recurso(double q, int p) : quantidade(q), preco(p) {};

    double getQuantidade();
    void setQuantidade(double q);

    int getPreco();
    void setPreco(int p);
};


#endif //UNTITLED_RECURSO_H
