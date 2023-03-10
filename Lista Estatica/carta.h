#include <iostream>
using namespace std;
#define TAM 52

struct carta
{
    int nipe;
    int valor;
};

struct listaE
{
  int tamanho;
  carta baralho [TAM];

};

void gerar(carta &jogo) {
    jogo.valor = rand() % 13 + 1;
    jogo.nipe = rand() % 4 + 1;
}

bool incializa_lista (listaE &poker) {
  poker.tamanho=0;

  if(poker.tamanho==0){
    return true;
  }
    return false;
  
}

void insere_inicio(carta jogo, listaE &poker){
  
  for (int i = poker.tamanho; i >= 0; i--) {
    poker.baralho[i + 1] = poker.baralho[i];
  }
  poker.baralho[0] = jogo;
  poker.tamanho++;

}

void insere_final(carta jogo, listaE &poker){
  poker.baralho[poker.tamanho]=jogo;
  poker.tamanho++;
}

void insere_posicao(carta jogo, listaE& poker) {
  int aux;
  cout << endl;
  cout << "Qual posicao deseja inserir" << endl;
  cin >> aux;

  for (int i = aux; i <= poker.tamanho; i++) {
    poker.baralho[aux + 1] = poker.baralho[aux];
  }
    poker.baralho[aux] = jogo;
    poker.tamanho++;
}

void remove_final(listaE &poker){
  poker.tamanho--;
}

void remove_inicio(listaE &poker) {

  for (int i = 0; i <= poker.tamanho; i++) {
    poker.baralho[i] = poker.baralho[i + 1];
  }
    poker.tamanho--;
}

void remove_posicao(listaE &poker) {
  int aux;
  cout << endl;
  cout << "Qual posicao deseja excluir " << endl;
  cin >> aux;

  for (int i = aux;i <= poker.tamanho;i++) {
    poker.baralho[aux] = poker.baralho[aux + 1];
  }
  poker.tamanho--;
}

void imprimir(listaE &poker){
  for(int i=0; i<=poker.tamanho ; i++){
    switch (poker.baralho[i].nipe)
    {  
      case 1:
      cout<<endl<<"Carta -> Numero: "<<poker.baralho[i].valor<<" Copas ";
      break;

      case 2:
      cout<<endl<<"Carta -> Numero: "<<poker.baralho[i].valor<<" Espadas ";
      break;

      case 3:
      cout<<endl<<"Carta -> Numero: "<<poker.baralho[i].valor<<" Ouro ";
      break;
    
      case 4:
      cout<<endl<<"Carta -> Numero: "<<poker.baralho[i].valor<<" Paus ";
      break;

    }
  }
}
