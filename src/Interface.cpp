#include "../inc/Interface.h"
#include "../inc/Menus.h"

void Interface::inicio() {
    cout << "Pedro Bastos & Rafaela Santos\n";
    cout << "POO 2021/2022\n";

    string comando;
    Menus t;
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "--------------------------------- Configuracao da Ilha --------------------------------\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "Carrega Ficheiro                               -> exec <nomeFicheiro>\n";
    cout << "Constroi edificio                              -> cons <tipo> <linha> <coluna>\n";
    cout << "Liga o edificio                                -> liga <linha> <coluna>\n";
    cout << "Desliga o edificio                             -> des <linha> <coluna>\n";
    cout << "Move o trabalhador                             -> move <id> <linha> <coluna>\n";
    cout << "Vende recursos                                 -> vende <tipo> <quanto>\n";
    cout << "Contrata trabalhador                           -> cont <tipo>\n";
    cout << "Ver dados da ilha                              -> list <linha> <coluna>\n";
    cout << "Vende o edificio                               -> vende <linha> <coluna>\n";
    cout << "Termina a fase de recolha de comandos          -> next\n";
    cout << "Grava o estado do jogo em memoria              -> save <nome>\n";
    cout << "Recupera um dado estado do jogo em memoria     -> load <nome>\n";
    cout << "Apaga um determinado savegame de memoria       -> apaga <nome>\n";
    cout << "Le o ficheiro de texto e extrai informacoes    -> config <ficheiro>\n";
    cout << "Adiciona a quantidade de dinheiro              -> debcash <valor>\n";
    cout << "Adiciona um edificio a custo zero              -> debed <tipo> <linha> <coluna>\n";
    cout << "Remove o trabalhador                           -> debkill <id>\n";
    cout << "Sair                                           -> sair\n";
    cout << "---------------------------------------------------------------------------------------\n";
    t.menu();
}
