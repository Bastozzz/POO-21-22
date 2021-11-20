#include "../inc/Edificio.h"
#include "../inc/Ilha.h"

string Edificio::getNome() {
    return nome;
}


/*
 *
 *
 *
 */

string MinaFerro::getAsString() const {
    ostringstream oss;
    oss << "Quantidade de Minas de Ferro: " <<  nivel << endl;
    return oss.str();
};
