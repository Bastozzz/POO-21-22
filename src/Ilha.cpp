#include "../inc/Ilha.h"
#include "../inc/Edificio.h"
#include "../inc/Trabalhador.h"

int Ilha::getriqueza() {
    return riqueza;
};

void Ilha::setriqueza(double dinhinicial) {
    riqueza = dinhinicial;
};

int Ilha::getDia() {
    return dia;
};

void Ilha::setDia(double d) {
    dia = d;
};

string Ilha::getAsString() const {
    ostringstream oss;
    Edificio e;
    Trabalhador t;
    oss << "Dados da Ilha: " << endl << "Numero de Edificios: " << e.getQuantidade() << endl
        << "Numero de Trabalhadores: " << t.getQuantidade() << endl;
    return oss.str();
}

