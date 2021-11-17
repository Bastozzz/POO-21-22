#include "../inc/Edificio.h"
#include "../inc/Ilha.h"

string Edificio::getNome() {
    return nome;
}

void Edificio::setNivel(int n) {
    nivel = n;
};

int Edificio::getNivel() const {
    return nivel;
};

/*
 *
 *
 *
 */

int MinaFerro::construir(int x, int y) {
    nome = "mnF";
};

string MinaFerro::getAsString() const {
    ostringstream oss;
    oss << "Quantidade de Minas de Ferro: " <<  nivel << endl;
    return oss.str();
};
