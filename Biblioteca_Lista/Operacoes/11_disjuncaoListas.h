#ifndef DISJUNCAO_LISTA_H
#define DISJUNCAO_LISTA_H

int disjuncaoListas (pDLista lista1, pDLista lista2, FuncaoComparacao funcaoComparacao){
    pNoh atual1 = lista1->inicio;

    while (atual1 != NULL) {
        if (contemInfo(lista2, atual1->info, funcaoComparacao)) {
            return 0;
        }
        atual1 = atual1->prox;
    }
    return 1;
}

#endif