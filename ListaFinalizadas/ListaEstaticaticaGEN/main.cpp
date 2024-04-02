#include <iostream>
using namespace std;
#include "refazendoListaEstatica.h"
#include "poker.h"

int main()
{
    TLista <TipoCarta, 52> listaEst;
    inicializaLista(listaEst);
    montaBaralho(listaEst);
    //imprimeBaralho(listaEst);
    //cout<<endl;
    //cout<<"Embaralhado"<<endl;
    embaralha(listaEst);
    //imprimeBaralho(listaEst);
    cout<<endl;
    cout<<"Ordenando"<<endl;
    int tamanhoBaralho = retornaTamanho(listaEst);
    quicksort(listaEst, 0, tamanhoBaralho-1);
    imprimeBaralho(listaEst);


}
