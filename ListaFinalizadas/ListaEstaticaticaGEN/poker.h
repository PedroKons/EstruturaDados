#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

#include <iostream> // Adicionando a biblioteca iostream para uso do cout
#include "refazendoListaEstatica.h" // Incluindo o arquivo com as definições das listas estáticas

struct TipoCarta {
    int naipe;
    int valor;
};

// Corrigindo a função imprimeCarta para receber TipoCarta como parâmetro
void imprimeCarta(const TipoCarta &carta) {
    std::string simbolo; // Alterando para std::string
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

    std::cout << carta.valor << " de " << simbolo << std::endl << std::endl;
}

// Corrigindo a função montaBaralho para usar corretamente a lista
void montaBaralho(TLista<TipoCarta, 52>& lista) {
    TipoCarta carta;
    for(int i = 0; i < 7; i+=2){
        for(int j = 1; j < 14; j++){
            carta.naipe = i;
            carta.valor = j;
            insereFim(lista, carta); // Usando a função insereFim da lista estática
        }
    }
}

// Corrigindo a função imprimeBaralho para usar corretamente a lista
template <typename TIPO, int MAX>
void imprimeBaralho(TLista<TIPO, MAX> lista){
    for(int i = 0; i< lista.tamanho; i++){
        imprimeCarta(lista.elementos[i].dado);
    }
}

// Corrigindo a função embaralha para usar corretamente a lista
template<typename TIPO, int MAX>
void embaralha(TLista<TIPO, MAX> &lista) {
    for(int i = 0; i< lista.tamanho;  i++){
        lista.elementos[i] = lista.elementos[rand()%lista.tamanho];
    }
}

// Corrigindo a função distribuirCartas para usar corretamente as listas
void distribuirCartas(TLista<TipoCarta, 52> &origem, TLista<TipoCarta, 52> &chegada, int tamanho) {
    for(int i = 0;i<tamanho;i++){
        insereInicio(chegada, origem.elementos[0].dado);
        removeInicio(origem);
    }
}

// Corrigindo a sobrecarga do operador <
bool operator < (TipoCarta& a, TipoCarta& b){
    return a.naipe*10+a.valor < b.naipe*10+b.valor;
};

#endif // POKER_H_INCLUDED
