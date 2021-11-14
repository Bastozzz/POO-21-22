#ifndef UNTITLED_MINAFERRO_H
#define UNTITLED_MINAFERRO_H

#include "utils.h"
#include "Edificio.h"
#include "Zona.h"

class MinaFerro : public Edificio {

public:
    MinaFerro(int q) : Edificio(q) {}

    int Construir(int x, int y);

    string getAsString() const;
};

#endif //UNTITLED_MINAFERRO_H
