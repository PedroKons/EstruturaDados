#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

template <typename TIPO>
struct TElemento{
TIPO dado;
TElemento * proximo;
};

template <typename TIPO>
struct TLista{
TElemento<TIPO> * inicio;
};

template <typename TIPO>
bool inicializar(TLista<TIPO> & lista){
  lista.inicio = NULL;
  return true;
}

template <typename TIPO>
bool insereFim(TLista<TIPO> & lista, TIPO dado){
  TElemento<TIPO> * novo = new TElemento<TIPO>;
  novo->dado = dado;
  novo->proximo = NULL;
  if(lista.inicio == NULL){
    lista.inicio = novo;
  }else{
    TElemento<TIPO> * nav = lista.inicio;
    while(nav->proximo != NULL){
      nav = nav->proximo;
    }
    nav->proximo = novo;
    
  }
  return true;
}

template <typename TIPO>
bool insereInicio(TLista<TIPO> & lista, TIPO dado){
  TElemento<TIPO> * novo = new TElemento<TIPO>;
  novo->dado = dado;
  novo->proximo = lista.inicio;
lista.inicio = novo;
  return true;
  
}

template <typename TIPO>
bool inserePosicao(TLista<TIPO> & lista, TIPO dado, int posicao){
  TElemento<TIPO> * novo = new TElemento<TIPO>;
  novo->dado = dado;
  novo->proximo = NULL;
  if(lista.inicio == NULL){
    lista.inicio = novo;
    
  }else{
    TElemento<TIPO> * nav = lista.inicio;
    int cont = 0;
    while(nav->proximo != NULL && cont < posicao-1){
      nav = nav->proximo;
      cont++; 
    }
    novo->proximo = nav->proximo;
    nav->proximo = novo;
  }
  return true;
}

template <typename TIPO>
bool removeInicio(TLista<TIPO> & lista){
  if(lista.inicio == NULL){
    return false;
  }else{
    TElemento<TIPO> * apagar = lista.inicio;
    lista.inicio = apagar->proximo;
    delete apagar;
    return true;
  }
  
}

template <typename TIPO>
bool removeFim(TLista<TIPO> & lista){
  if(lista.inicio == NULL){
    return false;
  }else{
    TElemento<TIPO> * nav = lista.inicio;
    TElemento<TIPO> * apagar;
    while(nav->proximo != NULL){
      apagar = nav;
      nav = nav->proximo;
    }
    apagar->proximo = NULL;
    delete nav;
    return true;
  }
}

template <typename TIPO>
bool removePosicao(TLista<TIPO> & lista, int posicao){
  if(lista.inicio == NULL){
    return false;
  }else{
    TElemento<TIPO> * nav = lista.inicio;
    TElemento<TIPO> * apagar;
    int cont = 0;
    while(nav->proximo != NULL && cont < posicao-1){
      apagar = nav;
      nav = nav->proximo;
      cont++;
    }
    apagar->proximo = nav->proximo;
    delete nav;
    return true;
  }
}

template <typename TIPO>
int quantidade(TLista<TIPO> lista){
  int cont = 0;
  TElemento<TIPO> * nav = lista.inicio;
  while(nav != NULL){
    cont++;
    nav = nav->proximo;
  }
  return cont;
}

template <typename TIPO>
int buscaDado(TLista<TIPO> lista, int pos){
  int cont = 0;
  TElemento<TIPO> * nav = lista.inicio;
  while(nav != NULL && cont < pos){
    cont++;
    nav = nav->proximo; 
  }
  if(nav == NULL){
    return -1;
  }else{
    return nav->dado;
  }
}

template <typename TIPO>
void bubblesort(TLista <TIPO> &lista) {
  for (int i = 0; i < quantidade(lista) - 1; i++) {
    for (int j = 0; j < quantidade(lista) - i - 1; j++) {
      if (buscaDado(lista, j) > buscaDado(lista, j+1)) {
        // Swap nome[j] and nome[j + 1]
       TIPO temp = buscaDado(lista, j);
            TIPO aux1 = buscaDado(lista, j);
            TIPO aux2 = buscaDado(lista, j+1);
            aux1 = buscaDado(lista, j+1);
            aux2 = temp;

      }
    }
  }
}
template <typename TIPO>
void imprime(TLista<TIPO> lista){
  TElemento<TIPO> * nav = lista.inicio;
  while(nav != NULL){
    cout << nav->dado << endl;
    nav = nav->proximo;
  }
}
