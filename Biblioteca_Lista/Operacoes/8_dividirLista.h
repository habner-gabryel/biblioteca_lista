#ifndef DIVIDIR_LISTA_H
#define DIVIDIR_LISTA_H


pDLista dividirLista(pDLista pListaOriginal, int pos)
{

    pDLista pListaDividida = criarDLista();

    pNoh atual = pListaOriginal->inicio;
    pNoh aux = NULL;
    int cont = 0;

    while(atual != NULL && cont < pos){
        atual = atual->prox;
        cont++;
    }

    if(atual != NULL){
        aux = atual;
        aux->prox = NULL;
        pListaOriginal->fim         = aux;
        pListaOriginal->quantidade  = pos;

        pListaDividida->inicio      = atual->prox;
        pListaDividida->quantidade  = pListaOriginal->quantidade - pos;
        pListaDividida->fim         = pListaOriginal->fim;
    }

    return pListaDividida;
}

#endif
