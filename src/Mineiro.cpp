#include "../inc/Mineiro.h"

int Mineiro::Contratar() {
    return ++quantidade;
}

void Mineiro::Desistir(int dias) {
    if(dias >= 2) {
        setProbabilidade(0.10);
        setQuantidade(-1);
    }
}

string Mineiro::getAsString() const {
    ostringstream oss;
    oss << "Quantidade de Mineiro: " <<  quantidade << endl;
    return oss.str();
}