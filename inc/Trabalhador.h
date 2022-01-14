#ifndef UNTITLED_TRABALHADOR_H
#define UNTITLED_TRABALHADOR_H

#include "utils.h"

//Classe principal
class Trabalhador {

protected:
    string      ID;
    string      tipo;
    double      probabilidade = 0.0;


public:
    Trabalhador(){}
    Trabalhador(string id, double prob = 0.0) : ID(id), probabilidade(prob) {}

    void        setID(int i, int dia);
    string      getID() const;

    void        setTipo(string t);
    string      getTipo() const;

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
    Mineiro(string id, double prob, int d) : Trabalhador(id, prob) {}

    string getAsString() const;

};

class Lenhador : public Trabalhador {

public:
    Lenhador(){}
    Lenhador(string id, double prob, int d) : Trabalhador(id, prob) {}

    string getAsString() const;

};

class Operario : public Trabalhador {

public:
    Operario(){}
    Operario(string id, double prob) : Trabalhador(id, prob) {}

    string getAsString() const;

};


#endif //UNTITLED_TRABALHADOR_H
