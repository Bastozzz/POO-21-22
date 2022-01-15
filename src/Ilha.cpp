#include "../inc/Ilha.h"

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
}

void Ilha::mostraIlha(){
    int n = 1, i, j;
    for(i = 0; i < lZonas; i++)
        cout << "_____";
    cout << endl;
    for(i = 0; i < lZonas; i++){
        cout << "|";
        for(j = 0; j < cZonas; j++){
            retornaZona(n);
            cout << "|";
            n++;
        }

        n -= cZonas;
        cout << endl << "|";

        for(j = 0; j < cZonas; j++){
            retornaEdificio(n);
            cout << "|";
            n++;
        }

        n -= cZonas;
        cout << endl << "|";

        for(j = 0; j < cZonas; j++){
            retornaTrabalhadores(n);
            cout << "|";
            n++;
        }

        n -= cZonas;
        cout << endl << "|";

        for(j = 0; j < cZonas; j++){
            cout << Zonas[j + (cZonas * i)].getNTrab() << "   ";
            cout << "|";
            n++;
        }

        cout << endl;
        for(i = 0; i < lZonas; i++)
            cout << "_____";
        cout << endl;
    }

    cout << endl;

    retornaRecursos();
}

void Ilha::retornaZona(int p) {
    int times = 0;
    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        times++;
        if(times == p)
            cout << i->getTipo() << " ";
    }
}

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
}

void Ilha::retornaTrabalhadores(int p) {
    int times = 0;
    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        times++;
        if(times == p){
            i->getTrab();
        }
    }
}

void Ilha::construir(string edifi, int l, int c){
    int posicao = ((l-1) * cZonas) + c;
    int times = 0;
    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        times++;
        if(times == posicao){
            i->construirEdificio(edifi);
            setRiqueza(getRiqueza()-10);        // todos os edificios custam 10 €
        }
    }
}

