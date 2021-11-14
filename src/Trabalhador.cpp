#include "../inc/Trabalhador.h"

void Trabalhador::setID(string id, Trabalhador, int dia) {
    int numero;
    id += to_string(numero) += ".";
    id += to_string(dia);
    numero++;
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


