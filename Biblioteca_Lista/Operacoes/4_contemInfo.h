#ifndef CONTEM_INFO_H
#define CONTEM_INFO_H


int contemInfo(pDLista pd, void* info, FuncaoComparacao pfc){

    int   cont = 1;
    pNoh  atual = pd->inicio;

    while(atual != NULL){

        if (pfc(info, atual->info) == 0)
            return cont;

        atual = atual->prox;
        cont++;
    }

    return 0;
}

#endif
