#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

#include <iostream> 
#include "refazendoListaEstatica.h" 

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

void montaBaralho(TLista<TipoCarta, 52>& lista) {
    TipoCarta carta;
    for(int i = 0; i < 7; i+=2){
        for(int j = 1; j < 14; j++){
            carta.naipe = i;
            carta.valor = j;
            insereFim(lista, carta); 
        }
    }
}

template <typename TIPO, int MAX>
void imprimeBaralho(TLista<TIPO, MAX> lista){
    for(int i = 0; i< lista.tamanho; i++){
        imprimeCarta(lista.elementos[i].dado);
    }
}

template<typename TIPO, int MAX>
void embaralha(TLista<TIPO, MAX> &lista) {
    for(int i = 0; i< lista.tamanho;  i++){
        lista.elementos[i] = lista.elementos[rand()%lista.tamanho];
    }
}

void distribuirCartas(TLista<TipoCarta, 52> &origem, TLista<TipoCarta, 52> &chegada, int tamanho) {
    for(int i = 0;i<tamanho;i++){
        insereInicio(chegada, origem.elementos[0].dado);
        removeInicio(origem);
    }
}

bool operator < (TipoCarta& a, TipoCarta& b){
    return a.naipe*10+a.valor < b.naipe*10+b.valor;
};

#endif // POKER_H_INCLUDED
