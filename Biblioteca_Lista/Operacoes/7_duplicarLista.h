#ifndef DUPLICAR_LISTA_H
#define DUPLICAR_LISTA_H

pDLista duplicarLista(pDLista pd, FuncaoAlocacao pfa)
{
    pDLista novaLista;

    novaLista = criarLista();

    pNoh atual;
    atual = pd->inicio;
    while(atual != NULL){

        void* copiaInfo = pfa(atual->info);

        incluirInfoFim(novaLista, copiaInfo);
        atual = atual->prox;
    }

    return novaLista;
}

#endif
