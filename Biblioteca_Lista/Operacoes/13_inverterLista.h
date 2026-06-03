#ifndef INVERTER_LISTA_H
#define INVERTER_LISTA_H

void inverterLista (pDLista pdLista){
    pNoh anterior = NULL;
    pNoh atual = pdLista->inicio;
    pNoh proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox; // Armazena o próximo nó
        atual->prox = anterior; // Inverte o ponteiro do nó atual
        anterior = atual; // Move o ponteiro anterior para o nó atual
        atual = proximo; // Move para o próximo nó
    }

    // Após a inversão, o último nó se torna o primeiro
    pdLista->inicio = anterior;

}

pDLista inverterListaComNovaLista (pDLista pdLista, FuncaoAlocacao pfa){
    pDLista novaLista = duplicarLista(pdLista, pfa);

    inverterLista(novaLista);

    return novaLista;
}

#endif