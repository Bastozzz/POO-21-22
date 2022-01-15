#include "../inc/Edificio.h"

string Edificio::getNome() {
    return nome;
}

void Edificio::setNome(string n) {
    nome = n;
}

string Edificio::getAsString() const {
    ostringstream oss;
    oss << "Quantidade de Minas de Ferro: " <<  nivel << endl;
    return oss.str();
}

void Edificio::setNivel(int n) {
    nivel = n;
}

int Edificio::getNivel() const {
    return nivel;
}

int Edificio::liga() {
    return ligaEdificio = true;
}

int Edificio::desliga() {
    return ligaEdificio = false;
}


/*
 *
 *
 *
 */


void MinaFerro::produzirF(){
    ferro += 2 + (nivel - 1);
    if(ferro > maxFerro + (nivel * 10) - 10)
        ferro = maxFerro + (nivel * 10) - 10;
};

void MinaCarvao::produzirC(){
    carvao += 2 + (nivel - 1);
    if(carvao > maxCarvao + (nivel * 10) - 10)
        carvao = maxCarvao + (nivel * 10) - 10;
};

void CentralEletrica::produzirRecursos(){
    carvao += 1;
    if(carvao > maxCarvao)
        carvao = maxCarvao;
}

void Bateria::armazenar() {
    eletricidade += 1;
    if(eletricidade > maxElet + (nivel * 10) - 10)
        eletricidade = maxElet + (nivel * 10) - 10;
}

void Fundicao::produzir() {
    aco += 1;
}