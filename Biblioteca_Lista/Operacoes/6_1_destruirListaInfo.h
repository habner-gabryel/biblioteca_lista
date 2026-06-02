#ifndef DESTRUIR_LISTA_INFO_H
#define DESTRUIR_LISTA_INFO_H

/* -------------------------------------*/
void destruirListaInfo (pDLista pd, FuncaoLiberacao pfl){

    pNoh atual = pd->inicio;
    while(atual != NULL){

        pNoh aux = atual->prox;
        //if(pfl!=NULL)
           pfl(atual->info);
        free(atual);
        atual = aux;
    }

    // atualizar o descritor
    pd->quantidade = 0;
    pd->inicio     = NULL;
    pd->fim        = NULL;

}

#endif

