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

void Trabalhador::setProbabilidade(int prob) {
    probabilidade = prob;
}

double Trabalhador::getProbabilidade() const {
    return probabilidade;
}


/*
 *
 *
 *
 */


string Mineiro::getAsString() const {
    ostringstream oss;
    return oss.str();
}

string Lenhador::getAsString() const {
    ostringstream oss;
    return oss.str();
}

string Operario::getAsString() const {
    ostringstream oss;
    return oss.str();
}



