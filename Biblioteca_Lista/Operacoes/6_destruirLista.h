#ifndef DESTRUIR_LISTA_H
#define DESTRUIR_LISTA_H

void destruirListaRecursiva(pNoh atual){

    if (atual == NULL)
        return;

    destruirListaRecursiva(atual->prox);
    free(atual);
}

/* -------------------------------------*/
void destruirLista(pDLista pd){

/*
    pNoh atual = pd->inicio;
    while(atual != NULL){

        pNoh aux = atual->prox;

        free(atual);

        atual = aux;
    }
*/
   destruirListaRecursiva(pd->inicio);


    // atualizar o descritor
    pd->quantidade = 0;
    pd->inicio     = NULL;
    pd->fim        = NULL;

}

#endif

