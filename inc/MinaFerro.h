#ifndef UNTITLED_MINAFERRO_H
#define UNTITLED_MINAFERRO_H

#include "utils.h"
#include "Edificio.h"

class MinaFerro : public Edificio {

public:
    MinaFerro(int q) : Edificio(q) {}

    int Construir();
    string getAsString() const;
};

#endif //UNTITLED_MINAFERRO_H
