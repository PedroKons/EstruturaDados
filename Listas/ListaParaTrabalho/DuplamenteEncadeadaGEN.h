#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

template <typename TIPO>
struct TElemento{
TIPO dado;
TElemento<TIPO> * proximo;
TElemento<TIPO> * anterior;
};

template <typename TIPO>
struct TLista{
TElemento<TIPO> * inicio;
TElemento<TIPO> * fim;
};

template <typename TIPO>
bool inicializar(TLista<TIPO> &lista){
  lista.inicio = NULL;
  lista.fim = NULL;
  return true;
}

template <typename TIPO>
void imprimir(TLista<TIPO> lista){
  TElemento<TIPO> * nav = lista.inicio;
  while(nav != NULL){
    cout << nav->dado << endl;
    nav = nav->proximo;  
  }
}

template <typename TIPO>
bool insereFim(TLista<TIPO> & lista, TIPO dado){
  TElemento<TIPO> * novo_elemento = new TElemento<TIPO>;
  novo_elemento->dado = dado;
  novo_elemento->proximo = nullptr;

  if (lista.inicio == nullptr) {
    lista.inicio = novo_elemento;
    lista.fim = novo_elemento;
  } else {
    lista.fim->proximo = novo_elemento;
    lista.fim = novo_elemento;
  }

  return true;
}

template <typename TIPO>
bool insereInicio(TLista<TIPO> & lista, TIPO dado){
  TElemento<TIPO> * novo_elemento = new TElemento<TIPO>;
  novo_elemento->dado = dado;
  novo_elemento->proximo = lista.inicio;
  lista.inicio = novo_elemento;

  if (lista.fim == nullptr) {
    lista.fim = novo_elemento;
  }

  return true;
}

template <typename TIPO>
bool inserePosicao(TLista<TIPO> &lista, TIPO dado, int posicao) {
  if (posicao < 0) {
    return false;
  }

  TElemento<TIPO> *novo_elemento = new TElemento<TIPO>;
  novo_elemento->dado = dado;
  novo_elemento->proximo = nullptr;

  if (posicao == 0) {
    novo_elemento->proximo = lista.inicio;
    lista.inicio = novo_elemento;
    if (lista.fim == nullptr) {
      lista.fim = novo_elemento;
    }
    return true;
  }

  TElemento<TIPO> *nav = lista.inicio;
  TElemento<TIPO> *anterior = nullptr;
  int cont = 0;

  while (nav != nullptr && cont < posicao) {
    anterior = nav;
    nav = nav->proximo;
    cont++;
  }

  if (nav == nullptr && cont < posicao) {
    // Position is out of bounds
    delete novo_elemento;
    return false;
  }

  novo_elemento->proximo = nav;
  if (anterior != nullptr) {
    anterior->proximo = novo_elemento;
  } else {
    lista.inicio = novo_elemento;
  }

  if (nav == lista.fim) {
    lista.fim = novo_elemento;
  }

  return true;
}



template <typename TIPO>
bool removeInicio(TLista<TIPO> & lista){
  if(lista.inicio == NULL){
    return false;
  } else {
    TElemento<TIPO> * apagar = lista.inicio;
    lista.inicio = apagar->proximo;
    delete apagar;
    if(lista.inicio == NULL){
      lista.fim = NULL;
    }  
    return true;
  }
}

template <typename TIPO>
bool removeFim(TLista<TIPO> & lista){
  if(lista.inicio == NULL){
    return false;
  } else {
    TElemento<TIPO> * nav = lista.inicio;
    TElemento<TIPO> * anterior = nullptr;

    while (nav->proximo != nullptr) {
        anterior = nav;
        nav = nav->proximo;
    }

    if (anterior != nullptr) {
        // Há pelo menos dois elementos na lista
        delete lista.fim;
        anterior->proximo = nullptr;
        lista.fim = anterior;
    } else {
        // Há apenas um elemento na lista
        delete lista.inicio;
        lista.inicio = nullptr;
        lista.fim = nullptr;
    }

    return true;
  }
}

template <typename TIPO>
bool removePosicao(TLista<TIPO> &lista, int posicao) {
    if (lista.inicio == nullptr || posicao < 0) {
        return false;
    }

    if (posicao == 0) {
        return removeInicio(lista);
    }

    TElemento<TIPO> *nav = lista.inicio;
    TElemento<TIPO> *anterior = nullptr;
    int cont = 0;

    while (nav != nullptr && cont < posicao) {
        anterior = nav;
        nav = nav->proximo;
        cont++;
    }

    if (nav == nullptr) {
        // Position is out of bounds
        return false;
    }

    anterior->proximo = nav->proximo;
    delete nav;

    if (anterior->proximo == nullptr) {
        // Removing the last element
        lista.fim = anterior;
    }

    return true;
}

