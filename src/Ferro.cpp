#include "../inc/Ferro.h"

void Ferro::Venda(bool sell){
    if(sell == true) {
        setPreco(1);
        setQuantidade(-1);
    }
}