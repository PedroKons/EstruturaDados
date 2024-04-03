#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

struct TipoCarta {
    int naipe;
    int valor;
};

void imprimeCarta(const TipoCarta &carta) {
    string simbolo;
    switch (carta.naipe)
    {
    case 0:
        simbolo = "COPAS";
        break;
    case 2:
        simbolo = "ESPADAS";
        break;
    case 4:
        simbolo = "OURO";
        break;
    case 6:
        simbolo = "PAUS";
        break;
    }

    cout << carta.valor << " de " << simbolo << endl << endl;
}

void montaBaralho(Tlista<TipoCarta>& lista) {
    TipoCarta carta;
    for(int i = 0; i < 7; i+=2){
        for(int j = 1; j < 14; j++){
            carta.naipe = i;
            carta.valor = j;
            insereFim(lista, carta);
        }
    }
}

void imprimeBaralho(Tlista<TipoCarta>& lista){
    TElemento<TipoCarta>* nav = lista.inicio;
    while (nav!=NULL){
        imprimeCarta(nav->dado);
        nav = nav->proximo;
    }
}

void embaralhar(Tlista<TipoCarta> &lista, int tamanho) {

    if (tamanho < 2) return;

    for (int i = 0; i < tamanho * 2; i++) { 
        TElemento<TipoCarta> *nav1 = lista.inicio, *nav2 = lista.inicio;
        int aux_pos1 = rand() % tamanho;
        int aux_pos2 = rand() % tamanho;
        
        for (int j = 0; j < aux_pos1; j++) nav1 = nav1->proximo;
        for (int j = 0; j < aux_pos2; j++) nav2 = nav2->proximo;

        TipoCarta aux = nav1->dado;
        nav1->dado = nav2->dado;
        nav2->dado = aux;
    }
}

bool operator < (const TipoCarta& a, const TipoCarta& b){
    return a.naipe*10+a.valor < b.naipe*10+b.valor;
};
#endif // POKER_H_INCLUDED
