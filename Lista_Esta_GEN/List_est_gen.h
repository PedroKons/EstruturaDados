#include <iostream>
#include <windows.h>
using namespace std;

template <typename TIPO>
struct TElemento 
{
    TIPO dado;
};

template <typename TIPO, int MAX>
struct ListaG
{
    TElemento <TIPO> elementos[MAX];
    int quantidade;
};

template <typename TIPO, int MAX>
void inicia_lista(ListaG<TIPO, MAX>& l) {
    l.quantidade = 0;
}

template <typename TIPO, int MAX>
bool insere_fim(ListaG<TIPO, MAX>& l, TIPO dado) {
    if (l.quantidade < MAX) {
        TElemento <TIPO> e;
        e.dado = dado;
        l.elementos[l.quantidade] = e;
        l.quantidade++;
        return true;
    }
    else {
        return false;
    }
}

template<typename TIPO, int MAX>
bool insere_ini(ListaG<TIPO, MAX>& l, TIPO dado) {
    if (l.quantidade < MAX) {
        for (int i = l.quantidade; i >= 0;i--) {
            l.elementos[i + 1] = l.elementos[i];
        }
        TElemento <TIPO> e;
        e.dado = dado;
        l.elementos[0] = e;
        l.quantidade++;
        return true;
    }
    else {
        return false;
    }
}

template<typename TIPO, int MAX>
bool insere_pos(ListaG<TIPO, MAX>& l, TIPO dado) {
    int aux;
    cout << endl;
    cout << "Qual posicao deseja inserir" << endl;
    cin >> aux;

    if (l.quantidade < MAX) {
        for (int i = aux;i <= l.quantidade;i++) {
            l.elementos[aux + 1] = l.elementos[aux];
        }
        TElemento <TIPO> e;
        e.dado = dado;
        l.elementos[aux] = e;
        l.quantidade++;
    }
    else {
        return false;
    }
}

template <typename TIPO, int MAX>
bool remove_fim(ListaG<TIPO, MAX>& l) {
    if (l.quantidade > 0) {
        l.quantidade--;
        return true;
    }
    else {
        return false;
    }
}

template <typename TIPO, int MAX>
bool remove_ini(ListaG<TIPO, MAX>& l) {
    if (l.quantidade > 0) {
        for (int i = 0; i <= l.quantidade;i++) {
            l.elementos[i] = l.elementos[i + 1];
        }
        l.quantidade--;
    }
    else {
        return false;
    }
}

template <typename TIPO, int MAX>
bool remove_pos(ListaG<TIPO, MAX>& l) {
    if (l.quantidade > 0) {
        int aux;
        cout << endl;
        cout << "Qual posicao deseja excluir " << endl;
        cin >> aux;

        for (int i = aux;i <= l.quantidade;i++) {
            l.elementos[aux] = l.elementos[aux + 1];
        }
        l.quantidade--;
    }
    else {
        return false;
    }
}












