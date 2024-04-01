#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "ListaEstaticaGEN.h"
#include "poker.h"

int main()
{
    TLista <TipoCarta, 52> baralho;
    TLista <TipoCarta, 52> jogador1;
    startList(baralho);
    startList(jogador1);
    montaBaralho(baralho);
    shuffleList(baralho);
    imprimeBaralho(baralho);
    distribuirCartas(baralho,jogador1,2);
    cout<<"Cartas jogador 1\n\n";
    imprimeBaralho(jogador1);
    cout<<"Baralho 1\n\n";
    imprimeBaralho(baralho);

    return 0;
}
