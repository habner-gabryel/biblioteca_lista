#ifndef EXCLUIR_INFO_H
#define EXCLUIR_INFO_H

int excluirInfo(pDLista pd, void* info){

    pNoh atual = pd->inicio;

    while(atual != NULL){
        if(atual->info == info){
            if(atual == pd->inicio){
                pd->inicio = atual->prox;
                if(pd->fim == atual){
                    pd->fim = NULL;
                }
            } else {
                pNoh aux = pd->inicio;
                while(aux->prox != atual){
                    aux = aux->prox;
                }
                aux->prox = atual->prox;
                if(pd->fim == atual){
                    pd->fim = aux;
                }
            }
            free(atual);
            pd->quantidade--;
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}

#endif
