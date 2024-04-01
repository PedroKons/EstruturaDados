#ifndef LISTAENCADEADAGEN_H_INCLUDED
#define LISTAENCADEADAGEN_H_INCLUDED

template<typename TIPO>
struct TElemento {
    TIPO dado;
    TElemento<TIPO> *proximo;
};

template<typename TIPO>
struct Tlista {
    TElemento<TIPO> *inicio;
};

template<typename TIPO>
bool startList(Tlista<TIPO> &l){
    l.inicio = NULL;
    return true;
}

template<typename TIPO>
void printList(TElemento<TIPO> *node) {
    while (node != NULL) {
        cout << node->dado << " ";
        node = node->proximo;
    }
    cout << endl;
}

template<typename TIPO>
TElemento<TIPO> *novoElemento(TIPO dado){
    TElemento<TIPO> *novo = new TElemento<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;
    return novo;
}

template<typename TIPO>
bool inserFirst(Tlista<TIPO> &l, TIPO dado){
    TElemento<TIPO> *novo = novoElemento(dado);
    novo->proximo = l.inicio;
    l.inicio = novo;
    return true;
}

template<typename TIPO>
bool insertEnd(Tlista<TIPO> &l, TIPO dado) {
    TElemento<TIPO> *nav = l.inicio;
    if(l.inicio != NULL) {
        while(nav->proximo != NULL) {
            nav = nav->proximo;
        }
        TElemento<TIPO> *novo = novoElemento(dado);
        novo->proximo = nav->proximo;
        nav->proximo = novo;
        return true;
    }else {
        TElemento<TIPO> *novo = novoElemento(dado);
        novo->proximo = l.inicio;
        l.inicio = novo;
        return true;
    }
}

template<typename TIPO>
bool insertPosition(Tlista<TIPO> &l, TIPO dado, int position){
    TElemento<TIPO> *nav = l.inicio;
    TElemento<TIPO> *novo = novoElemento(dado);
    if(l.inicio == NULL || position == 0) {
        novo->proximo = l.inicio;
        l.inicio = novo;
        return true;
    } else {
        for(int i = 0; i< position -1 && nav->proximo !=NULL;i++){
            nav = nav->proximo;
        }
        novo->proximo = nav->proximo;
        nav->proximo = novo;
        return true;
    }
}

template<typename TIPO>
bool removeEnd(Tlista<TIPO> &l){
    TElemento<TIPO> *nav = l.inicio;
    TElemento<TIPO> *aux = NULL;

    if(l.inicio == NULL) return false;

    while(nav->proximo != NULL){
        aux = nav;
        nav = nav->proximo;
    }
    delete nav;
    if(aux == NULL) {
        l.inicio = NULL;
    } else {
    aux->proximo = NULL;
    }
    return true;

}

template<typename TIPO>
bool removeFirst(Tlista<TIPO> &l){
    TElemento<TIPO> *nav = l.inicio;
    if(l.inicio == NULL) return false;
        l.inicio = nav->proximo;
        delete nav;
        return true;
}

template<typename TIPO>
bool removePosition(Tlista<TIPO>&l, int position){
    TElemento<TIPO> *nav = l.inicio;
    TElemento<TIPO> *aux = NULL;
    if(l.inicio == NULL) return false;
    for(int i = 0;  i<position && nav != NULL; i++) {
        aux = nav;
        nav = nav->proximo;
    }

    if(aux == NULL) {
        l.inicio = nav->proximo;
    }else{
     aux->proximo = nav->proximo;
    }

    delete nav;
    return true;
}

template<typename TIPO>
void bubblesort(Tlista<TIPO> &l) {
    if(l.inicio != NULL){
        TIPO temp;
        TElemento<TIPO> *nav = l.inicio;
        TElemento<TIPO> *aux = nav->proximo;
        while(aux != NULL){
            if(aux->dado < nav->dado) {
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






#endif // LISTAENCADEADAGEN_H_INCLUDED
