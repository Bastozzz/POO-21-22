#ifndef UNTITLED_EDIFICIO_H
#define UNTITLED_EDIFICIO_H

#include "utils.h"

class Edificio {
protected:
    int quantidade = 0;

public:
    Edificio(int q = 0) : quantidade(q) {}

    void setQuantidade(int q);
    int getQuantidade() const;

};



#endif //UNTITLED_EDIFICIO_H
