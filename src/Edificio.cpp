#include "../inc/Edificio.h"
#include "../inc/Ilha.h"

string Edificio::getNome() {
    return nome;
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

void MinaFerro::produzir() {
    ferro += 2 + (getNivel() - 1);
    if(ferro > 100) ferro = 100;

}