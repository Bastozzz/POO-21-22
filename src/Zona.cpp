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
    else if(nome == "mnC"){
        MinaCarvao mc;
        edif = mc;
    }
    else if(nome == "cEl"){
        CentralEletrica ce;
        edif = ce;
    }
    else if(nome == "bat"){
        Bateria b;
        edif = b;
    }
    else if(nome == "fun"){
        Fundicao f;
        edif = f;
    }
};

void Zona::colocarTrabalhador(string nome, Trabalhador t) {
    t.setTipo(nome);
    empreg.push_back(t);
};


string Zona::getEdif() {
    return edif.getNome();
}

string Zona::getTrab() {
    int times = 1;
    if(empreg.size() == 0){
        cout << "    ";
    }

    else {
        for (auto i = empreg.begin(); i != empreg.end(); ++i) {
            cout << i->getTipo();
            times++;
            if (times > 4) break;
        }
        for (int i = 4; times < 5; times++) {
            cout << " ";
        }
    }
}

int Zona::getNTrab() {
    return empreg.size();
}
