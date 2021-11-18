#include "../inc/Trabalhador.h"

void Trabalhador::setID(int i, int dia) {
    ID += to_string(i) += ".";
    ID += to_string(dia);
};

string Trabalhador::getID() const {
    return ID;
};

void Trabalhador::setQuantidade(int q) {
    quantidade = q;
};

int Trabalhador::getQuantidade() const {
    return quantidade;
};

void Trabalhador::setPreco(int price) {
    preco = price;
};

int Trabalhador::getPreco() const {
    return preco;
};

void Trabalhador::setProbabilidade(int prob) {
    probabilidade = prob;
};

double Trabalhador::getProbabilidade() const {
    return probabilidade;
};


/*
 *
 *
 *
 */

string Mineiro::getAsString() const {
    ostringstream oss;
    oss << "Quantidade de Mineiro: " <<  quantidade << endl;
    return oss.str();
}


