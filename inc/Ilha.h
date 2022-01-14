#ifndef UNTITLED_ILHA_H
#define UNTITLED_ILHA_H

#include "utils.h"
#include "Zona.h"

class Zona;
class Trabalhador;

class Ilha {

    int         lZonas;
    int         cZonas;
    int         dia;
    int         tmpCount;

    //Recursos
    int         riqueza;
    int         ferro;
    int         barraAco;
    int         carvao;
    int         madeira;
    int         vigasMadeira;
    int         eletricidade;


public:
    Ilha() {}
    Ilha(int riq, int lzon, int czon, int nd, int tmp = 1) : riqueza(riq), lZonas(lzon), cZonas(czon), dia(nd), tmpCount(tmp), ferro(0), barraAco(0), carvao(0), madeira(0), vigasMadeira(0), eletricidade(0) {}

    vector<Zona>             Zonas;

    void        criaIlha();
    void        mostraIlha();

    void        retornaZona(int p);
    void        retornaEdificio(int p);
    void        retornaTrabalhadores(int p);

    void        construir(string edifi, int l, int c);
    void        contratar(string nome);

    void        moveTrabalhador(string id, int lin, int col);

    int         getDia();
    void        setDia(int d);

    int         getCount();

    //Recursos
    int         getRiqueza();
    void        setRiqueza(double valor);

    int         getFerro();
    void        setFerro(double valor);

    int         getBarraAco();
    void        setBarraAco(double valor);

    int         getCarvao();
    void        setCarvao(double valor);

    int         getMadeira();
    void        setMadeira(double valor);

    int         getVigasMadeira();
    void        setVigasMadeira(double valor);

    int         getEletricidade();
    void        setEletricidade(double valor);

    void        retornaRecursos();
    string      getAsString() const;

    /*
     *
     */

    //Passar turnos
    void nextTurn();

};

#endif //UNTITLED_ILHA_H
