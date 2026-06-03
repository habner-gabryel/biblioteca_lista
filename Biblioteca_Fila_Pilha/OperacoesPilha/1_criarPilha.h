#ifndef CRIAR_PILHA_H
#define CRIAR_PILHA_H

pDPilha criarPilha(){
    /* aloca memoria para o descritor */
    pDPilha pilha = malloc(sizeof(DPilha));

    /* o descritor da pilha tem os mesmos campos do descritor de lista */
    pilha->lista = criarLista();

    return pilha;
}

#endif
