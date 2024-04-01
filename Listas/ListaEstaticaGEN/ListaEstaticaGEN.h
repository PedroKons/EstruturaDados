#ifndef LISTAESTATICAGEN_H_INCLUDED
#define LISTAESTATICAGEN_H_INCLUDED

template <typename TIPO>
struct TElemento {
    TIPO dado;
};

template <typename TIPO, int MAX>
struct TLista {
    TElemento <TIPO> elementos[MAX];
    int quantidade;
};

template <typename TIPO, int MAX>
void startList(TLista<TIPO, MAX>& l) {
    l.quantidade = 0;
}

template <typename TIPO, int MAX>
void insertEnd(TLista<TIPO, MAX>& l, TIPO dado) {
    TElemento <TIPO> e;
    e.dado = dado;
    l.elementos[l.quantidade] = e;
    l.quantidade++;
}

template<typename TIPO, int MAX>
void removeEnd(TLista<TIPO, MAX>& l) {
    l.quantidade--;
}

template<typename TIPO, int MAX>
int sizeList(TLista<TIPO, MAX>& l) {
    return l.quantidade;
}

template<typename TIPO, int MAX>
void removeFirt(TLista<TIPO, MAX>& l) {
    for (int i = 0;i < l.quantidade - 1;i++) {
        l.elementos[i] = l.elementos[i + 1];
    }
    l.quantidade--;
}

template<typename TIPO, int MAX>
void insertFirst(TLista<TIPO, MAX>& l, TIPO dado) {
    TElemento <TIPO> e;
    e.dado = dado;
    for(int i =l.quantidade;i>=0;i--){
        l.elementos[i] = l.elementos[i - 1];
    }
    l.elementos[0].dado = dado;
    l.quantidade++;
}

template<typename TIPO, int MAX>
void removePosition(TLista <TIPO, MAX>& l, int position) {
    for (int i = position; i < l.quantidade - 1;i++) {
        l.elementos[i] = l.elementos[i + i];
    }
    l.quantidade--;
}

template<typename TIPO, int MAX>
void insertFirst(TLista<TIPO, MAX>& l, TIPO dado, int position) {
    TElemento <TIPO> e;
    e.dado = dado;
    for (int i = l.quantidade;i >= position;i--) {
        l.elementos[i] = l.elementos[i - 1];
    }
    l.elementos[position] = dado;
    l.quantidade++;
}

template<typename TIPO, int MAX>
void bubblesort(TLista<TIPO, MAX>& l) {
    for(int i = 0; i < l.quantidade - 1; i++){
        for(int j =0; j < l.quantidade - i - 1; j++){
            if(l.elementos[j].dado < l.elementos[j+1].dado) {
                TIPO temp = l.elementos[j].dado;
                l.elementos[j].dado= l.elementos[j+1].dado;
                l.elementos[j+1].dado = temp;
            }
        }
    }
}


#endif // LISTAESTATICAGEN_H_INCLUDED
