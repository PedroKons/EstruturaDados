#include <iostream>
using namespace std;
#include "refazendoListaEncadeada.h"
#include "poker.h"

int main() {
    srand(time(NULL));
    Tlista<TipoCarta> lista_int;
    inicializaLista(lista_int);
    montaBaralho(lista_int);
    TElemento<TipoCarta>* nav = lista_int.inicio;
    int t = 0;
    while (nav!=NULL){
        t++;
        nav = nav->proximo;
    }
    embaralhar(lista_int,t);
    imprimeBaralho(lista_int);
    quicksortLista(lista_int);
    imprimeBaralho(lista_int);
    return 0;
}
