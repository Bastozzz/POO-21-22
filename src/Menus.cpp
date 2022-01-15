#include "../inc/Menus.h"

void Menus::execFile(string &nomefich, Ilha * i) {
    string texto;
    ifstream ficheiro("../" + nomefich);

    string comando, tipo, id, nome;
    int linha, coluna, quanto, valor;

    Edificio e;
    Trabalhador t;

    while (ficheiro) {
        getline(ficheiro, texto);
        istringstream iss;
        iss.str(texto);
        iss >> comando;

        if (comando == "cons") {       // constroi edificio
            if (iss >> tipo && iss >> linha && iss >> coluna) {
                if (tipo == "minaf" && linha > 0 && coluna > 0) {
                    i->construir("mnF", linha, coluna);
                    cout << "Mina Ferro Construida" << endl;
                    cout << endl;
                }
                else if (tipo == "minac" && linha > 0 && coluna > 0) {
                    i->construir("mnC", linha, coluna);
                    cout << "Mina de Carvao Construida" << endl;
                    cout << endl;
                }
                else if (tipo == "central" && linha > 0 && coluna > 0) {
                    i->construir("cEl", linha, coluna);
                    cout << "Central Eletrica Construida" << endl;
                    cout << endl;
                }
                else if (tipo == "bat" && linha > 0 && coluna > 0) {
                    i->construir("bat", linha, coluna);
                    cout << "Bateria Construida" << endl;
                    cout << endl;
                }
                else if (tipo == "fund" && linha > 0 && coluna > 0) {
                    i->construir("fun", linha, coluna);
                    cout << "Fundicao Construida" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "liga") {           // Liga o edifício
            if (iss >> linha && iss >> coluna) {
                if (linha > 0 && coluna) {
                    e.liga();
                    cout << "Edificio Ligado" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "des") {            // Desliga o edifício
            if (iss >> linha && iss >> coluna) {
                if (linha > 0 && coluna > 0) {
                    e.desliga();
                    cout << "Edificio Desligado" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "move") {           // Move trabalhador
            if (iss >> id && iss >> linha && iss >> coluna) {
                if (id == t.getID() && linha > 0 && coluna > 0) {                 // TODO id
                    i->moveTrabalhador(id, linha, coluna);
                    cout << "Trabalhador movido" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "vende") {          // Vende recursos
            if (iss >> tipo && iss >> quanto) {
                if (tipo == "ferro" && quanto > 0) {
                    cout << "\nComando indisponível\n" << endl;
                    cout << endl;
                }
                else if (tipo == "aco" && quanto > 0) {
                    cout << "\nComando indisponível\n" << endl;
                    cout << endl;
                }
                else if (tipo == "carvao" && quanto > 0) {
                    cout << "\nComando indisponível\n" << endl;
                    cout << endl;
                }
                else if (tipo == "mad" && quanto > 0) {
                    cout << "\nComando indisponível\n" << endl;
                    cout << endl;
                }
                else if (tipo == "viga" && quanto > 0) {
                    cout << "\nComando indisponível\n" << endl;
                    cout << endl;
                }
                else if (tipo == "eletr" && quanto > 0) {
                    cout << "\nComando indisponível\n" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "cont") {           // contrata trabalhador
            if (iss >> tipo) {
                if (tipo == "miner") {
                    i->contratar(tipo);
                    cout << "Mineiro Contratado" << endl;
                    cout << endl;
                }
                else if (tipo == "oper") {
                    i->contratar(tipo);
                    cout << "Operario Contratado" << endl;
                    cout << endl;
                }
                else if (tipo == "len") {
                    i->contratar(tipo);
                    cout << "Lenhador Contratado" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "list") {           // Ver dados da ilha
            i->mostraIlha();
        }
        else if (comando == "vende") {          // Vende edificios
            if (iss >> tipo && iss >> linha && iss >> coluna) {
                if (tipo == "minaf" && linha > 0 && coluna > 0) {
                    i->venderEdificio(tipo, linha, coluna);
                    cout << "Mina de Ferro Vendida" << endl;
                    cout << endl;
                }
                else if (tipo == "minac" && linha > 0 && coluna > 0) {
                    i->venderEdificio(tipo, linha, coluna);
                    cout << "Mina de Carvao Vendida" << endl;
                    cout << endl;
                }
                else if (tipo == "central" && linha > 0 && coluna > 0) {
                    i->venderEdificio(tipo, linha, coluna);
                    cout << "Central Eletrica Vendida" << endl;
                    cout << endl;
                }
                else if (tipo == "bat" && linha > 0 && coluna > 0) {
                    i->venderEdificio(tipo, linha, coluna);
                    cout << "Bateria Vendida" << endl;
                    cout << endl;
                }
                else if (tipo == "fund" && linha > 0 && coluna > 0) {
                    i->venderEdificio(tipo, linha, coluna);
                    cout << "Fundicao Vendida" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "next") {           // Termina a fase de recolha de comandos
            cout << "\nComando indisponível\n" << endl;
            cout << endl;
        }
        else if (comando == "save") {           // Grava o estado do jogo em memória
            if (iss >> nome) {
                if (nome == "") {               // TODO nome
                    cout << "\nComando indisponível\n" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "load") {           // Recupera um dado estado do jogo em memória
            if (iss >> nome) {
                if (nome == "") {               // TODO nome
                    cout << "\nComando indisponível\n" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "apaga") {          // Apaga um determinado savegame de memória
            if (iss >> nome) {
                if (nome == "") {               // TODO nome
                    cout << "\nComando indisponível\n" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "debcash") {      // Adicina a quantidade de €
            if (iss >> valor) {
                if (valor > 0) {
                    i->adicionaValor(valor);
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "debed") {        // Adiciona um edifício a custo zero
            if (iss >> tipo && iss >> linha && iss >> coluna) {
                if (tipo == "minaf" && linha > 0 && coluna > 0) {
                    i->adicionaEdificio("mnF", linha, coluna);
                    cout << "Mina de Ferro adicionado" << endl;
                    cout << endl;
                }
                else if (tipo == "minac" && linha > 0 && coluna > 0) {
                    i->adicionaEdificio("mnC", linha, coluna);
                    cout << "Mina de Carvao Construida" << endl;
                    cout << endl;
                }
                else if (tipo == "central" && linha > 0 && coluna > 0) {
                    i->adicionaEdificio("cEl", linha, coluna);
                    cout << "Central Eletrica Construida" << endl;
                    cout << endl;
                }
                else if (tipo == "bat" && linha > 0 && coluna > 0) {
                    i->adicionaEdificio("bat", linha, coluna);
                    cout << "Bateria Construida" << endl;
                    cout << endl;
                }
                else if (tipo == "fund" && linha > 0 && coluna > 0) {
                    i->adicionaEdificio("fun", linha, coluna);
                    cout << "Fundicao Construida" << endl;
                    cout << endl;
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else if (comando == "debkill") {      // Remove o trabalhador
            if (iss >> id) {
                if (id == t.getID()) {                 // TODO id
                    i->removeTrabalhador(id);
                }
                else
                    cout << "\nComando invalido!!\n";
            }
        }
        else {
            cout << "\nComando Invalido!!\n" << endl;
        }
    }
}

void Menus::configFile(string nomefich, Ilha * i) {
    string texto;
    ifstream ficheiro("../" + nomefich);

    string comando;
    int valor;

    while (ficheiro) {
        getline(ficheiro, texto);
        istringstream iss;
        iss.str(texto);
        iss >> comando;

        if (comando == "minaf") {
            if (iss >> valor) {
                if (valor > 0) {
                    cout << "Mina Ferro Comprada" << endl;
                    i->comprarEdificio(comando, valor);
                    cout << endl;
                } else
                    cout << "\nComando invalido!!\n";
            }
        } else if (comando == "minac") {
            if (iss >> valor) {
                if (valor > 0) {
                    cout << "Mina Carvao Comprada" << endl;
                    i->comprarEdificio(comando, valor);
                    cout << endl;
                } else
                    cout << "\nComando invalido!!\n";
            }
        }else if (comando == "central") {
            if (iss >> valor) {
                if (valor > 0) {
                    cout << "Central Eletrica Comprada" << endl;
                    i->comprarEdificio(comando, valor);
                    cout << endl;
                } else
                    cout << "\nComando invalido!!\n";
            }
        } else if (comando == "bat") {
            if (iss >> valor) {
                if (valor > 0) {
                    cout << "Bateria Comprada" << endl;
                    i->comprarEdificio(comando, valor);
                    cout << endl;
                } else
                    cout << "\nComando invalido!!\n";
            }
        } else if (comando == "fund") {
            if (iss >> valor) {
                if (valor > 0) {
                    cout << "Fundicao Comprada" << endl;
                    i->comprarEdificio(comando, valor);
                    cout << endl;
                } else
                    cout << "\nComando invalido!!\n";
            }
        } else if (comando == "oper") {
            if (iss >> valor) {
                if (valor > 0) {
                    i->comprarTrabalhador(comando, valor);
                } else
                    cout << "\nComando invalido!!\n";
            }
        } else if (comando == "len") {
            if (iss >> valor) {
                if (valor > 0) {
                    i->comprarTrabalhador(comando, valor);
                } else
                    cout << "\nComando invalido!!\n";
            }
        } else if (comando == "miner") {
            if (iss >> valor) {
                if (valor > 0) {
                    i->comprarTrabalhador(comando, valor);
                } else
                    cout << "\nComando invalido!!\n";
            }
        }
        else
            cout << "\nComando invalido!!\n";
    }
}

int Menus::menu() {

    string comando, nomefich, tipo, id, nome;
    int linha, coluna, quanto, valor;
    ostringstream oss;
    //Validação de inicio para o tamanho da ilha
    cout << "Quantas linhas vai ter a ilha? (de 3 a 8)\n";
    while(linha < 3 || linha > 8){
        cin >> linha;
        if(linha < 3 || linha > 8)
            cout << "Numero invalido de linhas.\n";
    }

    cout << "Quantas colunas vai ter a ilha? (de 3 a 16)\n";
    while(coluna < 3 || coluna > 16){
        cin >> coluna;
        if(coluna < 3 || coluna > 16)
            cout << "Numero invalido de colunas.\n";
    }

    Ilha i (30,  linha, coluna, 1);
    i.criaIlha();
    i.mostraIlha();
    Edificio e;
    Trabalhador t;

    do {
        cout << "Introduza um comando: \n";
        getline(cin, comando);
        istringstream iss(comando);
        if (iss >> comando) {
            if (comando == "exec") {
                if (iss >> nomefich)
                    execFile(nomefich, &i);
                else
                    cout << "\nComando invalido!!\n";
            }
            else if (comando == "cons") {       // constroi edificio
                if (iss >> tipo && iss >> linha && iss >> coluna) {
                    if (tipo == "minaf" && linha > 0 && coluna > 0) {
                        i.construir("mnF", linha, coluna);
                        cout << "Mina Ferro Construida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "minac" && linha > 0 && coluna > 0) {
                        i.construir("mnC", linha, coluna);
                        cout << "Mina de Carvao Construida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "central" && linha > 0 && coluna > 0) {
                        i.construir("cEl", linha, coluna);
                        cout << "Central Eletrica Construida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "bat" && linha > 0 && coluna > 0) {
                        i.construir("bat", linha, coluna);
                        cout << "Bateria Construida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "fund" && linha > 0 && coluna > 0) {
                        i.construir("fun", linha, coluna);
                        cout << "Fundicao Construida" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "liga") {           // Liga o edifício
                if (iss >> linha && iss >> coluna) {
                    if (linha > 0 && coluna) {
                        e.liga();
                        cout << "Edificio Ligado" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "des") {            // Desliga o edifício
                if (iss >> linha && iss >> coluna) {
                    if (linha > 0 && coluna > 0) {
                        e.desliga();
                        cout << "Edificio Desligado" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "move") {           // Move trabalhador
                if (iss >> id && iss >> linha && iss >> coluna) {
                    if (id == t.getID() && linha > 0 && coluna > 0) {                 // TODO id
                        i.moveTrabalhador(id, linha, coluna);
                        cout << "Trabalhador movido" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "vende") {          // Vende recursos
                if (iss >> tipo && iss >> quanto) {
                    if (tipo == "ferro" && quanto > 0) {
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else if (tipo == "aco" && quanto > 0) {
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else if (tipo == "carvao" && quanto > 0) {
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else if (tipo == "mad" && quanto > 0) {
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else if (tipo == "viga" && quanto > 0) {
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else if (tipo == "eletr" && quanto > 0) {
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "cont") {           // contrata trabalhador
                if (iss >> tipo) {
                    if (tipo == "miner") {
                        i.contratar(tipo);
                        cout << "Mineiro Contratado" << endl;
                        cout << endl;
                    }
                    else if (tipo == "oper") {
                        i.contratar(tipo);
                        cout << "Operario Contratado" << endl;
                        cout << endl;
                    }
                    else if (tipo == "len") {
                        i.contratar(tipo);
                        cout << "Lenhador Contratado" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "list") {           // Ver dados da ilha
                i.mostraIlha();
            }
            else if (comando == "vende") {          // Vende edificios
                if (iss >> tipo && iss >> linha && iss >> coluna) {
                    if (tipo == "minaf" && linha > 0 && coluna > 0) {
                        i.venderEdificio(tipo, linha, coluna);
                        cout << "Mina de Ferro Vendida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "minac" && linha > 0 && coluna > 0) {
                        i.venderEdificio(tipo, linha, coluna);
                        cout << "Mina de Carvao Vendida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "central" && linha > 0 && coluna > 0) {
                        i.venderEdificio(tipo, linha, coluna);
                        cout << "Central Eletrica Vendida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "bat" && linha > 0 && coluna > 0) {
                        i.venderEdificio(tipo, linha, coluna);
                        cout << "Bateria Vendida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "fund" && linha > 0 && coluna > 0) {
                        i.venderEdificio(tipo, linha, coluna);
                        cout << "Fundicao Vendida" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "next") {           // Termina a fase de recolha de comandos
                cout << "\nComando indisponível\n" << endl;
                cout << endl;
            }
            else if (comando == "save") {           // Grava o estado do jogo em memória
                if (iss >> nome) {
                    if (nome == "") {               // TODO nome
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "load") {           // Recupera um dado estado do jogo em memória
                if (iss >> nome) {
                    if (nome == "") {               // TODO nome
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "apaga") {          // Apaga um determinado savegame de memória
                if (iss >> nome) {
                    if (nome == "") {               // TODO nome
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "config") {        // Lê o ficheiro de texto e extrai informações
                if (iss >> nomefich) {
                    configFile(nomefich, &i);
                }
                else
                    cout << "\nComando invalido!!\n";
            }
            else if (comando == "debcash") {      // Adicina a quantidade de €
                if (iss >> valor) {
                    if (valor > 0) {
                        i.adicionaValor(valor);
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "debed") {        // Adiciona um edifício a custo zero
                if (iss >> tipo && iss >> linha && iss >> coluna) {
                    if (tipo == "minaf" && linha > 0 && coluna > 0) {
                        i.adicionaEdificio("mnF", linha, coluna);
                        cout << "Mina de Ferro adicionado" << endl;
                        cout << endl;
                    }
                    else if (tipo == "minac" && linha > 0 && coluna > 0) {
                        i.adicionaEdificio("mnC", linha, coluna);
                        cout << "Mina de Carvao Construida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "central" && linha > 0 && coluna > 0) {
                        i.adicionaEdificio("cEl", linha, coluna);
                        cout << "Central Eletrica Construida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "bat" && linha > 0 && coluna > 0) {
                        i.adicionaEdificio("bat", linha, coluna);
                        cout << "Bateria Construida" << endl;
                        cout << endl;
                    }
                    else if (tipo == "fund" && linha > 0 && coluna > 0) {
                        i.adicionaEdificio("fun", linha, coluna);
                        cout << "Fundicao Construida" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "debkill") {      // Remove o trabalhador
                if (iss >> id) {
                                     // TODO: id
                        i.removeTrabalhador(id);

                }
            }
            else if (comando == "sair") {
                return 0;
            }
            else {
                cout << "\nComando Invalido!!\n" << endl;
            }
        }
    } while (comando != "sair");
}

