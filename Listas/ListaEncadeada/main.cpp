#include <iostream>
using namespace std;
#include "ListaEncadeadaGEN.h"

int main() {
    Tlista<int> lista_int;
    startList(lista_int);
    insertEnd(lista_int, 4);
    insertEnd(lista_int, 2);
    insertEnd(lista_int, 1);
    insertEnd(lista_int, 10);

    cout << "Lista antes da ordenação: ";
    printList(lista_int.inicio);

    TElemento<int>* end = lista_int.inicio;
    while (end->proximo != NULL) {
        end = end->proximo;
    }



    return 0;
}




