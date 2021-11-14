#include "../inc/MinaFerro.h"

int MinaFerro::Construir(int x, int y) {
    Zona z(x, y);
    z.setPosX(x);
    z.setPosY(y);
    cout << "Posicao: (" << z.getPosX() << "," << z.getPosY() << ")" << endl;
    return ++quantidade;
};

string MinaFerro::getAsString() const {
    ostringstream oss;
    oss << "Quantidade de Minas de Ferro: " <<  quantidade << endl;
    return oss.str();
}

