#include "../inc/Trabalhador.h"

void Trabalhador::setID(int i, int dia) {
    ID += to_string(i) += ".";
    ID += to_string(dia);
};

string Trabalhador::getID() const {
    return ID;
};

void Trabalhador::setTipo(string t) {
    tipo = t;
};

string Trabalhador::getTipo() const {
    return tipo;
};


/*
 *
 *
 *
 */


string Mineiro::getAsString() const {
    ostringstream oss;
    return oss.str();
}


