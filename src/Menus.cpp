#include "../inc/Menus.h"
#include "../inc/MinaFerro.h"
#include "../inc/Mineiro.h"
#include "../inc/Ilha.h"
// TODO ILha

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
            if (iss >> nome && iss >> comando && iss >> tipo && iss >> linha && iss >> coluna) {
                if (comando == "cons" && tipo == "minaf" && linha > 0 && coluna > 0) {
                    mf.Construir();
                    cout << "Mina Ferro Construida" << endl;
                    cout << endl;
                }
                else if (comando == "cont" &&tipo == "miner") {
                    m.Contratar();
                    cout << "Mineiro Contratado" << endl;
                    cout << endl;
                }
                else
                    cout << "Erro na leitura do ficheiro";
            }
        }
        cout << "Carregado com sucesso!" << endl;
    }
}

int Menus::menu() {
    string comando;
    ostringstream oss;
    Ilha i;
    MinaFerro mf(0);
    Mineiro m(0);

    do
    {
        cout << "Introduza um comando: ";
        getline(cin, comando);
        istringstream iss(comando);
        if (iss >> comando)
        {
            if (comando == "cons")      // constroi edificio
            {
                string tipo;
                int linha, coluna;
                if (iss >> tipo) {
                    if (tipo == "minaf" /*&& linha > 0 && coluna > 0*/) {
                        mf.Construir();
                        cout << "Mina Ferro Construida" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!";
                }
            }
            else if (comando == "cont")     // contratar trabalhador
            {
                string tipo;
                int linha, coluna;
                if (iss >> tipo) {
                    if (tipo == "miner") {
                        m.Contratar();
                        cout << "Mineiro Contratado" << endl;
                        cout << endl;
                    }
                    else
                        cout << "\nComando invalido!!";
                }
            }
            else if (comando == "exec")
            {
                string nomefich;
                if (iss >> nomefich)
                    execFile(nomefich);
                else
                    cout << "\nComando invalido!!";
            }
            else if (comando == "list")
            {
                cout << "\n-----A mostrar lista:-----" << endl;
                //cout << i.getAsString();
                cout << mf.getAsString();
                cout << m.getAsString();
                cout << endl;
            }
            else if (comando == "sair")
            {
                return 0;
            }
            else
            {
                cout << "\nComando Invalido!!" << endl;
                return 0;
            }
        }
    } while (comando != "sair");

    return 0;
};

