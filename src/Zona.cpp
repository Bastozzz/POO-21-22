#include "../inc/Zona.h"
#include "../inc/Ilha.h"

string Zona::getTipo(){
    return tipo;
};

void Zona::construirEdificio(string nome){
    if(nome == "mnF"){
        MinaFerro mf;
        edif = mf;
    }
};

string Zona::getEdif() {
    return edif.getNome();
};