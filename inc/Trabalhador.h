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

    string getAsString() const;

};

class Lenhador : public Trabalhador {

public:
    Lenhador(){}

    string getAsString() const;

};

class Operario : public Trabalhador {

public:
    Operario(){}

    string getAsString() const;

};


#endif //UNTITLED_TRABALHADOR_H
