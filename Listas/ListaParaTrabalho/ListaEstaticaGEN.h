#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

template <typename TIPO>
struct TElemento{
  TIPO dado;
};

template <typename TIPO, int MAX>
struct Lista{
  TElemento <TIPO> elementos[MAX];
  int tamanho;
};

template <typename TIPO, int MAX>
void inicializa_lista(Lista <TIPO, MAX> &lista){
  lista.tamanho = 0;
}

template <typename TIPO, int MAX>
bool insereFim(Lista <TIPO, MAX> &lista, TIPO dado){
  if(lista.tamanho == MAX){
    return false;
  }else{
    TElemento <TIPO> novo;
    novo.dado = dado;
    lista.elementos[lista.tamanho] = novo;
    lista.tamanho++;
    return true;
  }
}

template <typename TIPO, int MAX>
bool insereInicio(Lista <TIPO, MAX> &lista, TIPO dado){
  if(lista.tamanho == MAX){
    return false;
  }else{
    for(int i = lista.tamanho; i > 0; i--){
      lista.elementos[i] = lista.elementos[i-1];
    }
    TElemento <TIPO> novo;
    novo.dado = dado;
    lista.elementos[0] = novo;
    lista.tamanho++;
    return true;
  }
}

template <typename TIPO, int MAX>
bool inserePosicao(Lista <TIPO, MAX> &lista, TIPO dado, int pos){
  if(lista.tamanho == MAX){
    return false;
  }
  else if(pos < 0 || pos > lista.tamanho){
      return false;
    }else{
      for(int i = lista.tamanho; i > pos; i--){
        lista.elementos[i] = lista.elementos[i-1];
        
      }
    TElemento <TIPO> novo;
    novo.dado = dado;
    lista.elementos[pos] = novo;
      lista.tamanho++;
      return true;
    
    }
  }
  

template <typename TIPO, int MAX>
bool removeFim(Lista <TIPO, MAX> &lista){
  if(lista.tamanho == 0){
    return false;
  }else{
    lista.tamanho--;
  }
}

template <typename TIPO, int MAX>
bool removeInicio(Lista <TIPO, MAX> &lista){
  if(lista.tamanho == 0){
    return false;
  }else{
    for(int i = 0; i < lista.tamanho; i++){
      lista.elementos[i]= lista.elementos[i+1];
      
    }
    lista.tamanho--;
    return true;
    
  }
}

template <typename TIPO, int MAX>
bool removePosicao(Lista <TIPO, MAX> &lista, int pos){
  if(lista.tamanho == 0){
    return false;
  }else{
    for(int i = pos; i < lista.tamanho; i++){
      lista.elementos[i] = lista.elementos[i+1];
    }
    lista.tamanho--;
    return true;
    
  }
}
template <typename TIPO, int MAX>
int quantidade(Lista <TIPO, MAX> &lista){
  return lista.tamanho;
}

template <typename TIPO, int MAX>
void bubblesort(Lista <TIPO, MAX> &lista) {
  for (int i = 0; i < lista.tamanho - 1; i++) {
    for (int j = 0; j < lista.tamanho - i - 1; j++) {
      if (lista.elementos[j].dado > lista.elementos[j + 1].dado) {
        // Swap nome[j] and nome[j + 1]
       TIPO temp = lista.elementos[j].dado;
          lista.elementos[j].dado = lista.elementos[j+1].dado;
          lista.elementos[j+1].dado = temp;

      }
    }
  }
}
template <typename TIPO, int MAX, typename COMPARADOR>
int particionar(Lista <TIPO, MAX> &lista, int baixo, int alto, COMPARADOR comp) {
  TIPO pivo = lista.elementos[alto].dado;
  int i = baixo - 1;

  for (int j = baixo; j <= alto - 1; j++) {
    // Aqui estamos usando a função de comparação para comparar os elementos
    if (comp(lista.elementos[j].dado, pivo)) {
      i++;
      TIPO temp = lista.elementos[i].dado;
      lista.elementos[i].dado = lista.elementos[j].dado;
      lista.elementos[j].dado = temp;
    }
  }
  TIPO temp = lista.elementos[i + 1].dado;
  lista.elementos[i + 1].dado = lista.elementos[alto].dado;
  lista.elementos[alto].dado = temp;

  return (i + 1);
}

template<typename T>
bool compMenor(T a, T b) {
    return a < b;
}

template <typename TIPO, int MAX, typename COMPARADOR>
void quicksort(Lista <TIPO, MAX> &lista, int baixo, int alto, COMPARADOR comp) {
  if (baixo < alto) {
    int pi = particionar(lista, baixo, alto, comp);
    quicksort(lista, baixo, pi - 1, comp);
    quicksort(lista, pi + 1, alto, comp);
  }
}

template <typename TIPO, int MAX, typename COMPARADOR>
void quicksort(Lista <TIPO, MAX> &lista, COMPARADOR comp) {
  quicksort(lista, 0, lista.tamanho - 1, comp);
}

template <typename TIPO, int MAX>
void quicksort(Lista <TIPO, MAX> &lista) {
  quicksort(lista, compMenor<TIPO>);
}
