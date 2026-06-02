#ifndef IMPRIMIR_LISTA_H
#define IMPRIMIR_LISTA_H

void imprimirLista(pDLista pd, FuncaoImpressao pfi){

    struct noh *atual;
    atual  =  pd->inicio;
    while (atual != NULL){

        pfi(atual->info);

        atual = atual->prox;
    }

}

#endif
