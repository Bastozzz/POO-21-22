#include "../inc/MinaFerro.h"

int MinaFerro::Construir() {
    return ++quantidade;
};

string MinaFerro::getAsString() const {
    ostringstream oss;
    oss << "Quantidade de Minas de Ferro: " <<  quantidade << endl;
    return oss.str();
}

