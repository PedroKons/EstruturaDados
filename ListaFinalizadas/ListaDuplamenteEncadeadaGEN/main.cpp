#include <iostream>
#include "duplamenteEncadeada.h"
#include "poker.h"
using namespace std;

int main()
{
    TLista<TipoCarta> listaD_int;
    inicializaLista(listaD_int);
    montaBaralho(listaD_int);

    TElemento<TipoCarta>* nav = listaD_int.inicio;
    int t = 0;
    while (nav!=NULL){
        t++;
        nav = nav->proximo;
    }
    embaralhar(listaD_int,t);
    imprimeBaralho(listaD_int);
    cout<<endl<<endl;
    quickSort(listaD_int.inicio, listaD_int.fim);
    imprimeBaralho(listaD_int);


    return 0;
}
