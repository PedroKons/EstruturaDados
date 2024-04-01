#ifndef DUPLAMENTEENCADEADAGEN_H_INCLUDED
#define DUPLAMENTEENCADEADAGEN_H_INCLUDED


template <typename TIPO>
struct TElemento {
    TIPO dado;
    TElemento <TIPO> * anterior;
    TElemento <TIPO> * proximo;
};

template<typename TIPO>
struct TLista {
    TElemento <TIPO> * inicio;
    TElemento <TIPO> * fim;
};

template<typename TIPO>
bool startList(TLista<TIPO> &l) {
    l.inicio = NULL;
    l.fim = NULL;
    return true;
}

template<typename TIPO>
TElemento<TIPO> *novoElemento(TIPO dado){
    TElemento<TIPO> *novo = new TElemento<TIPO>;
    novo->dado = dado;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

template<typename TIPO>
bool insertFirst(TLista<TIPO> &l, TIPO dado){
    TElemento<TIPO> *novo = novoElemento(dado);
    if(l.inicio != NULL) {
        TElemento<TIPO> *nav = l.inicio;
        l.inicio = novo;
        nav->anterior = novo;
        novo->proximo = nav;
        return true;
    }else {
        l.inicio = novo;
        l.fim  = novo;
        return true;
    }
}

template<typename TIPO>
bool insertEnd(TLista<TIPO> &l, TIPO dado) {
    TElemento<TIPO> *novo = novoElemento(dado);
    if(l.inicio != NULL){
        TElemento<TIPO> *nav = l.fim;
        l.fim = novo;
        nav->proximo = novo;
        novo->anterior = nav;
        return true;
    }else {
        l.inicio = novo;
        l.fim = novo;
        return true;
    }
}

template<typename TIPO>
bool insertPosition(TLista<TIPO> &l, TIPO dado, int position) {
    TElemento<TIPO> *novo = novoElemento(dado);
    TElemento<TIPO> *nav = l.inicio;
    if(position == 0 || l.inicio == NULL) {
        return insertFirst(l, dado);
    } else {
        for(int i=0; nav != NULL && i < position - 1; i++){
            nav = nav->proximo;
        }
    }
    novo->anterior = nav;
    novo->proximo = nav->proximo;
    if (nav->proximo)
        nav->proximo->anterior = novo;
    else
        l.fim = novo;
    nav->proximo = novo;
    return true;

}

template<typename TIPO>
bool removeFirst(TLista<TIPO> &l){
    TElemento<TIPO> *nav = l.inicio;
    if(l.inicio == NULL) {
        return false;
    }else {
        l.inicio = l.inicio->proximo;
    }
    if(l.inicio != NULL) {
        l.inicio->anterior = NULL;
    }else {
        l.fim = NULL;
    }

    delete nav;
    return true;
}

template<typename TIPO>
bool removeEnd(TLista<TIPO> &l) {
    TElemento<TIPO> *nav = l.fim;
    if(l.inicio == NULL) {
        return false;
    } else {
        l.fim = l.fim->anterior;
    }
    if(l.fim != NULL){
        l.fim->proximo = NULL;
    }else {
        l.inicio = NULL;
    }

    delete nav;
    return true;
}

template<typename TIPO>
bool removePosition(TLista<TIPO> &l, int position){
    TElemento<TIPO> *nav = l.inicio;
    if(l.inicio == NULL) return false;
    for(int i = 0;  i<position && nav != NULL; i++) {
        nav = nav->proximo;
    }
    if (nav->anterior)
        nav->anterior->proximo = nav->proximo;
    else
        l.inicio = nav->proximo; // Se atual é o primeiro elemento, atualiza o ponteiro de início

    if (nav->proximo)
        nav->proximo->anterior = nav->anterior;
    else
        l.fim = nav->anterior; // Se atual é o último elemento, atualiza o ponteiro de fim

    delete nav; // Libera a memória do elemento removido
    return true;
}

template<typename TIPO>
void bubblesort(TLista<TIPO> &l) {
    if(l.inicio != NULL) {
        TIPO temp;
        TElemento<TIPO> *nav = l.inicio;
        TElemento<TIPO> *aux = nav->proximo;
        while(aux != NULL){
            if(aux->dado < nav->dado){
                temp = aux->dado;
                aux->dado = nav->dado;
                nav->dado = temp;
                nav = l.inicio;
                aux = nav->proximo;
            }else {
                aux = aux->proximo;
                nav = nav->proximo;
            }
        }
    }
}

template<typename TIPO>
void swap(TElemento<TIPO>* a, TElemento<TIPO>* b) {
    TIPO temp = a->dado;
    a->dado = b->dado;
    b->dado =  temp;
}

template<typename TIPO>
TElemento<TIPO> *partition(TElemento<TIPO>* low, TElemento<TIPO>* high) {
    TIPO pivot = high->dado;
    TElemento<TIPO>* i = low->anterior;

    for (TElemento<TIPO>* j = low; j != high; j = j->proximo) {
        if (j->dado <= pivot) {
            if(i == NULL) {
                i = low;
            } else {
                i = i->proximo;
            }
            swap(i, j);
        }
    }

    if(i == NULL) {
        i = low;
    } else {
        i = i->proximo;
    }
    swap(i, high);
    return i;

}

template<typename TIPO>
void quickSort(TElemento<TIPO>* low, TElemento<TIPO>* high) {
    if (high != NULL && low != high && low != high->proximo) {
        TElemento<TIPO>* pivot = partition(low, high);
        quickSort(low, pivot->anterior);
        quickSort(pivot->proximo, high);
    }
}

#endif // DUPLAMENTEENCADEADAGEN_H_INCLUDED
