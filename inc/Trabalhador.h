#ifndef UNTITLED_TRABALHADOR_H
#define UNTITLED_TRABALHADOR_H

#include "utils.h"

//Classe principal
class Trabalhador {
protected:
    int quantidade;

private:
    string ID;
    int preco;
    double probabilidade;

public:
    Trabalhador(int quant = 0) : quantidade(quant) {}
    Trabalhador(string id, int price = 0, double prob = 0.0) : ID(id), preco(price), probabilidade(prob) {}

    void setID(string id, int dia);
    string getID() const ;

    void setQuantidade(int q);
    int getQuantidade() const;

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
    Mineiro(int quant) : Trabalhador(quant) {}
    Mineiro(string id, int price, double prob) : Trabalhador(id, price, prob) {}

    int Contratar();
    void Desistir(int dias);

    string getAsString() const;

};


#endif //UNTITLED_TRABALHADOR_H
