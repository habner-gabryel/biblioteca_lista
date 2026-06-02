#ifndef UNIR_LISTA_H
#define UNIR_LISTA_H


pDLista unirListas(pDLista lista1, pDLista lista2, FuncaoComparacao pfc)
{
    pDLista novaLista;
    novaLista = criarLista();

    pNoh atual;
    atual = lista1->inicio;
    while(atual != NULL){

         if (contemInfo(novaLista, atual->info, pfc) == 0)
            incluirInfoFim(novaLista, atual->info);

        atual = atual->prox;
    }

    atual = lista2->inicio;
    while(atual != NULL){

         if (contemInfo(novaLista, atual->info, pfc) == 0)
            incluirInfoFim(novaLista, atual->info);

        atual = atual->prox;
    }

    return novaLista;
}

#endif
