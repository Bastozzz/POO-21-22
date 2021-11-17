#include "inc/utils.h"
#include "inc/Menus.h"

void inicio() {
    cout << "Pedro Bastos & Rafaela Santos\n";
    cout << "POO 2021/2022\n";

    string comando;
    Menus t;
    cout << "------------------------------------------------------------------------\n";
    cout << "-----------------------Configuracao da Ilha-----------------------------\n";
    cout << "------------------------------------------------------------------------\n";
    cout << "Constroi edificio               -> comando: cons <tipo> <linha> <coluna>\n";
    cout << "Contrata trabalhador            -> comando: cont <tipo>\n";
    cout << "Carregar ilha                   -> comando: exec <nomeFicheiro>\n";
    cout << "Ver dados da ilha               -> comando: list\n";
    cout << "Sair                            -> comando: sair\n";
    cout << "------------------------------------------------------------------------\n";
    t.menu();
}

int main() {
    inicio();

    return 0;
}
