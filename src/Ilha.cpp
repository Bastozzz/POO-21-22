#include "../inc/Ilha.h"
#include "../inc/Edificio.h"
#include "../inc/Trabalhador.h"
#include "../inc/utils.h"

void Ilha::criaIlha() {
    srand(time(NULL));

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
        cout << "_____";
    cout << endl;
    for(int i = 0; i < lZonas; i++){
        cout << "|";
        for(int j = 0; j < cZonas; j++){
            retornaZona(n);
            cout << "|";
            n++;
        }

        n -= cZonas;
        cout << endl << "|";

        for(int j = 0; j < cZonas; j++){
            retornaEdificio(n);
            cout << "|";
            n++;
        }

        n -= cZonas;
        cout << endl << "|";

        for(int j = 0; j < cZonas; j++){
            retornaTrabalhadores(n);
            cout << "|";
            n++;
        }

        n -= cZonas;
        cout << endl << "|";

        for(int j = 0; j < cZonas; j++){
            cout << Zonas[j + (cZonas * i)].getNTrab() << "   ";
            cout << "|";
            n++;
        }

        cout << endl;
        for(int i = 0; i < lZonas; i++)
            cout << "_____";
        cout << endl;
    }

    cout << endl;
    cout << "Dia numero " << getDia() << endl;
    retornaRecursos();
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

void Ilha::retornaTrabalhadores(int p) {
    int times = 0;
    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        times++;
        if(times == p){
            i->getTrab();
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
        if(getRiqueza() >= 10){
            Mineiro t;
            string temp;
            t.setID(tmpCount, getDia());
            t.setTipo(nome);

            //cout << "TMP: " << tmpCount << " | ID: " << t.getID() << endl;
            tmpCount++;

            while(1){
                int times = 0;
                int flag = 0;
                int temp = randTP(lZonas * cZonas);

                for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
                    times++;
                    if(i->getTipo() == "pas" && times == temp){
                        i->colocarTrabalhador("M", t);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            setRiqueza(getRiqueza()-10);
            cout << "Mineiro Contratado" << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else{
            cout << "Não tem dinheiro suficiente para contratar o mineiro" << endl;
        }

    }


    if(nome == "len"){
        if(getRiqueza() >= 10){
            Lenhador l;
            string temp;
            l.setID(tmpCount, getDia());
            l.setTipo(nome);

            //cout << "TMP: " << tmpCount << " | ID: " << t.getID() << endl;
            tmpCount++;

            while(1){
                int times = 0;
                int flag = 0;
                int temp = randTP(lZonas * cZonas);

                for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
                    times++;
                    if(i->getTipo() == "pas" && times == temp){
                        i->colocarTrabalhador("L", l);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            setRiqueza(getRiqueza()-20);
            cout << "Lenhador Contratado" << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else{
            cout << "Não tem dinheiro suficiente para contratar o lenhador" << endl;
        }

    }


    if(nome == "oper"){
        if(getRiqueza() >= 10){
            Operario o;
            string temp;
            o.setID(tmpCount, getDia());
            o.setTipo(nome);

            //cout << "TMP: " << tmpCount << " | ID: " << t.getID() << endl;
            tmpCount++;

            while(1){
                int times = 0;
                int flag = 0;
                int temp = randTP(lZonas * cZonas);

                for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
                    times++;
                    if(i->getTipo() == "pas" && times == temp){
                        i->colocarTrabalhador("O", o);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            setRiqueza(getRiqueza()-15);
            cout << "Operario Contratado" << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else{
            cout << "Não tem dinheiro suficiente para contratar o operario" << endl;
        }

    }


}

void Ilha::moveTrabalhador(string id, int lin, int col){
    int times = 0;
    int posicao = ((lin-1) * cZonas) + col-1;
    string temp;
    Trabalhador copia;

    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        //cout << "Zona: " << times << endl;
        for(int j = 0; j < i->getNTrab(); j++){
            if(id == i->getTrabId(j)){
                temp = i->getTrabName(j);
                copia = i->copyTrab(j);
                i->retirarTrabalhador(j);
                Zonas[posicao].colocarTrabalhador(temp, copia);
            }
        }
        times++;
    }
};

int Ilha::getDia() {
    return dia;
};

void Ilha::setDia(int d) {
    dia = d;
};

int Ilha::getCount(){
    return tmpCount;
}

//Recursos
int Ilha::getRiqueza(){
    return riqueza;
};
void Ilha::setRiqueza(double valor) {
    riqueza = valor;
}


int Ilha::getFerro(){
    return ferro;
};
void Ilha::setFerro(double valor) {
    ferro = valor;
}


int Ilha::getBarraAco(){
    return barraAco;
};
void Ilha::setBarraAco(double valor) {
    barraAco = valor;
}


int Ilha::getCarvao(){
    return carvao;
};
void Ilha::setCarvao(double valor){
    carvao = valor;
}


int Ilha::getMadeira(){
    return madeira;
};
void Ilha::setMadeira(double valor){
    madeira = valor;
}


int Ilha::getVigasMadeira() {
    return vigasMadeira;
};
void Ilha::setVigasMadeira(double valor) {
    vigasMadeira = valor;
}


int Ilha::getEletricidade(){
    return eletricidade;
};
void Ilha::setEletricidade(double valor){
    eletricidade = valor;
}


void Ilha::retornaRecursos(){
    cout << "------------------------//--------------------------" << endl;
    cout << "Riqueza: " << getRiqueza() << endl;
    cout << "Ferro -> " << getFerro();
    cout << " | Barras de Aco -> " << getBarraAco();
    cout << " | Carvao -> " << getCarvao() << endl;
    cout << "Madeira -> " << getMadeira();
    cout << " | Vigas de Madeira -> " << getVigasMadeira();
    cout << " | Eletricidade -> " << getEletricidade() << endl;
    cout << "------------------------//--------------------------" << endl << endl;
}

/*
 *
 */



void Ilha::nextTurn() {

}


string Ilha::getAsString() const {
    ostringstream oss;
    Edificio e;
    Trabalhador t;
    return oss.str();
}

