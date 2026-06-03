#ifndef DESTRUIR_LISTA_H
#define DESTRUIR_LISTA_H

void destruirListaRecursiva(pNoh atual, FuncaoLiberacao funcaoLiberacao) {
    if (atual == NULL){
        return;
    }

    destruirListaRecursiva(atual->prox, funcaoLiberacao);
    if(funcaoLiberacao != NULL) {
        funcaoLiberacao(atual->info);
    }
    free(atual);
}

/* -------------------------------------*/
void destruirLista(pDLista pd){
    destruirListaRecursiva(pd->inicio, NULL);
    atualizarDescritor(pd);
}

void destruirListaInfo(pDLista pd, FuncaoLiberacao funcaoLiberacao){
    destruirListaRecursiva(pd->inicio, funcaoLiberacao);
    atualizarDescritor(pd);
}

void atualizarDescritor(pDLista pd){
    pd->quantidade = 0;
    pd->inicio     = NULL;
    pd->fim        = NULL;
}

#endif