void Ilha::contratar(string nome) {
    if(nome == "miner"){
        if(getRiqueza() >= 10){
            Mineiro t;
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
            cout << "Mineiro Contratado -> ID: " << t.getID() << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Nao tem dinheiro suficiente para contratar o mineiro" << endl;
    }
    else if(nome == "len"){
        if(getRiqueza() >= 10){
            Lenhador l;
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
            cout << "Lenhador Contratado -> ID: " << l.getID() << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Nao tem dinheiro suficiente para contratar o lenhador" << endl;
    }
    else if(nome == "oper"){
        if(getRiqueza() >= 10){
            Operario o;
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
            cout << "Operario Contratado -> ID: " << o.getID() << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Nao tem dinheiro suficiente para contratar o operario" << endl;
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
}

void Ilha::comprarEdificio(string edifi, int valor){
    if(getRiqueza() >= valor){
        int posicao = randTP(lZonas * cZonas);
        int times = 0;
        for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
            times++;
            if(times == posicao){
                i->construirEdificio(edifi);
                setRiqueza(getRiqueza() - valor);
            }
        }
        cout << "Novo balanco: " << getRiqueza() << endl;
    }
    else
        cout << "Nao tem dinheiro suficiente para comprar edificio" << endl;
}

void Ilha::comprarTrabalhador(string nome, int valor) {
    if(nome == "miner"){
        if(getRiqueza() >= valor){
            Mineiro t;
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
            setRiqueza(getRiqueza()-valor);
            cout << "Mineiro Contratado -> ID: " << t.getID() << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Nao tem dinheiro suficiente para comprar o mineiro" << endl;
    }
    else if(nome == "len"){
        if(getRiqueza() >= valor){
            Lenhador l;
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
            setRiqueza(getRiqueza()-valor);
            cout << "Lenhador Contratado -> ID: " << l.getID() << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Nao tem dinheiro suficiente para comprar o lenhador" << endl;
    }
    else if(nome == "oper"){
        if(getRiqueza() >= valor){
            Operario o;
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
            setRiqueza(getRiqueza()-valor);
            cout << "Operario Contratado -> ID: " << o.getID() << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Nao tem dinheiro suficiente para comprar o operario" << endl;
    }
}

void Ilha::venderRecursos(string nome, int quant) {
    if(nome == "ferro") {
        if(getFerro() >= quant) {
            setFerro(getFerro()-quant);
            setRiqueza(getRiqueza()+(1*quant));
            cout << "Ferro vendido" << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Quantidade insuficiente de ferro para vender" << endl;
    }
    else if(nome == "aco") {
        if(getBarraAco() >= quant) {
            setBarraAco(getBarraAco()-quant);
            setRiqueza(getRiqueza()+(2*quant));
            cout << "Barra de aco vendida" << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Quantidade insuficiente de barras de aco para vender" << endl;
    }
    else if(nome == "carvao") {
        if(getCarvao() >= quant) {
            setCarvao(getCarvao()-quant);
            setRiqueza(getRiqueza()+(1*quant));
            cout << "Carvao vendido" << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Quantidade insuficiente de carvao para vender" << endl;
    }
    else if(nome == "mad") {
        if(getMadeira() >= quant) {
            setMadeira(getMadeira()-quant);
            setRiqueza(getRiqueza()+(1*quant));
            cout << "Madeira vendida" << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Quantidade insuficiente de madeira para vender" << endl;
    }
    else if(nome == "viga") {
        if(getVigasMadeira() >= quant) {
            setVigasMadeira(getVigasMadeira()-quant);
            setRiqueza(getRiqueza()+(2*quant));
            cout << "Viga de madeira vendida" << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Quantidade insuficiente de vigas de madeira para vender" << endl;
    }
    else if(nome == "eletr") {
        if(getEletricidade() >= quant) {
            setEletricidade(getEletricidade()-quant);
            setRiqueza(getRiqueza()+(1.5*quant));
            cout << "Eletricidade vendida" << endl;
            cout << "Novo balanco: " << getRiqueza() << endl;
        }
        else
            cout << "Quantidade insuficiente de eletricidade para vender" << endl;
    }
}

void Ilha::venderEdificio(string edifi, int l, int c) {         // TODO: Vender edificio
    int posicao = randTP(lZonas * cZonas);
    int times = 0;
    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        times++;
        if(times == posicao){
            i->retirarEdificio(edifi, posicao);
            setRiqueza(getRiqueza() - 10);
        }
    }
    cout << "Novo balanco: " << getRiqueza() << endl;
}

void Ilha::adicionaValor(int valor) {
    setRiqueza(getRiqueza()+valor);
    cout << "Valor adicionado" << endl;
    cout << "Novo balanco: " << getRiqueza() << endl;
}

void Ilha::adicionaEdificio(string edifi, int l, int c){
    int posicao = ((l-1) * cZonas) + c;
    int times = 0;
    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        times++;
        if(times == posicao){
            i->construirEdificio(edifi);
        }
    }
}

void Ilha::removeTrabalhador(string id) {       // TODO: verificar se está a remover pelo id certo
    int times = 0;
    for (auto i = Zonas.begin(); i != Zonas.end(); ++i){
        //cout << "Zona: " << times << endl;
        for(int j = 0; j < i->getNTrab(); j++){
            if(id == i->getTrabId(j)){
                i->retirarTrabalhador(j);
            }
        }
        times++;
    }
}

int Ilha::getCount(){
    return tmpCount;
}

int Ilha::getDia() {
    return dia;
}

void Ilha::setDia(int d) {
    dia = d;
}

//Recursos
double Ilha::getRiqueza(){
    return riqueza;
}

void Ilha::setRiqueza(double quant) {
    riqueza = quant;
}

double Ilha::getFerro(){
    return ferro;
}

void Ilha::setFerro(double quant) {
    ferro = quant;
}

double Ilha::getBarraAco(){
    return barraAco;
}

void Ilha::setBarraAco(double quant) {
    barraAco = quant;
}

double Ilha::getCarvao(){
    return carvao;
}

void Ilha::setCarvao(double quant){
    carvao = quant;
}

double Ilha::getMadeira(){
    return madeira;
}

void Ilha::setMadeira(double quant){
    madeira = quant;
}

double Ilha::getVigasMadeira() {
    return vigasMadeira;
}

void Ilha::setVigasMadeira(double quant) {
    vigasMadeira = quant;
}

double Ilha::getEletricidade(){
    return eletricidade;
}

void Ilha::setEletricidade(double quant){
    eletricidade = quant;
}

void Ilha::retornaRecursos(){
    cout << "------------------------//--------------------------" << endl;
    cout << "Riqueza: " << getRiqueza() << endl;
    cout << "Ferro -> " << getFerro();
    cout << " | Barras de Aco -> " << getBarraAco();
    cout << " | Carvao -> " << getFerro() << endl;
    cout << "Madeira -> " << getMadeira();
    cout << " | Vigas de Madeira -> " << getVigasMadeira();
    cout << " | Eletricidade -> " << getEletricidade() << endl;
    cout << "------------------------//--------------------------" << endl << endl;
}

string Ilha::getAsString() const {
    ostringstream oss;
    Edificio e;
    Trabalhador t;
    return oss.str();
}

