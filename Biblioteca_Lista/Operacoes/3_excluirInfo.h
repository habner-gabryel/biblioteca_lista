#ifndef EXCLUIR_INFO_H
#define EXCLUIR_INFO_H

int excluirInfo(pDLista pd, void* info){
    return efetuarExclusao(pd, info, NULL);
}

int excluirInfo1(pDLista pd, void* info, FuncaoLiberacao funcaoLiberacao){
    return efetuarExclusao(pd, info, funcaoLiberacao);
}

int efetuarExclusao(pDLista pd, void* info, FuncaoLiberacao funcaoLiberacao){
    
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
            if(funcaoLiberacao != NULL) {
                funcaoLiberacao(atual->info);
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
