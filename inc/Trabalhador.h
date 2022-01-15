#ifndef UNTITLED_TRABALHADOR_H
#define UNTITLED_TRABALHADOR_H

#include "utils.h"

//Classe principal
class Trabalhador {

protected:
    string      ID;
    string      tipo;
    int         preco;
    double      probabilidade = 0.0;


public:
    Trabalhador(){}
    Trabalhador(string id, int price = 0, double prob = 0.0) : ID(id), preco(price), probabilidade(prob) {}

    void        setID(int i, int dia);
    string      getID() const;

    void        setTipo(string t);
    string      getTipo() const;


    //Por implementar na meta 2
    void        setPreco(int price);
    int         getPreco() const;
    void        setProbabilidade(int prob);
    double      getProbabilidade() const;

};

/*
 *
 *
 */

//Subclasses

class Mineiro : public Trabalhador {

public:
    Mineiro(){}
    Mineiro(string id, double prob, int d, int price=15) : Trabalhador(id, price, prob) {}

    string getAsString() const;

};

class Lenhador : public Trabalhador {

public:
    Lenhador(){}
    Lenhador(string id, double prob, int d, int price=20) : Trabalhador(id, price, prob) {}

    string getAsString() const;

};

class Operario : public Trabalhador {

public:
    Operario(){}
    Operario(string id, double prob, int price=10) : Trabalhador(id, price, prob) {}

    string getAsString() const;

};


#endif //UNTITLED_TRABALHADOR_H
