#include "../inc/Ilha.h"
#include "../inc/Edificio.h"
#include "../inc/Trabalhador.h"
#include "../inc/utils.h"

void Ilha::criaIlha() {

    string verifica[lZonas][cZonas];
    for(int i = 0; i < lZonas; i++)
        for(int j = 0; j < cZonas; j++)
            verifica[i][j] = "0";

    int lin, col, temp = 0;
    vector<string> zon = {"mnt", "dsr", "pas", "flr", "pnt", "znZ"};


    for(int t = 0; t < (lZonas * cZonas); t++){
        while(1){
            lin = randTP(lZonas);
            col = randTP(cZonas);

            if(verifica[lin][col] == "0") {
                verifica[lin][col] = zon[temp];
                break;
            }
        }
        temp++;
        if(temp > 5) temp = 0;
    }

    for(int i = 0; i < lZonas; i++) {
        for (int j = 0; j < cZonas; j++){

            //Aqui vai ser em vez de só com o vetor, vai ser criada a classe em si
            Zona z(verifica[i][j], i, j);
            Zonas.push_back(z);
        }

    }
};

void Ilha::mostraIlha(){
    int n = 1;
    for(int i = 0; i < lZonas; i++)
        cout << "____";
    cout << endl;
    for(int i = 0; i < lZonas; i++){
        cout << "|";
        for(int j = 0; j < cZonas; j++){
            retornaZona(n);
            n++;
        }

        n -= cZonas;

        cout << "|" << endl << "|";

        for(int j = 0; j < cZonas; j++){
            retornaEdificio(n);
            n++;
        }
        cout << "|";
        cout << endl;
    }
    for(int i = 0; i < lZonas; i++)
        cout << "====";
    cout << endl << endl;
    cout << "Trabalhadores contratados:" << endl;
    for (auto i = Trabalhadores.begin(); i != Trabalhadores.end(); ++i){
            cout << i->getTipo() << " ";
    }
    cout << endl << endl;
};


void Ilha::retornaZona(int p) {
    int times = 0;
    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        times++;
        if(times == p)
            cout << i->getTipo() << " ";
    }
};


void Ilha::retornaEdificio(int p) {
    int times = 0;
    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        times++;
        if(times == p){
            if(i->getEdif() == ""){
                cout << "    ";
            }
            else{
                cout << i->getEdif() << " ";
            }
        }
    }
};


void Ilha::construir(string edifi, int l, int c){

    int posicao = ((l-1) * cZonas) + c;
    int times = 0;

    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        times++;
        if(times == posicao){
            i->construirEdificio(edifi);
        }
    }
};

void Ilha::contratar(string nome) {
    if(nome == "miner"){
        Trabalhador t;
        string temp;
        t.setID(tmpCount, getDia());
        t.setTipo(nome);
        Trabalhadores.push_back(t);

        tmpCount++;
    }

}

int Ilha::getCount(){
    return tmpCount;
}

int Ilha::getDia() {
    return dia;
};

string Ilha::getAsString() const {
    ostringstream oss;
    Edificio e;
    Trabalhador t;
    return oss.str();
};
