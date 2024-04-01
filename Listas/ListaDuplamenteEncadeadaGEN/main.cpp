#include <iostream>
using namespace std;
#include "DuplamenteEncadeadaGEN.h"

int main()
{
    TLista<int> listaD_int;
    startList(listaD_int);
    insertEnd(listaD_int, 5);
    insertEnd(listaD_int, 4);
    insertEnd(listaD_int, 2);
    insertEnd(listaD_int, 7);
    insertEnd(listaD_int, 1);
    insertEnd(listaD_int, 9);
    insertEnd(listaD_int, 6);
    insertEnd(listaD_int, 0);

    TElemento<int>* lastElement = listaD_int.inicio;
    while (lastElement->proximo != NULL) {
        lastElement = lastElement->proximo;
    }

    quickSort(listaD_int.inicio, lastElement);

    TElemento<int> *current = listaD_int.inicio;
    while (current != NULL) {
        cout << current->dado << " ";
        current = current->proximo;
    }
    cout << endl;
    return 0;
}
