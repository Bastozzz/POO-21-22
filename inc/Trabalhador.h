#ifndef UNTITLED_TRABALHADOR_H
#define UNTITLED_TRABALHADOR_H

#include "utils.h"

class Trabalhador {
protected:
    int quantidade;

private:
    string ID;
    int preco;
    double probabilidade;

public:
    Trabalhador(int quant = 0) : quantidade(quant) {}
    //Trabalhador(string id, int quant = 0, int price, double prob) : ID(id), quantidade(quant), preco(price), probabilidade(prob) {}

    void setID(string id, Trabalhador, int dia);
    string getID() const ;

    void setQuantidade(int q);
    int getQuantidade() const ;

    void setPreco(int price);
    int getPreco() const;

    void setProbabilidade(int prob);
    double getProbabilidade() const;

};


#endif //UNTITLED_TRABALHADOR_H
