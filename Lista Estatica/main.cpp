#include <iostream>
#include <windows.h>
#include "carta.h"
#include <time.h>
using namespace std;


void menu_ca(carta jogo, listaE poker) {
    cout<<endl;
    cout<<"   Menu   ";
    cout<<endl;
    cout << "1- insere final " << endl;
    cout << "2- insere comeco " << endl;
    cout << "3- remove final " << endl;
    cout << "4- imprimi " << endl;
    cout << "5- remove inicio" << endl;
    cout << "6- remove posicao" << endl;
    cout << "7- insere posicao" << endl;
    
    int esc;
    cout<<"Qual sua opcao: ";
    cin>>esc;

    switch(esc)
      {
        case 1:
          gerar(jogo);
          system("cls");
          insere_final(jogo, poker);
          system("cls");
          menu_ca(jogo, poker);
          break;

        case 2:
          system("cls");
          gerar(jogo);
          insere_inicio(jogo, poker);
          system("cls");
          menu_ca(jogo,poker);
          break;

        case 3:
          system("cls");
          remove_final(poker);
          menu_ca(jogo, poker);
          break;

        case 4:
          system("cls");
          imprimir(poker);
          menu_ca(jogo,poker);
          break;

        case 5:
          system("cls");
          remove_inicio(poker);
          menu_ca(jogo, poker);
          break;

        case 6:
          system("cls");
          remove_posicao(poker);
          menu_ca(jogo, poker);
          break;

        case 7:
          gerar(jogo);
          system("cls");
          insere_posicao(jogo, poker);
          system("cls");
          menu_ca(jogo, poker);
          break;
          


      }
  }

int main() {
  srand(time(NULL));
  listaE poker;
  carta jogo;
  incializa_lista(poker);
  menu_ca(jogo,poker);
}
