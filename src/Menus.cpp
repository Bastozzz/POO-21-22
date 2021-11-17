#include "../inc/Menus.h"
#include "../inc/MinaFerro.h"
#include "../inc/Zona.h"
#include "../inc/Ilha.h"
#include "../inc/Trabalhador.h"

void Menus::execFile(string nomefich) {
    MinaFerro mf(0);
    Mineiro m(0);
    ifstream ficheiro(nomefich);
    if (ficheiro) {
        string nome, tipo, comando;
        int linha, coluna;
        string str;
        while (getline(ficheiro, str)) {
            istringstream iss(str);
            if (iss >> comando) {
                if (comando == "cons") {     // constroi edificio
                    if (iss >> tipo && iss >> linha && iss >> coluna) {
                        if (tipo == "minaf") {
                            if (linha > 0 ) {
                                if (coluna > 0) {
                                    mf.Construir(linha, coluna);
                                    cout << "Mina Ferro Construida" << endl;
                                    cout << endl;
                                }
                                else
                                    cout << "\nComando invalido!!\n";
                            }
                            else
                                cout << "\nComando invalido!!\n";
                        }
                        else
                            cout << "\nComando invalido!!\n";
                    }
                }
                else if (comando == "cont")     // contrata trabalhador
                {
                    string tipo;
                    if (iss >> tipo) {
                        if (tipo == "miner") {
                            m.Contratar();
                            cout << "Mineiro Contratado" << endl;
                            cout << endl;
                        }
                        else
                            cout << "\nComando invalido!!\n";
                    }
                }
                else
                    cout << "Erro na leitura do ficheiro\n";
            }
        }
        cout << "Carregado com sucesso!\n" << endl;
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

    Mineiro("hey", 3, 3);
    Ilha i (30,  linha, coluna, 1);
    i.mostraIlha();
    i.criaIlha(i);

    MinaFerro mf(0);
    Mineiro m(0);
    //Zona z(linha, coluna);

    do {
        cout << "Introduza um comando: ";
        getline(cin, comando);
        istringstream iss(comando);
        if (iss >> comando) {
            if (comando == "exec") {
                if (iss >> nomefich)
                    execFile(nomefich);
                else
                    cout << "\nComando invalido!!\n";
            }
            else if (comando == "cons") {       // constroi edificio
                if (iss >> tipo && iss >> linha && iss >> coluna) {
                    if (tipo == "minaf") {
                        if (linha > 0 ) {
                            if (coluna > 0) {
                                mf.Construir(linha, coluna);
                                cout << "Mina Ferro Construida" << endl;
                                cout << endl;
                            }
                            else
                                cout << "\nComando invalido!!\n";
                        }
                        else
                            cout << "\nComando invalido!!\n";
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "liga") {           // Liga o edifício
                if (iss >> linha && iss >> coluna) {
                    if (linha > 0 ) {
                        if (coluna > 0) {
                            cout << "\nComando indisponível\n" << endl;
                            cout << endl;
                        }
                        else
                            cout << "\nComando invalido!!\n";
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "des") {            // Desliga o edifício
                if (iss >> linha && iss >> coluna) {
                    if (linha > 0 ) {
                        if (coluna > 0) {
                            cout << "\nComando indisponível\n" << endl;
                            cout << endl;
                        }
                        else
                            cout << "\nComando invalido!!\n";
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "move") {           // Move trabalhador
                if (iss >> id && iss >> linha && iss >> coluna) {
                    if (id == "") {                 // TODO id
                        if(linha > 0) {
                            if (coluna > 0) {
                                cout << "\nComando indisponível\n" << endl;
                                cout << endl;
                            }
                            else
                                cout << "\nComando invalido!!\n";
                        }
                        else
                            cout << "\nComando invalido!!\n";
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "vende") {          // Vende recursos
                if (iss >> tipo && iss >> quanto) {
                    if (tipo == "ferro") {
                        if (quanto > 0) {
                            cout << "\nComando indisponível\n" << endl;
                            cout << endl;
                        }
                        else
                            cout << "\nComando invalido!!\n";
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "cont") {           // contrata trabalhador
                string tipo;
                if (iss >> tipo) {
                    if (tipo == "miner") {
                        m.Contratar();
                        cout << "Mineiro Contratado" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "list") {           // Ver dados da ilha
                if (iss >> linha && iss >> coluna) {
                    if (linha > 0 ) {
                        if (coluna > 0) {
                            cout << "\n-----A mostrar lista:-----" << endl;
                            // TODO Mostrar as informações pela posição
                            cout << mf.getAsString();
                            cout << m.getAsString();
                            cout << endl;
                        }
                        else
                            cout << "\nComando invalido!!\n";
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "vende") {          // Vende edificios
                if (iss >> linha && iss >> coluna) {
                    if (linha > 0) {
                        if (coluna > 0) {
                            cout << "\nComando indisponível\n" << endl;
                            cout << endl;
                        }
                        else
                            cout << "\nComando invalido!!\n";
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
                    execFile(nomefich);
                    cout << endl;
                }
            }
            else if (comando == "debcash ") {      // Adicina a quantidade de €
                if (iss >> valor) {
                    if (valor > 0) {
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "debed") {        // Adiciona um edifício a custo zero
                if (iss >> tipo && iss >> linha && iss >> coluna) {
                    if (tipo == "minaf") {
                        if(linha > 0) {
                            if (coluna > 0) {
                                cout << "\nComando indisponível\n" << endl;
                                cout << endl;
                            }
                            else
                                cout << "\nComando invalido!!\n";
                        }
                        else
                            cout << "\nComando invalido!!\n";
                    }
                    else
                        cout << "\nComando invalido!!\n";
                }
            }
            else if (comando == "debkill") {      // Remove o trabalhador
                if (iss >> id) {
                    if (id == "") {                 // TODO id
                        cout << "\nComando indisponível\n" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!\n";
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

    return 0;
};

