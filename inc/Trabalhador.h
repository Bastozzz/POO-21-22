#ifndef UNTITLED_TRABALHADOR_H
#define UNTITLED_TRABALHADOR_H

#include "utils.h"

//Classe principal
class Trabalhador {

protected:
    string ID;
    string tipo;
    int preco;
    double probabilidade;


public:
    Trabalhador(){}
    Trabalhador(string id, int price = 0, double prob = 0.0) : ID(id), preco(price), probabilidade(prob) {}

    void setID(int i, int dia);
    string getID() const;

    void setTipo(string t);
    string getTipo() const;

    void setPreco(int price);
    int getPreco() const;

    void setProbabilidade(int prob);
    double getProbabilidade() const;

};

/*
 *
 *
 */

//Sublacsse de mineiro
class Mineiro : public Trabalhador {

public:
    Mineiro(){}
    Mineiro(string id, int price, double prob) : Trabalhador(id, price, prob) {}

    string getAsString() const;

};


#endif //UNTITLED_TRABALHADOR_H
