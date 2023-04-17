#include <iostream>
#include <string.h>
using namespace std;


template<typename TIPO>
struct TElementoP
{
    TIPO dado;
    TElementoP<TIPO>* proximo;
};

template<typename TIPO>
struct TPilha
{
    TElementoP<TIPO>* topo;
};

template<typename TIPO>
bool inicia_pilha(TPilha<TIPO>& pilha) {
    pilha.topo = NULL;
    return true;
}

template<typename TIPO>
TElementoP<TIPO>* novoElemento(TIPO dado) {
    TElementoP<TIPO>* novo = new TElementoP<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;
}

template<typename TIPO>
bool push(TPilha<TIPO>& pilha, TIPO dado) {
    TElementoP<TIPO>* novo = novoElemento(dado);
    novo->proximo = pilha.topo;
    pilha.topo = novo;
    return true;
}

template<typename TIPO>
TIPO pop(TPilha<TIPO>& pilha) {
    if (pilha.topo != NULL) {
        TElementoP<TIPO>* apagado = pilha.topo;
        pilha.topo = apagado->proximo;
        TIPO temp = apagado->dado;
        delete apagado;
        return temp;
    }
}

template<typename TIPO>
bool verif_eq(TPilha<TIPO>& pilha) {
    char eq[100];
    int cont = 0;

    cout << "Digite a expressao: ";
    cin >> eq;

    for (int i = 0; i < strlen(eq);i++) {
        if (eq[i] == '{' || eq[i] == '[' || eq[i] == '(') {

            push(pilha, eq[i]);
        }
        else if (eq[i] == '}' || eq[i] == ']' || eq[i] == ')') {

            char ver = pop(pilha);
            if ((eq[i] == '}' && ver != '{') || (eq[i] == ']' && ver != '[') || (eq[i] == ')' && ver == '(')) {
                cout << "Operacao incorreta ";
                return false;
            }

        }
        cont++;
        
    }
    cout << "Operacao correta " << "\t" << cont;
    return true;

    

   

    

}
