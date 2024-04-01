#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

struct TipoCarta {
    int naipe;
    int valor;
};

void print(const TipoCarta &carta) {
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

void montaBaralho(TLista <TipoCarta, 52>&lista) {
    TipoCarta carta;
    for(int i = 0; i < 7; i+=2){
        for(int j = 1; j < 14; j++){
            carta.naipe = i;
            carta.valor = j;
            insertEnd(lista, carta);
        }
    }

}

template <typename TIPO, int MAX>
void imprimeBaralho(TLista<TIPO, MAX> lista){
    for(int i = 0; i< lista.quantidade; i++){
        print(lista.elementos[i].dado);
    }
}

template<typename TIPO, int MAX>
void shuffleList(TLista<TIPO, MAX> &lista) {
    for(int i = 0; i< lista.quantidade;  i++){
        lista.elementos[i] = lista.elementos[rand()%lista.quantidade];
    }
}


void distribuirCartas(TLista<TipoCarta, 52> &origem, TLista<TipoCarta, 52> &chegada, int tamanho) {
    for(int i = 0;i<tamanho;i++){
        insertFirst(chegada, origem.elementos[0].dado);
        removeFirt(origem);
    }
}


bool operator < (TipoCarta a, TipoCarta b){
    return a.naipe*10+a.valor < b.naipe*10+b.valor;
};


#endif // POKER_H_INCLUDED
