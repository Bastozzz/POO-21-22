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
    double      riqueza;
    double      ferro;
    double      barraAco;
    double      carvao;
    double      madeira;
    double      vigasMadeira;
    double      eletricidade;


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

    void        comprarEdificio(string edifi, int valor);
    void        comprarTrabalhador(string nome, int valor);

    void        venderRecursos(string nome, int quant);
    void        venderEdificio(string edifi, int l, int c);

    void        adicionaValor(int valor);
    void        adicionaEdificio(string edifi, int l, int c);
    void        removeTrabalhador(string id);

    int         getDia();
    void        setDia(int d);

    int         getCount();

    //Recursos
    double      getRiqueza();
    void        setRiqueza(double valor);

    double      getFerro();
    void        setFerro(double quant);

    double      getBarraAco();
    void        setBarraAco(double quant);

    double      getCarvao();
    void        setCarvao(double quant);

    double      getMadeira();
    void        setMadeira(double quant);

    double      getVigasMadeira();
    void        setVigasMadeira(double quant);

    double      getEletricidade();
    void        setEletricidade(double quant);

    void        retornaRecursos();
    string      getAsString() const;

};

#endif //UNTITLED_ILHA_H
