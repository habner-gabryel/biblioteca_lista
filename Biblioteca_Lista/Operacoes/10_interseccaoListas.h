#ifndef INTERSECCAO_LISTA_H
#define INTERSECCAO_LISTA_H


pDLista interseccaoListas(pDLista lista1, pDLista lista2, FuncaoComparacao pfc)
{
    pDLista novaLista;
    novaLista = criarLista();

    pNoh atual;
    atual = lista1->inicio;
    while(atual != NULL){

         if (contemInfo(lista2, atual->info, pfc) == 1)
            incluirInfoFim(novaLista, atual->info);

        atual = atual->prox;
    }

    return novaLista;
}

#endif