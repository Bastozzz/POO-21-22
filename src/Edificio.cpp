#include "../inc/Edificio.h"

string Edificio::getNome() {
    return nome;
}

void Edificio::setNome(string n) {
    nome = n;
}

string Edificio::getAsString() const {
    ostringstream oss;
    oss << "Quantidade de Minas de Ferro: " <<  nivel << endl;
    return oss.str();
}

void Edificio::setNivel(int n) {
    nivel = n;
}

int Edificio::getNivel() const {
    return nivel;
}

int Edificio::liga() {
    return ligaEdificio = true;
}

int Edificio::desliga() {
    return ligaEdificio = false;
}


/*
 *
 *
 *
 */
