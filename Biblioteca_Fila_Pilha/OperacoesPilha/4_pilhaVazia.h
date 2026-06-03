#ifndef PILHAVAZIA_PILHA_H
#define PILHAVAZIA_PILHA_H

int pilhaVazia(pDPilha pilha){

    if(pilha->lista->quantidade != 0)
       return 0;

    return 1;
}

#endif
