#include "../inc/Zona.h"
#include "../inc/Ilha.h"

void Zona::setPosX(int pos) {
    posX = pos;
};

int Zona::getPosX() {
    return posX;
};

void Zona::setPosY(int pos) {
    posY = pos;
};

int Zona::getPosY() {
    return posY;
};

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